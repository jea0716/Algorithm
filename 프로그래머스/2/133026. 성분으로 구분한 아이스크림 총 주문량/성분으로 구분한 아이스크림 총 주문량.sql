-- 코드를 입력하세요
SELECT
II.INGREDIENT_TYPE,
SUM(FH.TOTAL_ORDER) AS TOTAL_ORDER
FROM FIRST_HALF AS FH
INNER JOIN ICECREAM_INFO AS II ON FH.FLAVOR = II.FLAVOR
GROUP BY II.INGREDIENT_TYPE
