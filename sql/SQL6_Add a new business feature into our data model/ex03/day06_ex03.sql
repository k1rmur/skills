create unique index idx_person_discounts_unique on person_discounts(pizzeria_id,person_id);
set enable_seqscan = off;
EXPLAIN ANALYZE
SELECT pizzeria_id,person_id
    FROM person_discounts
    WHERE pizzeria_id > 1 AND discount > 0;
INSERT INTO person_discounts VALUES (16, 9 , 5 , 22);