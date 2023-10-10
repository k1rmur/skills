SELECT address,round(CAST(max(age) as numeric(10,2))-(cast(min(age) as numeric)/cast(max(age) as numeric(10,2))),2) as
formula,round(avg(person.age),2) as average,
       CASE WHEN round(CAST(max(age) as numeric(10,2))-(cast(min(age) as numeric)/cast(max(age) as numeric(10,2))),2) > round(avg(person.age),2) THEN 'true'
        ELSE 'false'
        END as comparison
FROM person
GROUP BY 1
ORDER BY 1