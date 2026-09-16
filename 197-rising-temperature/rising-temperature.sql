-- WITH prev AS (
--     SELECT
--         *,
--         LAG(temperature) OVER (ORDER BY recordDate) AS prev_val
--     FROM Weather
-- )
-- SELECT id
-- FROM prev
-- WHERE temperature > prev_val;

SELECT w1.id
FROM Weather w1
JOIN Weather w2
    ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;