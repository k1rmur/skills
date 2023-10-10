Сессия 1:
BEGIN;
Сессия 2:
BEGIN;
update pizzeria set rating = 5 where name = 'Pizza Hut'; -- Обновлен столбец rating Pizza Hut для первой сессии
select * from pizzeria; -- Значение обновилось для первой сессии
Сессия 2:
select * from pizzeria; -- Значение не поменялось для 2-ой сессии
Сессия 1:
COMMIT; -- Коммит 1-ой сессии
Сессия 2:
select * from pizzeria; -- Значение обновилось у 2-ой сессии