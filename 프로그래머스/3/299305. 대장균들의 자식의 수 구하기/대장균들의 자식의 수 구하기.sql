-- 코드를 작성해주세요
SELECT 
    ID,
    (SELECT 
        COUNT(*) 
     FROM 
        ECOLI_DATA IED 
     WHERE 
        OED.ID = IED.PARENT_ID) AS CHILD_COUNT
FROM
    ECOLI_DATA OED
ORDER BY
    ID ASC;
    