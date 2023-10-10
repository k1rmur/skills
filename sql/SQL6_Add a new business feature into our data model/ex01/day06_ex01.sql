INSERT INTO person_discounts
WITH counter as (
    SELECT person.id as person_id,person.name,count(person_order.order_date) as count
    FROM person
    JOIN person_order ON person.id = person_order.person_id
    GROUP BY person.id,person.name
),
insert_data as (
    SELECT DISTINCT counter.person_id,pizzeria_id,counter.count
    FROM person_order
    JOIN menu ON person_order.menu_id = menu.id
    JOIN counter ON counter.person_id = person_order.person_id
    ORDER BY counter.person_id
)
SELECT DISTINCT (row_number() over ()),insert_data.person_id, insert_data.pizzeria_id,
CASE WHEN counter.count = 1 THEN 10.5
WHEN counter.count = 2 THEN 22
ELSE 30
END
FROM insert_data
JOIN counter ON insert_data.person_id = counter.person_id
ORDER BY 1
