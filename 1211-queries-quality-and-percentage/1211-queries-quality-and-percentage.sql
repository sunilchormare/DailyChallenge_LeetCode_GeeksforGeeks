SELECT query_name, ROUND(AVG(rating/position),2) quality, ROUND((SUM(IF(rating < 3, 1, 0))/COUNT(query_name)*100),2) poor_query_percentage
FROM Queries
WHERE query_name is not null
GROUP BY query_name