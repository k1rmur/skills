SELECT person_name1.name as person_name1, person_name2.name as person_name2, person_name1.address as common_address
FROM (SELECT name, address, id
      FROM person) as person_name1, (SELECT name, address, id
      FROM person) as person_name2
WHERE person_name1.address = person_name2.address AND person_name1.id > person_name2.id
ORDER BY person_name1