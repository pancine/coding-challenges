--03/2021
declare @row int = 1

while @row < 21
begin
    select replicate('* ', @row)
    set @row += 1
end