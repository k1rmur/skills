SELECT menu.pizza_name, price, pizzeria.name as pizzeria_name
FROM (
SELECT menu.id
FROM menu
EXCEPT
SELECT person_order.menu_id
FROM person_order,menu
WHERE person_order.id = menu.id) as we, pizzeria, menu
WHERE menu.id = we.id AND menu.pizzeria_id = pizzeria.id
ORDER BY 1,2