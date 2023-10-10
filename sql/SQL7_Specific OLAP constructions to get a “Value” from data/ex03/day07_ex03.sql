WITH orders as (SELECT pizzeria.name, count(person_order.id) as count
FROM person_order
JOIN menu ON menu.id = person_order.menu_id
JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
GROUP BY 1
ORDER BY 2 DESC),visits as (SELECT pizzeria.name, count(person_visits.id) as count
FROM person_visits
JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
GROUP BY 1
ORDER BY 2 DESC), count as (
SELECT pizzeria.name, visits.count+orders.count,visits.count,
CASE WHEN visits.count isnull THEN 0
    ELSE visits.count
END as visits_counter,
CASE WHEN orders.count isnull THEN 0
    ELSE orders.count
    END as orders_counter
FROM pizzeria
JOIN visits ON pizzeria.name = visits.name
LEFT JOIN orders ON pizzeria.name = orders.name)
SELECT count.name,visits_counter+orders_counter as total_count
    FROM count
ORDER BY 2 DESC,1
