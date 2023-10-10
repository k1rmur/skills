INSERT INTO person_visits
VALUES ((SELECT MAX(id)+1
         FROM person_visits), 4, 2, '2022-02-24'),
    ((SELECT MAX(id)+2
         FROM person_visits), 6, 2, '2022-02-24')