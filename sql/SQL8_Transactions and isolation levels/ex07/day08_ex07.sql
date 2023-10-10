Сессия 1:
begin;
Сессия 2:
begin;
Сессия 1:
update pizzeria set rating = 2.1 where id = 1; -- Обновление первой сессии, где id = 1
Сессия 2:
update pizzeria set rating = 2.2 where id = 2; -- Обновление второй сессии, где id = 2
Сессия 1:
update pizzeria set rating = 2.3 where id = 2; -- Обновление первой сессии, где id = 2. 1-ая сессия встает и ожидает ответа от 2-ой сессии.
Сессия 2:
update pizzeria set rating = 2.5 where id = 1; -- Обновление второй сессии, где id = 1. 2-ая сессия встает и ожидает ответа от 2-ой сессии => deadlock
Сессия 1:
commit;
Сессия 2:
commit;