/* Write your PL/SQL query statement below */
select name as Customers from customers
where id NOT IN (SELECT customerId  FROM Orders);