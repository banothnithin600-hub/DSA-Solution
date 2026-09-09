select p.firstName,p.lastName,A.city,A.state
from Person p
left join Address A
ON p.personId = A.personId;