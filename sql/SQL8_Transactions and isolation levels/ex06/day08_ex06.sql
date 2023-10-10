Сессия 1:
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ; -- Замена уровня изоляции 1-ой сессии
SHOW TRANSACTION ISOLATION LEVEL;
Сессия 2:
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ; -- Замена уровня изоляции 2-ой сессии
SHOW TRANSACTION ISOLATION LEVEL; 
Сессия 1:
select sum(rating) from pizzeria; -- Вывод суммы из таблицы 1-ой сессии
Сессия 2:
update pizzeria set rating = 5 where name = 'Pizza Hut'; -- Обновление 2-ой сессии
Сессия 2:
COMMIT; -- Коммит 2-ой сессии
Сессия 1:
select sum(rating) from pizzeria; -- Вывод суммы из таблицы 1-ой сессии
Сессия 1:
COMMIT; -- Коммит 1-ой сессии
Сессия 1:
select sum(rating) from pizzeria; -- Вывод суммы из таблицы 1-ой сессии
Сессия 2:
select sum(rating) from pizzeria; -- Вывод суммы из таблицы 2-ой сессии