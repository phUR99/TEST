-- 코드를 입력하세요
SELECT 
    REST_INFO.REST_ID, 
    REST_NAME, 
    FOOD_TYPE, 
    REST_INFO.FAVORITES, 
    ADDRESS, 
    ROUND(AVG(REVIEW_SCORE), 2) AS SCORE
FROM
    REST_INFO
JOIN
    REST_REVIEW
ON    
    REST_INFO.REST_ID = REST_REVIEW.REST_ID
WHERE
    ADDRESS LIKE '서울%'
GROUP BY
    REST_NAME
ORDER BY
    SCORE DESC, FAVORITES DESC;