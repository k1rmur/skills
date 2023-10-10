SELECT menu.id as menu_id
FROM menu
EXCEPT
SELECT person_order.menu_id
FROM person_order,menu
WHERE person_order.id = menu.id
ORDER BY 1
