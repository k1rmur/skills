SELECT pizzeria_name_1.pizza_name, pizzeria_name_1.name as pizzeria_name_1, pizzeria_name_2.name as pizzeria_name_2, pizzeria_name_1.price
FROM (SELECT pizzeria.name, pizzeria.id, menu.price, menu.pizza_name
    FROM pizzeria, menu
    WHERE pizzeria.id = menu.pizzeria_id) as pizzeria_name_1,
     (SELECT pizzeria.name, pizzeria.id, menu.price, menu.pizza_name
    FROM pizzeria, menu
    WHERE pizzeria.id = menu.pizzeria_id) as pizzeria_name_2
WHERE pizzeria_name_1.price = pizzeria_name_2.price
  AND pizzeria_name_1.id > pizzeria_name_2.id
  AND pizzeria_name_1.pizza_name = pizzeria_name_2.pizza_name
ORDER BY 1