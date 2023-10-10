WITH people_id AS (
    SELECT *
    FROM generate_series(date '2022-01-01',date '2022-01-10',interval '1 day')
)
SELECT to_char(generate_series,'yyyy-mm-dd') as missing_date
    FROM people_id
         LEFT JOIN (SELECT visit_date
          FROM person_visits
    WHERE person_visits.person_id = 1 OR person_visits.person_id = 2) as weee ON generate_series = weee.visit_date
    WHERE weee.visit_date isnull
ORDER BY visit_date