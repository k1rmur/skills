SELECT pizza_name, price, pizzeria.name, person_visits.visit_date
FROM pizzeria, menu, person, person_visits
WHERE price <= 1000 AND price >= 800 AND person.name = 'Kate' AND person.id = person_visits.person_id AND person_visits.pizzeria_id = pizzeria.id AND pizzeria.id = menu.pizzeria_id
ORDER BY pizza_name, price, pizzeria.name