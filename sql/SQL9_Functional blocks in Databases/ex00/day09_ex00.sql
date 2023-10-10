CREATE TABLE person_audit (
    created timestamp with time zone NOT NULL DEFAULT CURRENT_TIMESTAMP,
    type_event char(1) NOT NULL DEFAULT 'I',
    row_id bigint NOT NULL ,
    name varchar,
    age integer,
    gender varchar,
    address varchar
);

alter table person_audit add constraint ch_type_event check (type_event = 'I' OR type_event = 'D' OR type_event = 'U');

create function fnc_trg_person_insert_audit() returns trigger as $trg_person_insert_audit$
    begin
        INSERT INTO person_audit SELECT CURRENT_TIMESTAMP,'I',new.id,new.name,new.age,new.gender,new.address;
        return NULL;
        end
$trg_person_insert_audit$ LANGUAGE plpgsql;

create trigger trg_person_insert_audit after insert on person
    for each row execute procedure fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
