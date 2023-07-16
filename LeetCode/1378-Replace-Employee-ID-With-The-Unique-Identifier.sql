# Write your MySQL query statement below
select empuni.unique_id as unique_id, emp.name as name
from Employees emp left join EmployeeUni empuni
on emp.id=empuni.id;