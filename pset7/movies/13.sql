SELECT DISTINCT name
FROM people
	JOIN stars ON people.id = stars.person_id
	JOIN movies ON stars.movie_id = movies.id
WHERE name IS NOT 'Kevin Bacon' AND movies.id IN (
	SELECT DISTINCT movies.id
	FROM people
		JOIN stars ON people.id = stars.person_id
		JOIN movies ON stars.movie_id = movies.id
	WHERE name = 'Kevin Bacon' AND birth = 1958 )
ORDER BY name