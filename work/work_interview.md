# 操作系统
# 算法
- lru-cache
- fisher-yates shuffle
- bp
- adaboost
- 
  
# 数据结构
- 二叉树
    - 遍历
        - 递归 vs 非递归
- 哈希表
    - 不适用场景
        * 不适用于范围检索
        * 不能找到具有最大或最小关键码值的记录
        * 不能按关键码值的顺序访问记录
    - 设计
        * 正向快速：给定明文和 hash 算法，在有限时间和有限资源内能计算出 hash 值。
        * 逆向困难：给定（若干） hash 值，在有限时间内很难（基本不可能）逆推出明文。
        * 输入敏感：原始输入信息修改一点信息，产生的 hash 值看起来应该都有很大不同。
        * 冲突避免：很难找到两段内容不同的明文，使得它们的 hash 值一致（发生冲突）。即对于任意两个不同的数  据块，其hash值相同的可能性极小；对于一个给定的数据块，找到和它hash值相同的数据块极为困难。
    - hash 在Java中的应用
        - hashmap
        - hashtable
        - 区别:
            - HashTable线程更加安全，代价就是因为它粗暴的添加了同步锁，所以会有性能损失。
            - 其实有更好的concurrentHashMap可以替代HashTable，一个是方法级，一个是Class级。
- 图
    - DFS
    - BFS
    - 拓扑排序
    - 最小生成树
    - prim 算法（连接）
    - kruskal
- B 树和B+树
- trie树(统计前缀出现的次数;翻译;实现搜索引擎的热门搜索排名;输入自动补全;一亿个号码的文,快速查找某个号码,时间复杂度O(log(N)))
- 第k大
- 第k短路
- 
# 计算机网络
- TCP和UDP的区别
- 三次握手和四次
- 互斥的方式
-  
- 1. 
# spark
- RDD 中`reduceByKey`和`groupByKey`哪个性能好
reduceByKey:reduceByKey会在结果发送至reducer之前会对每个mapper在进行merge,有点类似于在Mapreduce中的Combiner.


