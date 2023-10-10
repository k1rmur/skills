COMMENT ON TABLE person_discounts IS 'Таблица персональных скидок';
COMMENT ON COLUMN person_discounts.id IS 'PK данной таблицы';
COMMENT ON COLUMN person_discounts.person_id IS 'ID таблицы person';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'ID таблицы pizzeria';
COMMENT ON COLUMN person_discounts.discount IS 'Скидка';