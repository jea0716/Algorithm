-- 코드를 입력하세요
SELECT 
ANIMAL_ID,
NAME,
SEX_UPON_INTAKE
FROM ANIMAL_INS
WHERE 
NAME LIKE "LUCY" OR
NAME LIKE "ELLA" OR
NAME LIKE "PICKLE" OR
NAME LIKE "ROGAN" OR
NAME LIKE "SABRINA" OR
NAME LIKE "MITTY"
ORDER BY ANIMAL_ID