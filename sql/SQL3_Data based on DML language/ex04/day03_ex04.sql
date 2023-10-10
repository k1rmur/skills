(SELECT pizzeria.name as pizzeria_name
FROM pizzeria, person, person_order, menu
WHERE person.id = person_order.person_id
  AND person_order.menu_id = menu.id
  AND menu.pizzeria_id = pizzeria.id
  AND person.gender = 'male'
UNION
SELECT pizzeria.name
FROM pizzeria, person, person_order, menu
WHERE person.id = person_order.person_id
  AND person_order.menu_id = menu.id
  AND menu.pizzeria_id = pizzeria.id
  AND person.gender = 'female')
EXCEPT
(SELECT pizzeria.name
FROM pizzeria, person, person_order, menu
WHERE person.id = person_order.person_id
  AND person_order.menu_id = menu.id
  AND menu.pizzeria_id = pizzeria.id
  AND person.gender = 'male'
INTERSECT
SELECT pizzeria.name
FROM pizzeria, person, person_order, menu
WHERE person.id = person_order.person_id
  AND person_order.menu_id = menu.id
  AND menu.pizzeria_id = pizzeria.id
  AND person.gender = 'female')
ORDER BY 1