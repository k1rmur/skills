Сессия 1:
SHOW TRANSACTION ISOLATION LEVEL; -- Просмотр уровня изоляции 1-ой сессии (авто - READ COMMITTED)
Сессия 2:
SHOW TRANSACTION ISOLATION LEVEL; -- Просмотр уровня изоляции 2-ой сессии (авто - READ COMMITTED)
Сессия 1:
BEGIN;
Сессия 2:
BEGIN;
Сессия 1:
select sum(rating) from pizzeria; -- Вывод суммы из таблицы 1-ой сессии
Сессия 2:
update pizzeria set rating = 1 where name = 'Pizza Hut'; -- Обновление 2-ой сессии
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
