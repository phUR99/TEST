WITH P1 AS (
    SELECT
        ID,
        (SELECT PARENT_ID FROM ECOLI_DATA WHERE ECOLI_DATA.ID = E.PARENT_ID) AS PID1
    FROM 
        ECOLI_DATA E
)
SELECT
    ED.ID
FROM
    ECOLI_DATA ED
JOIN
    P1 ON P1.ID = ED.ID
WHERE
    ED.PARENT_ID IS NOT NULL AND P1.PID1 IS NOT NULL 
    AND (SELECT PARENT_ID FROM ECOLI_DATA WHERE P1.PID1 = ECOLI_DATA.ID) IS NULL
ORDER BY
    ED.ID ASC
