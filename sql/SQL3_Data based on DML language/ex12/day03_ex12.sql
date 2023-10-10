INSERT INTO person_order(id,person_id,menu_id,order_date)
SELECT generate_series((SELECT MAX(person_order.id)+1
                        FROM person_order),
    (SELECT MAX(person_order.id)+MAX(person.id)
     FROM person_order, person
     WHERE person_order.person_id = person.id)), generate_series(1,(SELECT MAX(person.id)
                                                                    FROM person)), (SELECT *
                                                                                    FROM generate_series(19,19)), '2022-02-25'
