- The key differences are:
    - pairRDD operations (such as map, reduceByKey etc) produce key,value pairs. Whereas operations on RDD(such as flatMap or reduce) gives you a collection of values or a single value
    - pairRDD operations are applied on each key/element in parallel.Operations on RDD (like flatMap) are applied to the whole collection.
- These RDDs are called pair RDDs. Pair RDDs are a useful building block in many programs, as they expose operations that allow you to act on each key in parallel or regroup data across the network. 

```scala
rdd.collect() 
// # to see the contents of rdd
rdd.count()
// # return the length of rdd
```

Key/value RDDs are commonly used to perform aggregations, and often we will do some initial ETL (extract, transform, and load) to get our data into a key/value format. Key/value RDDs expose new operations (e.g., counting up reviews for each product, grouping together data with
the same key, and grouping together two different RDDs).
```scala
pairs.filter{case (key, value) => value.length < 20}
```

Spark provides the `mapValues(func)` function, which is the same as `map{case (x, y): (x, func(y))}` .

stage 和 task 的划分问题。只要在 ShuffleDependency 处断开，就只剩 NarrowDependency，而 NarrowDependency chain 是可以进行 pipeline 的。

所以划分算法就是：从后往前推算，遇到 ShuffleDependency 就断开，遇到 NarrowDependency 就将其加入该 stage。每个 stage 里面 task 的数目由该 stage 最后一个 RDD 中的 partition 个数决定。

粗箭头表示 task。因为是从后往前推算，因此最后一个 stage 的 id 是 0，stage 1 和 stage 2 都是 stage 0 的 parents。如果 stage 最后要产生 result，那么该 stage 里面的 task 都是 ResultTask，否则都是 ShuffleMapTask。之所以称为 ShuffleMapTask 是因为其计算结果需要 shuffle 到下一个 stage，本质上相当于 MapReduce 中的 mapper。ResultTask 相当于 MapReduce 中的 reducer（如果需要从 parent stage 那里 shuffle 数据），也相当于普通 mapper（如果该 stage 没有 parent stage）。



请简要描述一下Hadoop, Spark, MPI三种计算框架的特点以及分别适用于什么样的场景

a)Hadoop
基于分布式文件系统HDFS的分布式批处理计算框架。适用于数据量大，SPMD(单程序多数据)的应用。
b)Spark
基于内存计算的并行计算框架。适用于需要迭代多轮计算的应用。
c)MPI
基于消息传递的并行计算框架。适用各种复杂应用的并行计算。支持MPMD( 多程序多数据) ，开发复杂度高