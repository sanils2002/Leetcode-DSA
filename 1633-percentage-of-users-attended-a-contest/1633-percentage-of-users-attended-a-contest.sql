# Write your MySQL query statement below
SELECT
    R.contest_id,
    ROUND(COUNT(R.user_id) / U.total_users * 100, 2) AS percentage
FROM Register R
JOIN (
    SELECT COUNT(DISTINCT user_id) AS total_users
    FROM Users
) U
GROUP BY R.contest_id
ORDER BY percentage DESC, contest_id;
