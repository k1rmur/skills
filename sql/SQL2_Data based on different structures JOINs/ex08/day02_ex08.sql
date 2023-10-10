SELECT person.name
FROM person, menu, person_order
WHERE (person.address = 'Moscow' OR person.address = 'Samara') AND (menu.pizza_name = 'pepperoni pizza' OR menu.pizza_name = 'mushroom pizza') AND person.id = person_order.person_id AND person_order.menu_id = menu.id
ORDER BY person.name DESC
