CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats as
SELECT pizzeria.name as pizzeria_name
FROM pizzeria,person,person_visits, menu
WHERE pizzeria.id = person_visits.pizzeria_id AND person_visits.person_id = person.id AND person.name = 'Dmitriy' AND person_visits.visit_date = '2022-01-08' AND menu.pizzeria_id = pizzeria.id AND menu.price < 800