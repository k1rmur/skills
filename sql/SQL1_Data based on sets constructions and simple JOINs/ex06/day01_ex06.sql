SELECT order_date as action_date, name as person_name
FROM (
    SELECT order_date, person.name
    FROM person_order, person
    WHERE person_order.person_id = person.id
     ) as action_date
UNION
SELECT visit_date, name
FROM (
    SELECT visit_date,person.name
    FROM person_visits,person_order, person
    WHERE visit_date = order_date AND person.id = person_order.person_id AND person.id = person_visits.person_id
     ) as person_name
ORDER BY action_date, person_name DESC