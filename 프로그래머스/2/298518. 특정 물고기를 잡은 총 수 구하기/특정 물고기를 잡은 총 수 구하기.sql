-- 코드를 작성해주세요
SELECT COUNT(ID) AS FISH_COUNT FROM FISH_INFO AS FI
LEFT JOIN FISH_NAME_INFO AS FNI
ON FI.FISH_TYPE = FNI.FISH_TYPE
WHERE FISH_NAME = 'BASS' OR FISH_NAME = 'SNAPPER' 