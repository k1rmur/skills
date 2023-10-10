CREATE VIEW v_price_with_discount as
SELECT person.name, menu.pizza_name, price, round(price - price*0.1) as discount_price
FROM person, menu, person_order
WHERE person.id = person_order.person_id AND person_order.menu_id = menu.id
ORDER BY 1,2