
    --  select u.product_id,avg(p.price*u.units) as average_price from Prices p
    --  join UnitsSold u
    --  where u.product_id = p.product_id;
--     SELECT
--     u.product_id,
--     ROUND(SUM(p.price * u.units) / SUM(u.units), 2) AS average_price
-- FROM UnitsSold u
-- JOIN Prices p
--     ON u.product_id = p.product_id
--     AND u.purchase_date BETWEEN p.start_date AND p.end_date
-- GROUP BY u.product_id;
SELECT
    p.product_id,
    ROUND(
        COALESCE(SUM(p.price * u.units) / SUM(u.units), 0),
        2
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
