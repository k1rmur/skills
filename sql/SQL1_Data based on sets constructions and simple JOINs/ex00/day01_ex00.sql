SELECT menu.id AS object_id, menu.pizza_name AS object_name
FROM menu,person
UNION
SELECT person.id, person.name
FROM person
