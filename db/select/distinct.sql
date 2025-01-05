-- sqlite3 settings for prettier output
.mode columns
.header on

SELECT DISTINCT(Country) FROM Customers;
SELECT COUNT(DISTINCT(Country)) FROM Customers;
SELECT DISTINCT(City) FROM Customers;
SELECT COUNT(DISTINCT(City)) FROM Customers;
