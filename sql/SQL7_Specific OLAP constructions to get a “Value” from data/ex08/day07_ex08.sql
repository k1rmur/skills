SELECT address, pizzeria.name, count(person_order.id) as count_of_orders
FROM person
JOIN person_order ON person_order.person_id = person.id
JOIN menu ON menu.id = person_order.menu_id
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY 1,2
ORDER BY 1,2