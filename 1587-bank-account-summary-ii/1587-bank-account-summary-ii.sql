# Write your MySQL query statement below
SELECT U.name, IFNULL(SUM(T.amount), 0) AS balance
FROM Users U
LEFT JOIN Transactions T ON U.account = T.account
GROUP BY U.name
HAVING balance > 10000;
