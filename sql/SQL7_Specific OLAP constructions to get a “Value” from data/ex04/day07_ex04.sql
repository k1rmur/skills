WITH persons as (SELECT person.name,count(person_visits.id) as count_of_visits
    FROM person
JOIN person_visits ON person_visits.person_id = person.id
GROUP BY 1)
SELECT *
    FROM persons
WHERE persons.count_of_visits > 3
