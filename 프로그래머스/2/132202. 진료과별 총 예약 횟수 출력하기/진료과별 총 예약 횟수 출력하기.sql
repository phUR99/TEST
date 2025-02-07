-- 코드를 입력하세요
SELECT
    MCDP_CD AS 진료과코드,
    COUNT(*) AS 5월예약건수
FROM
    APPOINTMENT
WHERE
    APNT_YMD LIKE "2022-05%"
GROUP BY
    MCDP_CD
ORDER BY
    5월예약건수 ASC, MCDP_CD ASC;
    
    