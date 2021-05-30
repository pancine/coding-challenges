--03/2021
select distinct city
from station
where right(city,1) not in ('a','e','i','o','u')