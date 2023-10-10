SELECT DISTINCT person.name,menu.pizza_name,menu.price,menu.price - (menu.price*person_discounts.discount/100) as discount_price,pizzeria.name as pizzeria_name
FROM person
JOIN person_order ON person_order.person_id = person.id
JOIN person_discounts ON person.id = person_discounts.person_id
JOIN menu ON menu.id = person_order.menu_id
JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
ORDER BY 1,2