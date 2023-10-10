SELECT we.pizzeria_name
FROM (SELECT COUNT(*) as female_visits, pizzeria.name as pizzeria_name
      FROM person_visits,
           person,
           pizzeria
      WHERE person_visits.person_id = person.id
        AND pizzeria.id = person_visits.pizzeria_id
        AND person.gender = 'female'
      GROUP BY pizzeria.name) as we,(SELECT COUNT(*) as female_visits, pizzeria.name as pizzeria_name
      FROM person_visits,
           person,
           pizzeria
      WHERE person_visits.person_id = person.id
        AND pizzeria.id = person_visits.pizzeria_id
        AND person.gender = 'male'
      GROUP BY pizzeria.name) as we2
WHERE we.pizzeria_name = we2.pizzeria_name AND we.female_visits > we2.female_visits
UNION ALL
SELECT we.pizzeria_name
FROM (SELECT COUNT(*) as female_visits, pizzeria.name as pizzeria_name
      FROM person_visits,
           person,
           pizzeria
      WHERE person_visits.person_id = person.id
        AND pizzeria.id = person_visits.pizzeria_id
        AND person.gender = 'female'
      GROUP BY pizzeria.name) as we,(SELECT COUNT(*) as female_visits, pizzeria.name as pizzeria_name
      FROM person_visits,
           person,
           pizzeria
      WHERE person_visits.person_id = person.id
        AND pizzeria.id = person_visits.pizzeria_id
        AND person.gender = 'male'
      GROUP BY pizzeria.name) as we2
WHERE we.pizzeria_name = we2.pizzeria_name AND we.female_visits < we2.female_visits
ORDER BY 1