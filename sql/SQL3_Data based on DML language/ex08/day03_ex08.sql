INSERT INTO menu
VALUES ((SELECT MAX(id)+1
         FROM menu),2 ,'sicilian pizza', 900)