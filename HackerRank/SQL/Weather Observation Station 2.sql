--05/2021
select 
    round(cast(sum(lat_n) as decimal(10,2)),2), 
    round(cast(sum(long_w) as decimal(10,2)),2)
from station;