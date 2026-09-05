select actor_id,director_id from ActorDirector
group by actor_id , director_id 
HAVING count(actor_id)>=3 AND count(director_id)>=3;