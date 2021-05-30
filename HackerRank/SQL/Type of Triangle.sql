 --05/2021
SELECT 
    CASE WHEN (2 * GREATEST(A,B,C) < (A+B+C)) THEN 
        CASE 
             WHEN (A = B AND B = C) THEN 'Equilateral'
             WHEN ((A = B) OR (A = C) OR (B = C)) THEN 'Isosceles' 
             ELSE 'Scalene' END  
    ELSE 'Not A Triangle' END
FROM triangles 