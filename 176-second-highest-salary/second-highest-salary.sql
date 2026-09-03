#select (select distinct salary from Employee
#order by salary Desc
#limit 1 OFFSET 1) as SecondHighestSalary; #This code not run for duplic.. value

# We are follow two step to find second max :- subquery
 #select salary from Employee
 SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);
