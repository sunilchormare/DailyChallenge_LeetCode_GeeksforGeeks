select e.Name as Employee
from Employee e, Employee m
where e.ManagerId is not NULL and
e.ManagerId = m.ID and e.Salary > m.Salary