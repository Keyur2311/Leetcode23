/* Write your PL/SQL query statement below */

SELECT d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
       FROM Employee e,Department d
       WHERE e.departmentId = d.id
       AND (e.departmentId,Salary) IN
       (select departmentId,MAX(salary) FROM Employee GROUP BY departmentId);