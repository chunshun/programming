- rdd
  ```scala
    val rdd=sc.parallelize(List("fish","dog"))
    val rdd_2=sc.textFile()
    // converting a DataFrame or DataSet(created from the SparkSession)
  ```
  The *SparkContext* represents the connection between a Spark cluster and one running Spark application.The *SparkContext* can be used to create an RDD from a local Scala object(using the *makeRDD* or *parallelize* methods) or by reading from stable storage(text files, binary files,a Hadoop Context).*DataFrames* and *DataSets* can be using the Spark equivalent to a *SparkContext* ,the *SparkSession*
  SparkSession内部封装了SparkContext，所以计算实际上是由SparkContext完成的。
- Dataset

```scala
val nums=spark.range(1,10,1)
nums.orderBy(desc("id")).show()

```
- quick_sort
- Like RDDs, DataFrames and Datasets represent distributed collections, with addi‐
tional schema information not found in RDDs. This additional schema information
is used to provide a more efficient storage layer (Tungsten), and in the optimizer
(Catalyst) to perform additional optimizations.
- Dataset 可以认为是dataframe的一个特例，主要区别是dataset的每一个record存储的是一个强类型而不是一个row
    - dataset可以在编译时检查类型
    - 并且是面型对象的编程接口  
    - df.as[ElementType]可以把dataframe转换为dataset,ds.toDF()可以把dataset转换为dataframe
- Dataset 
    - dataFrame=dataSet[row]/dataFrame=Dataset[T]

- DataFrame/Dataset=>RDD
    ```scala
    val rdd1=DF.rdd
    ``` 
- RDD=>DataFrame
    ```scala
    val testDF=rdd.map{line=>(line._1,line._2)}.toDF("col1","col2")
    ``` 
- RDD=Dataset
    ```scala
    import spark.implicits._
    case class Coltest(col1:String,col2:Int) extends Serializable
    val testDS=rdd.map{line=>Coltest(line._1,line._2)}.toDS

    ``` 
- Dataset=>DataFrame
    ```scala
    val testDF=testDS.toDF
    ```
- DataFrame=>DataSet
    ```scala    
    import spark.implicits._
    case class Coltest(col1:String,col2:Int)extends Serializable //定义字段名和类型
    val testDS = testDF.as[Coltest]

    ```
- Dataframe
```scala
df.select("name").show()
df.filter($"name">12).show()
```
样本类：
```scala
case class Calculator(brand:String,model:String)
val hp20=Calculator("HP","20b")
```
DataFrames can be converted to a Dataset by providing a class. Mapping will be done by name
```scala
val path = "examples/src/main/resources/people.json"
val peopleDS = spark.read.json(path).as[Person]
```
