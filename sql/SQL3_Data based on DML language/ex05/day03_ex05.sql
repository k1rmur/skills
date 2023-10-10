SELECT DISTINCT pizzeria.name as pizzeria_name
FROM person,person_visits, pizzeria
WHERE person.name = 'Andrey' AND person.id = person_visits.person_id AND person_visits.pizzeria_id = pizzeria.id
EXCEPT
SELECT DISTINCT pizzeria.name
FROM pizzeria,menu,person,person_order
WHERE person.name = 'Andrey' AND pizzeria.id = menu.pizzeria_id AND menu.id = person_order.menu_id AND person.id = person_order.person_id
ORDER BY 1