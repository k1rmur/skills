create function fnc_persons(in pgender varchar default 'female')
    returns table(name varchar)
    as $$
    select name from person where gender = pgender;
    $$LANGUAGE SQL;

select *
from fnc_persons();

select *
from fnc_persons(pgender := 'male');
