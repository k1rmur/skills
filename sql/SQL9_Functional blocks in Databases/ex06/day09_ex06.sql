create function fnc_person_visits_and_eats_on_date(in pperson varchar default 'Dmitriy',in pprice bigint default 500,
in pdate date default '2022-01-08')
    returns table(name varchar)
    as $$
    select distinct pizzeria.name from pizzeria
    join menu on menu.pizzeria_id = pizzeria.id
    join person_visits on person_visits.pizzeria_id = pizzeria.id
    join person on person.id = person_visits.person_id
    where pperson = person.name AND pprice > menu.price AND pdate = person_visits.visit_date;
    $$LANGUAGE SQL;

select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');
