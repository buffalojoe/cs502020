SELECT name
FROM people p
	JOIN directors d ON p.id = person_id
	JOIN movies m on m.id = d.movie_id
	JOIN ratings r on r.movie_id = m.id
WHERE r.rating >= 9.0
GROUP BY person_id