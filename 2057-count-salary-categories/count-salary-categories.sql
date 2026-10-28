-- select (case where account_id<20000 then 'Low Salary'
--              where account_id>20000 and account_id<50000 then 'Average Salary'
--              where account_id>50000 then 'High Salary')as category,
--         (count(acount_id<20000),count(account_id>20000 and account_id<50000),count(account_id>50000))as accounts_count
-- from Accounts;
SELECT 
    'Low Salary' AS category, 
    COUNT(CASE WHEN income < 20000 THEN 1 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT 
    'Average Salary' AS category, 
    COUNT(CASE WHEN income >= 20000 AND income <= 50000 THEN 1 END) AS accounts_count
FROM Accounts

UNION ALL

SELECT 
    'High Salary' AS category, 
    COUNT(CASE WHEN income > 50000 THEN 1 END) AS accounts_count
FROM Accounts;
