create function fnc_persons_female()
    returns table(name varchar) as $$
    select name from person where gender = 'female'
$$LANGUAGE SQL;

create function fnc_persons_male()
    returns table(name varchar) as $$
    select name from person where gender = 'male'
$$LANGUAGE SQL;

SELECT *
FROM fnc_persons_male();

SELECT *
FROM fnc_persons_female();