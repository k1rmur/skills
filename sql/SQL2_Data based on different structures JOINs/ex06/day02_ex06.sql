SELECT pizza_name, pizzeria.name as pizzeria_name
FROM menu, person_order, person, pizzeria
WHERE person.id = person_order.person_id AND person_order.menu_id = menu.id AND menu.pizzeria_id = pizzeria.id AND (person.name = 'Anna' OR person.name = 'Denis')
ORDER BY 1,2