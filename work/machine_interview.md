- svm kernel method
    - kernel types
        - linear kernel
        - polynomial kernels
        - rbf
        - sigmoid kernels
    - usage
        - 如果特征的数量大道和样本数量差不多，选用logistic regression 或者线性核的SVM；
        - 如果特征数量小，样本的数量正常，则选用SVM+RBF；
        - 如果特征的数量小，而样本的数量很大，则需要手工添加一些特征转化成第一种情况。
- random forest
    - process
        - draw a random bootstrap sample of size n(randomly choose n samples from the training set with replacement)
        - grow a decision tree from the bootstrap sample.At each node
            - randomly select *d* features without replacement
            - split the node using the feature that provides the best split according to the objective function,for instance, maximizing the information gain
        - repeat the two steps *k* times
        - aggregate the prediction by each tree to assign the class label by **majority voting**
    - criterion to split
        - classification:gini index(CART default) or information gain
        - regression:MSE(CART default) or MAE(mean absolute error)
- Decision Tree
    - information gain:
        - $I(x,y)=H(x)-H(x|y)$,条件熵度量了在知道Y以后的不确定性
        - ID3选取信息增益大的结点进行分裂
        - ID3不足：
            - ID3没有考虑连续特征，比如长度，密度都是连续值，无法在ID3运用。这大大限制了ID3的用途。
            - ID3采用信息增益大的特征优先建立决策树的节点。很快就被人发现，在相同条件下，取值比较多的特征比取值少的特征信息增益大。比如一个变量有2个值，各为1/2，另一个变量为3个值，各为1/3，其实他们都是完全不确定的变量，但是取3个值的比取2个值的信息增益大。
            - ID3算法对于缺失值的情况没有做考虑
            - 没有考虑过拟合的问题
    - 信息增益比
        - C4.5
            - 将连续的特征离散化
            - 信息增益作为标准容易偏向于取值较多的特征的问题。引入信息增益比
            - 缺失值处理   
                - 一是在样本某些特征缺失的情况下选择划分的属性：
                - 二是选定了划分属性，对于在该属性上缺失特征的样本的处理：将缺失特征的样本同时划分入所有的子节点，不过将该样本的权重按各个子节点样本的数量比例来分配。
            - over-fitting
                - 引入正则化
        - C4.5不足
            - 由于决策树算法非常容易过拟合，因此对于生成的决策树必须要进行剪枝。
                - 方法：
                    - 预剪枝，即在生成决策树的时候就决定是否剪枝
                    - 后剪枝，即生成决策树，再通过交叉验证来剪枝
            - 生成的是多叉树
            - 只能用于分类
            - 基于熵模型，大量对数运算
    - CART
        - GINI index
            - 代表纯度，越小特征越好
        - 处理连续特征，不断二分离散化
        - classification and regression:
            - 连续值的处理方法不同，特征划分点
            - 决策树建立后做预测的方式不同，CART分类树采用叶子节点里概率最大的类别作为当前节点的预测类别。而回归树输出不是类别，它采用的是用最终叶子的均值或者中位数来预测输出结果。
        - CART采用的办法是后剪枝法，即先生成决策树，然后产生所有可能的剪枝后的CART树，然后使用交叉验证来检验各种剪枝的效果，选择泛化能力最好的剪枝策略。
            - CART树的剪枝算法可以概括为两步，第一步是从原始决策树生成各种剪枝效果的决策树，第二部是用交叉验证来检验剪枝后的预测能力，选择泛化预测能力最好的剪枝后的数作为最终的CART树。
- 机器学习基础题
1. LSTM的公式
2. RNN为什么出现梯度消失及BPTT的推导
3. DQN的基本原理么
4. GBDT和随机森林有什么区别, GBDT的原理,如何做分类和回归,随机森林的随机体现在哪方面
5. Wide &Deep的原理
6. GBDT+LR是怎么做的?
7. DQN模型为什么要故经验回放
8.  数据之间如果不是独立同分布的会怎样
9.  AUC的原理介绍一下
10. XGBOOst和GBDT 的区别。
11. 强化学习和监督学习的区别
12. 神经网络里面的损失函数有哪些
13. 机器学习中常见的激活函数有哪些?为什么通常需要零均值?
14. DeepFM介绍
15. FM推导
16. boosting和bagging的区别 ?
17. bagging为什么能减小方差?
18. 交叉熵损失函数, 0-1分类的交叉熵损失函数的形式。什么是凸函
数?0- 1分类为什么用交叉熵而不是平方损失?
21. L1和L 2有什么区别,从数学角度解释L 2为什么能提升模型的泛化能
力。
22. 深度学习中, L2和dropout有哪些区别?
23. L1正则化有哪些好处
24. 如果有一万个地理坐标,转换成1-10000的数,可以用决策树么?
25. CART分类树和ID3以及C4. 5有什么区别?
26. 树集成模型有哪几种实现方式: Bagging和B oosting ,随即森林
的随机体现在哪些方面, AdaBoos是如何改变样本权重, GBDT分类树
拟合的是什么?
27. Dueling DQN和DQN有什么区别
28. early stop对参数有什么影响?
- 数据结构算法题
1. K个有序数组,找一一个长度最小的区间,在这个区间里至少包含每个
数组各一一个数
2. n个[0,n)的数,求每个数的出现次数(不能开辟额外空间)
3. 数组的全排列(空间复杂度O ( 1) )
4. 一堆钞票,尽可能均分(利用背包问题的思想)
5. 无向无环图中,最短路径的最大值( Floyd算法)
6. 层次遍历二叉树
7. 字符串的最长公共子序列(动态规划)
8. 树的前序遍历和zigzag遍历(非递归)
9. 一个数组,所有数组都出现了两次,只有一个数出现了一次,返回
这个数(位运算)
10. 一一个数组,一个数出现了超过一半次数,返回这个数
11. 将除法的结果用字符串返回,如果能够除尽,则返回相除的结果，
如果不能除尽,则无限循环部分用口标记。
12. 数组排序,假设数组排序后的位次和排序前的位次绝对值差值小于
K ,有什么比快排好的算法?
13. 树中两个节点的第一个的公共祖先。
14. 判断是否是回文链表
15. 判断两个链表中是否有相同节点

-  实践题
1. 如果你想往模型中加入一一个特征,如何判定这个特征是否有效?
2. LR和FM的区别? FM需要进行交叉特征的选择么?如果在LR选了一
部分特征做交叉之后,取得了比FM更好的效果,这是为什么?如果FM
变成DeepFM之后, 效果超过了LR ,这又是为什么?
3. 如果逻辑回归的所有样本的都是正样本,那么它学出来的超平面是
怎样的?
4. 哪些场景下的分类问题不适用于交叉熵损失函数?
5. 推荐系统中你认为最重要的环节是什么?
6. 多臂老虎机中,有许多方法,比如e-greedy , timponson采样，
UCB ,这些方法都有哪些适用场景?
7. 如何预测一家店分品类的销量
8. 模型在线下评估和线上使用时,往往出现线上实际效果不如线下效
果的情况,请分析可能的原因。
9. 信息流采样，有n份数据,但是n的长度并不知道,设计一个采样算
法,使得每份被选择的概率是相同的





