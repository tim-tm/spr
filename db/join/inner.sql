-- sqlite3 settings for prettier output
.mode columns
.header on

SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate FROM Orders
JOIN Customers ON Orders.CustomerID=Customers.CustomerID
ORDER BY Customers.CustomerName;

SELECT Orders.OrderID, Customers.CustomerName, Orders.OrderDate FROM Orders
JOIN Customers ON Orders.CustomerID=Customers.CustomerID
ORDER BY Orders.OrderDate DESC;
