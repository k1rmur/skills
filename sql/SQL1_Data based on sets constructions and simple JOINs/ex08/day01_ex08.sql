SELECT person_order.order_date, concat(person_.name,' (age:',person_.age,')') as person_information
FROM (SELECT id as person_id, name,age,gender,address
      FROM person
        ) as person_
NATURAL JOIN person_order
WHERE person_.person_id = person_order.person_id
ORDER BY order_date, person_information