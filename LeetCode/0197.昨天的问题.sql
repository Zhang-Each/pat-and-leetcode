# Write your MySQL query statement below
select a.id from Weather as a join Weather as b
where a.temperature > b.temperature and dateDiff(a.recordDate,b.recordDate) = 1