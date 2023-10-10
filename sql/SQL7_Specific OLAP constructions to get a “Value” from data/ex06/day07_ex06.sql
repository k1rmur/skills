SELECT pizzeria.name,count(person_order.id) as count_of_orders, round(avg(price),2) as average_price,max(price) as max_price,min(price) as min_price
FROM menu
JOIN person_order ON person_order.menu_id = menu.id
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY 1
ORDER BY 1