select c.name as Customers
from Customers c
left join Orders O
on c.id = O.customerId
where O.customerId is NULL;
