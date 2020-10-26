SELECT ROUND(AVG(rating), 2)
FROM ratings
	JOIN movies ON movies.id = ratings.movie_id
WHERE movies.year = 2012