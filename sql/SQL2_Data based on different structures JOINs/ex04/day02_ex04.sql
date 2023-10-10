SELECT menu.pizza_name, pizzeria.name as pizzeria_name, menu.price
FROM menu, pizzeria
WHERE menu.pizzeria_id = pizzeria.id AND (pizza_name = 'mushroom pizza' OR pizza_name = 'pepperoni pizza')
ORDER BY pizza_name,name