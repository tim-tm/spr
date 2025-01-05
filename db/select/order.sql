-- sqlite3 settings for prettier output
.mode columns
.header on

SELECT * FROM Products ORDER BY ProductName DESC;
SELECT * FROM Products ORDER BY Price DESC;
SELECT * FROM Products ORDER BY Price;

SELECT * FROM Customers ORDER BY Country, CustomerName;
