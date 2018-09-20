- delete the duplicates
  
```sql
#If you want to keep the row with the lowest id value:
DELETE n1 FROM names n1, names n2 WHERE n1.id > n2.id AND n1.name = n2.name

# If you want to keep the row with the highest id value:
DELETE n1 FROM names n1, names n2 WHERE n1.id < n2.id AND n1.name = n2.name
```

- select id from a and not in  b;
```sql

select a.id from a left join b on a.id=b.id where b.id is null
```
- update use case
```sql
update TBL set Nmbr = case when Nmbr = 0 then Nmbr+2 else Nmbr+3 end;

UPDATE SALARIES SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END
```
- union:
```sql
select * from a union select * from b;

SELECT * FROM mytable WHERE a=X UNION ALL SELECT * FROM mytable WHERE b=Y AND a!=X

#or 
select distinct c.* from (select * from a union all select * from b) as c;


# equals to 
select * from a union distinct select * from b;
```
- groupby
```sql
SELECT
      u.user_id,
      username,
      training_id,
      training_date,
      count( user_training_id ) AS count
  FROM users u JOIN training_details t ON t.user_id = u.user_id
  GROUP BY u.user_id,
           username,
           training_id,
           training_date
  HAVING count( user_training_id ) > 1
  ORDER BY training_date DESC;

```
- select the top 
```sql
select * from test where id%2=0 limit 1,10;
```
- rank()
```sql
SELECT @rank:=@rank+1 from test,(SELECT @rank:=0) q;

# or 
SET @rank:=0;
SELECT pid, name, age, @curRank := @curRank + 1 AS rank
FROM players
ORDER BY age

```
- `where` and `having`
    - The WHERE clause is used to filter records from a result. The filtering occurs before any groupings are made.
    - The HAVING clause is used to filter values from a group (i.e., to check conditions after aggregation into groups has been performed).
- order by
```sql 
select * from test order by 2
# order by the column 2
```

- sum 
```sql 
select sum(1) from test;
#the column is 5 then sum(1)=5, sum(2)=10

```
- multi-in
```sql
select * from test where yellow in (col1,col2,col3)
```
- `in` vs `exists`
    - IN:

        * Works on List result set
        * Doesn’t work on subqueries resulting in Virtual tables with multiple columns
        * Compares every value in the result list
        * Performance is comparatively SLOW for larger result set of subquery

    - EXISTS:

        * Works on Virtual tables
        * Is used with co-related queries
        * Exits comparison when match is found
        * Performance is comparatively FAST for larger result set of subquery
- CTE(common table expression)
    - A common table expression is a named temporary result set that exists only within the execution scope of a single SQL statement e.g.,SELECT, INSERT, UPDATE, or DELETE.
    - a CTE is not stored as an object and last only during the execution of a query. Different from a derived table, a CTE can be self-referencing (a recursive CTE) or can be referenced multiple times in the same query. In addition, a CTE provides better readability and performance in comparison with a derived table.

- To select the numeric column
```sql
select * from test where concat('',id*1)=id;
```
- transform
```sql 

SELECT col, case when upper(col) = lower(col) then 'Fizz' else 'Buzz' end as FizzBuzz from table;
```

- get the sum of positive number and negative number
```sql
select sum(case when x>0 then x else 0 end)sum_pos
,sum(case when x<0 then x else 0 end)sum_neg from a;
```
- copy data from a table
```sql
INSERT INTO table2 (column1, column2, column3, ...)
SELECT column1, column2, column3, ...
FROM table1
WHERE condition;
```
- `in` vs `from`


Find the SQL statement below that is equal to the following: SELECT name FROM customer WHERE state = 'VA';

    * SELECT name IN customer WHERE state IN ('VA');
    * SELECT name IN customer WHERE state = 'VA';
    * SELECT name IN customer WHERE state = 'V';
    * SELECT name FROM customer WHERE state IN ('VA');
The last one
- transpose column to row
```sql

mysql> select * from tb order by cname,cource;n
+-------+---------+-------+
| cname | cource  | score |
+-------+---------+-------+
| a     | chinese |    74 |
| a     | math    |    83 |
| a     | phy     |    90 |
| b     | chinese |    87 |
| b     | math    |    82 |
| b     | phy     |    93 |
+-------+---------+-------+
6 rows in set (0.00 sec)


mysql> select cname,sum(if(cource='chinese',score,0)) as chinese,sum(if(cource='math',score,0)) as math ,sum(if(cource='phy',score,0)) as phy from tb group by cname;
+-------+---------+------+------+
| cname | chinese | math | phy  |
+-------+---------+------+------+
| a     |      74 |   83 |   90 |
| b     |      87 |   82 |   93 |
+-------+---------+------+------+
2 rows in set (0.00 sec)

```