/* Write your PL/SQL query statement below */

select id,
       CASE 
           WHEN p_id IS NULL THEN 'Root'
           WHEN id in (select p_id from Tree) THEN 'Inner'
           ELSE 'Leaf'
       END AS "type"
from Tree