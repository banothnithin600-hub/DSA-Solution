with new as(
     select      num,
                LAG(num,1) over (order by id) as prev_num,
                LAG(num,2) over (order by id) as prev_prev
     from Logs
)

select DISTINCT num AS ConsecutiveNums from new 
where num=prev_num and num=prev_prev;