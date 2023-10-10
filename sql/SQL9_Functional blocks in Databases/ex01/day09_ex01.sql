create function fnc_trg_person_update_audit() returns trigger as $trg_person_update_audit$
    begin
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'U',old.id,old.name,old.age,old.gender,old.address;
        return null;
    end
$trg_person_update_audit$ LANGUAGE plpgsql;

create trigger trg_person_update_audit after update on person
    for each row execute procedure fnc_trg_person_update_audit();

UPDATE person SET name = 'Bulat' WHERE id = 10;
UPDATE person SET name = 'Damir' WHERE id = 10;