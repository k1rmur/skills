CREATE VIEW v_generated_dates AS
WITH date_ as (SELECT generated_date::date
               FROM generate_series(date'2022-01-01',date'2022-01-31',interval '1 day') as generated_date)
    SELECT generated_date
    FROM date_
ORDER BY 1;

SELECT * FROM v_generated_dates;