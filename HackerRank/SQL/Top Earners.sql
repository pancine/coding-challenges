 --06/2021 
WITH CTE(employee_id, earnings) 
AS 
(
    SELECT  
        employee_id,
        (months * salary) AS earnings
    FROM Employee 
)
SELECT 
    (SELECT  MAX(earnings) FROM CTE),
    COUNT(*)
FROM employee
WHERE (months * salary) = (SELECT MAX(earnings) FROM CTE)
