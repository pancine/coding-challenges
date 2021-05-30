--03/2021
declare @row int = 20

while @row > 0
begin
    select replicate('* ', @row)
    set @row -= 1
end