CREATE SEQUENCE seq_person_discounts START WITH 1 INCREMENT 1;

ALTER TABLE person_discounts
ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');

SELECT * FROM setval('seq_person_discounts',(SELECT count(id) FROM person_discounts));

INSERT INTO person_discounts VALUES (nextval('seq_person_discounts'),5,4,33.66);

DELETE FROM person_discounts WHERE person_discounts.discount = 33.66