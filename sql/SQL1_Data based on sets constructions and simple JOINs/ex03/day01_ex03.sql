SELECT order_date as action_date, person_id
FROM (
    SELECT order_date, person_id
    FROM person_order
     ) as action_date
UNION
SELECT visit_date, person_id
FROM (
    SELECT visit_date, person_visits.person_id
    FROM person_visits,person_order
    WHERE visit_date = order_date
     ) as we
ORDER BY action_date, person_id DESC
