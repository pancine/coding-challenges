--03/2021
select top 1 city, len(city)
from station
order by len(city), city

select top 1 city, len(city)
from station
order by len(city) desc, city