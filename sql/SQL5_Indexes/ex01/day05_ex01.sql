set enable_seqscan = off;
EXPLAIN ANALYZE
SELECT menu.pizza_name, pizzeria.name as pizzeria_name
FROM menu, pizzeria
WHERE menu.pizzeria_id = pizzeria.id