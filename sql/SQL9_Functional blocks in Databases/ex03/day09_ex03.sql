drop function if exists fnc_trg_person_update_audit() cascade;
drop function if exists fnc_trg_person_delete_audit() cascade;
drop function if exists fnc_trg_person_insert_audit() cascade;
truncate person_audit;

create function fnc_trg_person_audit() returns trigger as $trg_person_audit$
    begin
        if (tg_op = 'DELETE') then
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'D',old.id,old.name,old.age,old.gender,old.address;
        elsif (tg_op = 'UPDATE') then
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'U',old.id,old.name,old.age,old.gender,old.address;
        elsif (tg_op = 'INSERT') then
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'I',new.id,new.name,new.age,new.gender,new.address;
        end if;
        return null;
    end
$trg_person_audit$ LANGUAGE plpgsql;

create trigger trg_person_audit after delete or update or insert on person
    for each row execute procedure fnc_trg_person_audit();

INSERT INTO person(id, name, age, gender, address)  VALUES (10,'Damir', 22, 'male', 'Irkutsk');
UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;
DELETE FROM person WHERE id = 10;