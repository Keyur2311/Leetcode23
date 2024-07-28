/* Write your PL/SQL query statement below */

SELECT  DISTINCT s.stock_name,
       (
       (SELECT SUM(price) FROM Stocks  WHERE stock_name=s.stock_name AND operation='Sell')
       -
       (SELECT SUM(price) FROM Stocks  WHERE stock_name=s.stock_name AND operation='Buy')
       )
       AS capital_gain_loss FROM Stocks s