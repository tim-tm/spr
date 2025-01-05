-- sqlite3 settings for prettier output
.mode columns
.header on

SELECT * FROM Customers WHERE City = 'Berlin';
SELECT * FROM Customers WHERE Country = 'Germany';

SELECT * FROM Customers WHERE PostalCode LIKE '1%';
SELECT * FROM Customers WHERE PostalCode LIKE '%1';

SELECT * FROM Customers WHERE Country = 'Germany' AND PostalCode LIKE '1%';
SELECT * FROM Customers WHERE Country = 'Germany' AND (PostalCode LIKE '1%' OR PostalCode LIKE '5%');

SELECT * FROM Customers WHERE City LIKE 'Be__in';
SELECT * FROM Customers WHERE City LIKE 'Be__%';

SELECT * FROM Customers WHERE City IN ('Berlin', 'Paris', 'Madrid', 'Bern') ORDER BY City;
