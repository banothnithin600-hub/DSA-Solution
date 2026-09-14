with dupl as(
    select email,count(email) as cunt from Person
     group by email
     Having cunt>1
)

select email as Email from dupl;