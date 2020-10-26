SELECT title
FROM people p
	JOIN stars s ON p.id = s.person_id
	JOIN movies m ON s.movie_id = m.id
WHERE name = 'Johnny Depp' AND title IN(
	SELECT title 
	FROM people p
		JOIN stars s ON p.id = s.person_id
		JOIN movies m ON s.movie_id = m.id
	WHERE name = 'Helena Bonham Carter')