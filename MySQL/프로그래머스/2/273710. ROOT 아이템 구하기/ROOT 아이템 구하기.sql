-- 코드를 작성해주세요
SELECT A.ITEM_ID, A.ITEM_NAME
FROM ITEM_INFO A
JOIN ITEM_TREE TR ON TR.ITEM_ID = A.ITEM_ID 
WHERE TR.PARENT_ITEM_ID IS NULL