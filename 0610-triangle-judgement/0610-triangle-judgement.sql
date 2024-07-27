/* Write your PL/SQL query statement below */

select x,y,z,
      CASE 
            WHEN (x+y>z) AND (x+z>y) AND (y+z>x) THEN 'Yes'
            ELSE 'No' 
       END AS "triangle"
from Triangle;
       
