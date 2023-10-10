SELECT * FROM mv_dmitriy_visits_and_eats;

INSERT INTO person_visits VALUES (22,9,5,'2022-01-08');

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;