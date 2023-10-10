SELECT person.name
FROM person, menu, person_order
WHERE person.gender = 'female' AND menu.pizza_name = 'pepperoni pizza' AND person.id = person_order.person_id AND person_order.menu_id = menu.id
INTERSECT
SELECT person.name
FROM person, menu, person_order
WHERE person.gender = 'female' AND menu.pizza_name = 'cheese pizza' AND person.id = person_order.person_id AND person_order.menu_id = menu.id