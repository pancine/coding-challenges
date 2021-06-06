 --06/2021
SELECT 
    CAST(
        CEILING(
            AVG(
                CAST(salary AS float) - CAST(REPLACE(CAST(salary AS varchar(7)),'0','') AS float)
            )
        ) 
        AS int
    )
FROM employees
