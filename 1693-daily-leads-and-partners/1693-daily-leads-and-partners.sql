/* Write your PL/SQL query statement below */

SELECT TO_CHAR(date_id,'YYYY-MM-DD') date_id,make_name,
       COUNT(DISTINCT(lead_id)) AS unique_leads,
       COUNT(DISTINCT(partner_id)) AS unique_partners
       FROM DailySales
       group by TO_CHAR(date_id,'YYYY-MM-DD'),make_name