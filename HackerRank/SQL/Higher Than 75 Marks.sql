--03/2021
select name
from students
where marks > 75
order by right(name, 3), id