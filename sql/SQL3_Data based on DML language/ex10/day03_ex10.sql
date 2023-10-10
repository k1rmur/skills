INSERT INTO person_order VALUES ((SELECT MAX(id)+1
                                  FROM person_order), 4, 20, '2022-02-24'),
                             ((SELECT MAX(id)+2
                                  FROM person_order), 6, 20, '2022-02-24')