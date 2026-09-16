WITH val AS (
    SELECT
        *,
        LAG(people, 1) OVER (ORDER BY id) AS prev_people,
        LAG(people, 2) OVER (ORDER BY id) AS prev_prev_people,
        LEAD(people, 1) OVER (ORDER BY id) AS next_people,
        LEAD(people, 2) OVER (ORDER BY id) AS next_next_people
    FROM Stadium
)

SELECT id, visit_date, people
FROM val
WHERE
    (
        prev_prev_people >= 100
        AND prev_people >= 100
        AND people >= 100
    )
    OR
    (
        prev_people >= 100
        AND people >= 100
        AND next_people >= 100
    )
    OR
    (
        people >= 100
        AND next_people >= 100
        AND next_next_people >= 100
    )
ORDER BY visit_date;