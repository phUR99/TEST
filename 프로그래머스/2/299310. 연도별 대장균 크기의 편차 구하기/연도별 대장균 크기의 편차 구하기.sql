-- 코드를 작성해주세요
WITH ECOLI_MOD AS
(
    SELECT        
        MAX(SIZE_OF_COLONY) AS MX,
        YEAR(DIFFERENTIATION_DATE) AS YEAR
    FROM 
        ECOLI_DATA
    GROUP BY
        YEAR
)
SELECT
    YEAR,
    EM.MX - SIZE_OF_COLONY AS YEAR_DEV,
    ID
FROM    
    ECOLI_DATA ED
JOIN
    ECOLI_MOD EM
ON
    YEAR(DIFFERENTIATION_DATE) = EM.YEAR
ORDER BY
    EM.YEAR ASC, YEAR_DEV ASC;