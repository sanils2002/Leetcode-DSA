# Write your MySQL query statement below
select if((select max(id) from seat)%2=1 and id=(select max(id) from seat), id, if(id%2=1, id+1, id-1)) as id, student
from seat
order by id;