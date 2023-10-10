create unique index idx_menu_unique ON menu (pizzeria_id,pizza_name);
set enable_seqscan = off;
EXPLAIN ANALYZE
SELECT pizzeria_id,pizza_name FROM menu
WHERE menu.pizzeria_id > 2 AND pizza_name != 'cheese pizza'