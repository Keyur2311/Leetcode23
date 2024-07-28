/* Write your PL/SQL query statement below */

select u.user_id AS buyer_id,
       TO_CHAR(u.join_date,'YYYY-MM-DD') as join_date,
       (SELECT count(*) from Orders where buyer_id = u.user_id AND EXTRACT(YEAR FROM order_date) = 2019) 
       AS orders_in_2019 
FROM Users u;