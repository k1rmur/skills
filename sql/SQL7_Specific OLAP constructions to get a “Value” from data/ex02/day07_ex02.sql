WITH orders as (SELECT pizzeria.name, count(person_order.id), 'order' as action_type
FROM person_order
JOIN menu ON menu.id = person_order.menu_id
JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
GROUP BY 1
ORDER BY 2 DESC
LIMIT 3),visits as (SELECT pizzeria.name, count(person_visits.id), 'visit' as action_type
FROM person_visits
JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
GROUP BY 1
ORDER BY 2 DESC
LIMIT 3)
SELECT * FROM visits
UNION
SELECT * FROM orders
ORDER BY 3,2 DESC