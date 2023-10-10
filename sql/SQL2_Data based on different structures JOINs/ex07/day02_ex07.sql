SELECT pizzeria.name
FROM pizzeria, person_visits, person, menu
WHERE person.name = 'Dmitriy' AND person_visits.visit_date = '2022-01-08' AND menu.price < 800 AND person.id = person_visits.person_id AND person_visits.pizzeria_id = pizzeria.id AND pizzeria.id = menu.pizzeria_id