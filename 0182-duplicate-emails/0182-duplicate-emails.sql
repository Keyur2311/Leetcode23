/* Write your PL/SQL query statement below */

SELECT email AS email from Person
group by email 
having count(*) > 1;