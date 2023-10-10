create function func_minimum(arr numeric[])
    returns table(name varchar)
    as $$
    select min(min_el) from unnest(arr) as min_el
    $$LANGUAGE SQL;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);
