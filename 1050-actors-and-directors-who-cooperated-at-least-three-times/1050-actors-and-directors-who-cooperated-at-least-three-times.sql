/* Write your PL/SQL query statement below */

SELECT actor_id,director_id
FROM ActorDirector
GROUP BY actor_id,director_id
having count(*) > 2