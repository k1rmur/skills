SELECT (SELECT COALESCE(person.name,'-')) as person_name, we.visit_date, (SELECT COALESCE(pizzeria.name,'-')) as pizzeria_name
FROM (SELECT person_visits.visit_date, person_id, pizzeria_id
        FROM person_visits
        WHERE person_visits.visit_date >= '2022-01-01' AND person_visits.visit_date <= '2022-01-03'
        ) as we
    FULL JOIN pizzeria ON we.pizzeria_id = pizzeria.id
    FULL JOIN person ON we.person_id = person.id
ORDER BY person_name,visit_date,pizzeria.name

