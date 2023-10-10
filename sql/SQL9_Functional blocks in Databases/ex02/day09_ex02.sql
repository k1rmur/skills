create function fnc_trg_person_delete_audit() returns trigger as $trg_person_delete_audit$
    begin
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'D',old.id,old.name,old.age,old.gender,old.address;
        return null;
    end
$trg_person_delete_audit$ LANGUAGE plpgsql;

create trigger trg_person_delete_audit after delete on person
    for each row execute procedure fnc_trg_person_delete_audit();

DELETE FROM person WHERE id = 10;