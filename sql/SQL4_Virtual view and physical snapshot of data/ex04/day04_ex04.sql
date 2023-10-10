CREATE VIEW v_symmetric_union as
(SELECT person.id as person_id
FROM person, person_visits
WHERE person.id = person_visits.person_id AND person_visits.visit_date = '2022-01-02'
EXCEPT
SELECT person.id
FROM person, person_visits
WHERE person.id = person_visits.person_id AND person_visits.visit_date = '2022-01-06')
UNION
(SELECT person.id
FROM person, person_visits
WHERE person.id = person_visits.person_id AND person_visits.visit_date = '2022-01-06'
EXCEPT
SELECT person.id
FROM person, person_visits
WHERE person.id = person_visits.person_id AND person_visits.visit_date = '2022-01-02')
ORDER BY 1