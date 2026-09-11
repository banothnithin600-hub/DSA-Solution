WITH rnk AS (
    SELECT
        score,
        DENSE_RANK() OVER (
            ORDER BY score DESC
        ) AS 'rank'
    FROM Scores
)
SELECT * FROM rnk;