/* Write your PL/SQL query statement below */

-- select u.user_id AS buyer_id,
--        TO_CHAR(u.join_date,'YYYY-MM-DD') as join_date,
--        (SELECT count(*) from Orders where buyer_id = u.user_id AND EXTRACT(YEAR FROM order_date) = 2019) 
--        AS orders_in_2019 
-- FROM Users u;

SELECT u.user_id as buyer_id, TO_CHAR(u.join_date,'YYYY-MM-DD') as join_date, count(o.order_id) as orders_in_2019
FROM users u
LEFT JOIN Orders o
ON o.buyer_id=u.user_id AND EXTRACT(YEAR FROM order_date)=2019
GROUP BY u.user_id,u.join_date