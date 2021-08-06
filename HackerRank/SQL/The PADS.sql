--07/2021
SELECT CONCAT(oc.name, '(', LEFT(oc.occupation, 1), ')')
FROM occupations oc
ORDER BY oc.name;

SELECT CONCAT('There are a total of ', COUNT(oc.occupation), ' ', LOWER(oc.occupation), 's.')
FROM occupations oc
GROUP BY oc.occupation
ORDER BY COUNT(oc.occupation), oc.occupation