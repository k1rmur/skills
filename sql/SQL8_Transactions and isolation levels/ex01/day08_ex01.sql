Cессия 1:
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN; 
Сессия 2:
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
Сессия 1:
update pizzeria set rating = 4 where name = 'Pizza Hut'; -- Обновление первой в первой сессии
Сессия 2:
update pizzeria set rating = 3.6 where name = 'Pizza Hut'; -- Обновление второй сессии, после этого обновления, 2-ая сессия ждет, пока не завершится 1-ая сессия 
Сессия 1:
COMMIT: -- Коммит 1 сессии, сразу после него обновляется вторая сессия
Сессия 2:
COMMIT; -- Коммит 2 сессии
Сессия 1:
select * from pizzeria where name = 'Pizza Hut'; -- Вывод из таблицы 1-ой сессии
Сессия 2:
select * from pizzeria where name = 'Pizza Hut'; -- Вывод из таблицы 2-ой сессии