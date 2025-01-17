SELECT title
FROM movies m
	JOIN ratings r ON r.movie_id = m.id
	JOIN stars s ON s.movie_id = m.id
	JOIN people p ON p.id = s.person_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5