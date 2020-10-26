SELECT name
FROM people p
	JOIN stars ON person_id = p.id
	JOIN movies m ON m.id = movie_id
WHERE year = 2004
GROUP BY person_id
ORDER BY birth