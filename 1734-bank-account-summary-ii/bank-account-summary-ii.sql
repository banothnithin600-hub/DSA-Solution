select u.name,sum(T.amount) as balance
from Users U
join Transactions T
on u.account=T.account 
group by u.account,u.name 
having sum(t.amount)>10000;