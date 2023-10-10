SELECT person.name, count(person_visits.person_id) as count_of_visits
FROM person
JOIN person_visits ON person_visits.person_id = person.id
GROUP BY person.name
ORDER BY 2 DESC,1
LIMIT 4;