SELECT person.name AS person_name, pizza_name, pizzeria.name as pizzeria_name
FROM person_order, menu, pizzeria, person
WHERE person_order.person_id = person.id AND person_order.menu_id = menu.id AND menu.pizzeria_id = pizzeria.id
ORDER BY person.name,pizza_name,pizzeria.name