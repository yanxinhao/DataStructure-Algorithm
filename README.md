<!--
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-12-04 17:49:30
 * @LastEditors: yanxinhao
 * @Description: 
-->
# 数据结构与算法
> 考研期间做的数据结构与算法的笔记，实现了我们遇到的一些基本数据结构与算法。主要参考清华邓俊晖老师的课件以及一些上科大算法课的课件。希望能给同样需要学习这门课的同学一些参考

- [数据结构与算法](#数据结构与算法)
  - [数据结构](#数据结构)
    - [介绍](#介绍)
    - [数据结构基础](#数据结构基础)
    - [线性表](#线性表)
      - [向量：](#向量)
      - [链表：](#链表)
        - [链式存储结构：](#链式存储结构)
      - [一些线性表的算法题](#一些线性表的算法题)
    - [栈与队列](#栈与队列)
      - [顺序栈](#顺序栈)
      - [链式栈](#链式栈)
      - [循环队列](#循环队列)
      - [链队](#链队)
      - [栈的应用](#栈的应用)
        - [逆序输出 : 进制转换](#逆序输出--进制转换)
        - [递归嵌套 : 函数调用,括号匹配](#递归嵌套--函数调用括号匹配)
        - [栈混洗 : 等价于n对括号的匹配](#栈混洗--等价于n对括号的匹配)
        - [延迟缓冲 : 中缀表达式求值](#延迟缓冲--中缀表达式求值)
        - [逆波兰表达式（后缀表达式）求值与转换算法](#逆波兰表达式后缀表达式求值与转换算法)
      - [试探回溯法](#试探回溯法)
    - [Priority queue](#priority-queue)
      - [介绍](#介绍-1)
      - [operations](#operations)
      - [实现](#实现)
        - [Complete Binary heap (Binary heap)](#complete-binary-heap-binary-heap)
          - [建堆](#建堆)
      - [Heapsort](#heapsort)
      - [应用](#应用)
    - [散列表](#散列表)
      - [散列的原理](#散列的原理)
      - [The hash process](#the-hash-process)
      - [相关术语](#相关术语)
      - [散列函数](#散列函数)
      - [冲突解决方法](#冲突解决方法)
        - [链接法](#链接法)
        - [开放寻址法](#开放寻址法)
        - [再散列](#再散列)
      - [性能分析](#性能分析)
        - [平均查找长度](#平均查找长度)
      - [hash实例应用](#hash实例应用)
    - [树](#树)
      - [树的术语](#树的术语)
      - [树的性质](#树的性质)
      - [树的表示](#树的表示)
      - [树的遍历](#树的遍历)
        - [深度优先遍历](#深度优先遍历)
          - [Application](#application)
        - [广度优先遍历](#广度优先遍历)
      - [二叉树](#二叉树)
        - [二叉树的一些性质：](#二叉树的一些性质)
        - [二叉树的表示](#二叉树的表示)
        - [遍历二叉树](#遍历二叉树)
        - [线索二叉树](#线索二叉树)
        - [二叉树的重构](#二叉树的重构)
      - [树和森林与二叉树的相互转换](#树和森林与二叉树的相互转换)
      - [树的算法实例](#树的算法实例)
        - [二叉排序树（又称二叉搜索树）](#二叉排序树又称二叉搜索树)
          - [Definition](#definition)
          - [算法和实现](#算法和实现)
        - [平衡二叉树（包含AVL）](#平衡二叉树包含avl)
        - [哈夫曼（Huffman）树和哈夫曼编码](#哈夫曼huffman树和哈夫曼编码)
          - [介绍](#介绍-2)
          - [算法](#算法)
          - [哈夫曼树的特点](#哈夫曼树的特点)
    - [并查集（用于不相交集合的数据结构）](#并查集用于不相交集合的数据结构)
      - [实现](#实现-1)
        - [不相交集合的链表表示](#不相交集合的链表表示)
        - [不相交集合森林](#不相交集合森林)
          - [改进运行时间的启发式策略](#改进运行时间的启发式策略)
    - [图](#图)
      - [图的性质](#图的性质)
      - [特殊图的类型](#特殊图的类型)
      - [图的存储结构](#图的存储结构)
      - [图的算法实例](#图的算法实例)
        - [图的遍历：深度优先搜索与广度优先搜索](#图的遍历深度优先搜索与广度优先搜索)
        - [优先级搜索](#优先级搜索)
        - [最小生成(支撑)树 (MST)](#最小生成支撑树-mst)
          - [Prim](#prim)
          - [Kruskal](#kruskal)
        - [最短路径 (SPT)](#最短路径-spt)
          - [Dijkstral](#dijkstral)
          - [Floid-Warshall](#floid-warshall)
        - [拓扑排序（Topological Sort）(AOV)](#拓扑排序topological-sortaov)
          - [Motivation](#motivation)
          - [Task](#task)
          - [Theorem:](#theorem)
          - [lemmas](#lemmas)
          - [Algorithm](#algorithm)
          - [Analysis](#analysis)
        - [关键路径(AOE)](#关键路径aoe)
          - [相关定义:](#相关定义)
          - [算法流程:](#算法流程)
          - [应用分析](#应用分析)
      - [应用实例](#应用实例)
  - [算法基础](#算法基础)
    - [算法分析基础](#算法分析基础)
      - [时间复杂度](#时间复杂度)
      - [NP完全性:](#np完全性)
        - [判定问题与优化问题](#判定问题与优化问题)
        - [归约](#归约)
        - [例子](#例子)
    - [迭代与递归](#迭代与递归)
      - [迭代算法实例](#迭代算法实例)
      - [尾递归](#尾递归)
      - [减而治之（Decrease and conquer）](#减而治之decrease-and-conquer)
        - [减而治之的实例：](#减而治之的实例)
      - [分而治之（Divide and conquer）](#分而治之divide-and-conquer)
        - [分而治之的实例：](#分而治之的实例)
      - [递归消除：尾递归](#递归消除尾递归)
    - [动态规划](#动态规划)
    - [贪心法](#贪心法)
  - [其他算法领域](#其他算法领域)
    - [近似算法](#近似算法)
    - [随机算法](#随机算法)
  - [算法实战](#算法实战)
    - [排序](#排序)
    - [字符串匹配](#字符串匹配)
      - [暴力匹配算法](#暴力匹配算法)
      - [KMP算法](#kmp算法)
        - [改进思路](#改进思路)
        - [实现](#实现-2)
        - [算法原理](#算法原理)
      - [BM算法](#bm算法)
    - [动态规划例子](#动态规划例子)
  - [参考资料](#参考资料)

## 数据结构

### 介绍

### 数据结构基础

<div align="center"> 
  <img src="./imgs/Abstract_data.png" width=70% height=70% /> 
</div>

### 线性表
#### 向量：
（线性表的顺序存储结构）

#### 链表： 
##### 链式存储结构：
  - 单链表
  - 循环链表
  - 双向链表

#### 一些线性表的算法题
  - 链表逆置
  - 倒数第k个节点
  - 循环移动R位
  - 两个等长有序列表的中位数
  - 单链表的公共后缀
  - 单链表保存绝对值不超过n的整数，删除绝对值相等的节点仅保留第一次出现的节点
  - 有序链表归并
  - 两个有序表求并集，交集，差集
  - 最快时间复杂度合并两个循环链表，已知长度m，n
  - 

### 栈与队列
#### 顺序栈
- 栈空状态 : st.top== -1
- 栈满状态 : st.top== maxSize-1
#### 链式栈

#### 循环队列
> 循环队列必须损失一个存储空间，用来区分队空和队满状态。一般定义队头指针指向队头元素的前一个位置，队尾指针指向队尾元素
- 队空状态 : qu.rear==qu.front
- 队满状态 : (qu.rear+1)%maxSize==qu.front

#### 链队
> 链队的特点就是理论上不存在队列满上溢的情况。队头指向链头，队尾指向链尾
- 队空状态 :lqu->rear==NULL或者lqu->front==NULL

#### 栈的应用

<div align="center"> 
  <img src="./imgs/stack_application.png" width=70% height=70% /> 
</div>

  思考：栈结构适用于具有局部相关的数据

  ##### 逆序输出 : 进制转换
  <table>
    <tr>
    <td><img src="./imgs/conversion_1.png"></td>
    <td><img src="./imgs/conversion_2.png"></td>
    </tr>
  </table>  

  ##### 递归嵌套 : 函数调用,括号匹配
  <table>
    <tr>
    <td><img src="./imgs/parentheses_1.png"></td>
    <td><img src="./imgs/parentheses_2.png"></td>
    <td><img src="./imgs/parentheses_3.png"></td>
    </tr>
  </table>  

  ##### 栈混洗 : 等价于n对括号的匹配
  <table>
    <tr>
    <td><img src="./imgs/permutation_1.png"></td>
    <td><img src="./imgs/permutation_2.png"></td>
    </tr>
    <tr>
    <td><img src="./imgs/permutation_3.png"></td>
    <td><img src="./imgs/permutation_4.png"></td>
    </tr>
  </table>  

  ##### 延迟缓冲 : 中缀表达式求值
  <table>
    <tr>
    <td><img src="./imgs/infix_1.png"></td>
    <td><img src="./imgs/infix_2.png"></td>
    <td><img src="./imgs/infix_3.png"></td>
    </tr>
    <tr>
    <td><img src="./imgs/infix_4.png"></td>
    <td><img src="./imgs/infix_5.png"></td>
    <td><img src="./imgs/infix_6.png"></td>
    </tr>
  </table>  

  ##### 逆波兰表达式（后缀表达式）求值与转换算法
  <table>
    <tr>
    <td><img src="./imgs/rpn_1.png"></td>
    <td><img src="./imgs/rpn_2.png"></td>
    </tr>
    <tr>
    <td><img src="./imgs/rpn_3.png"></td>
    <td><img src="./imgs/rpn_4.png"></td>
    </tr>
  </table>  

#### 试探回溯法

### Priority queue
> pop the object with the highest priority

#### 介绍
  <table>
  <tr>
  <td><img src="./imgs/PQ.png"></td>
  <td><img src="./imgs/PQ_2.png"></td>
  </tr></table>

#### operations
- Top(或者称为getMax)
- Pop(或者称为delMax)
- Push(或者称为insert)

#### 实现
> 容易想到的可选数据结构有向量，列表，多个列表，或者基于BBST。但是向量和列表对于有些操作的时间复杂度为O(n)，而BBST的功能远远超出优先队列的要求，并不需要维护所有元素之间的全序关系。应该有结构更为简单，维护成本更低的方法，使得插入和删除的为O(logn)，getmax为O(1)。这就是完全二叉堆！！！
##### Complete Binary heap (Binary heap)
> 这里用向量来存储完全二叉堆,会用到完全二叉树的性质来访问节点的父亲和孩子。 Implementation using arrays

  Operations
   - Top		O(1)
   - Push		O(ln(n))
   - Pop		O(ln(n))
   - Build		O(n)
  <table>
    <tr>
      <td><img src="./imgs/PQ_push_1.png"></td>
      <td><img src="./imgs/PQ_push_2.png"></td>
      <td><img src="./imgs/PQ_push_3.png"></td>
    </tr>
    <tr>
      <td><img src="./imgs/PQ_pop_1.png"></td>
      <td><img src="./imgs/PQ_pop_2.png"></td>
      <td><img src="./imgs/PQ_pop_3.png"></td>
    </tr>
    </table>

  ###### 建堆
  - Approach 1 : Repeatedly perform push but Complexity : O(nln(n))
  <table>
    <tr>
      <td><img src="./imgs/PQ_Floyd_1.png"></td>
      <td><img src="./imgs/PQ_Floyd_2.png"></td>
    </tr>
    </table>
    
#### Heapsort
  - Time: O(nln(n))
  - Space: O(1)
  <table>
    <tr>
      <td><img src="./imgs/heapsort_1.png"></td>
      <td><img src="./imgs/heapsort_2.png"></td>
      <td><img src="./imgs/heapsort_3.png"></td>
    </tr>
    </table>

#### 应用
  - 试探回溯法 : n皇后问题与迷宫寻径问题

### 散列表
  > 散列表是普通数组概念的推广，当关键字的全域比较小时，直接寻址是简单而有效的，通常用数组（或者称为直接寻址表）。但是当全域很大时，实际存储的关键字集合K相对于全域U可能很小，用数组就会造成大量的空间浪费，空间利用率低。

  这里先简单介绍直接寻址表和散列表:
  - 直接寻址表（数组）: 每个位置（其实就是rank）对应着一个关键字，里面的值指向对应关键字的元素
  - 散列表 : 关键字k的元素被存储在位置h(k)的槽（桶）中，里面的值指向对应关键字k的元素

  #### 散列的原理  
<div align="center"> 
  <img src="./imgs/hash.png" width=70% height=70% /> 
</div>

  #### The hash process

<div align="center"> 
  <img src="./imgs/hash_process.png" width=70% height=70% /> 
</div>
  
  #### 相关术语
  - 装填因子:有两种不同的定义
    - 算法导论定义:关键字个数/表长度，所以可以大于一
    - 清华大学数据结构严慧敏和邓俊晖的书中定义:表中填入的记录数/哈希表的长度，所以不能大于一
  #### 散列函数
  关于下面第四项均匀性，做出如下解释:\
  If two objects are randomly chosen, there should be only a one-in-M chance that they have the same value from 0 to M – 1 
  (相当于任意随机选一个关键字，他等可能的落入对应的桶中，与确定性不同的是确定性是关键字已经给定)

<div align="center"> 
  <img src="./imgs/hash_function.png" width=70% height=70% /> 
</div>


  #### 冲突解决方法
  
  ##### 链接法

  ##### 开放寻址法
  - 线性探测:容易产生二次聚集
    > 堆积现象 
  - 平方探测
  - 双向平方探测
  - 伪随机探测
  
  ##### 再散列

  #### 性能分析
  ##### 平均查找长度
  查找成功时:

  查找不成功时

#### hash实例应用
  - 桶排序

### 树

#### 树的术语
> 不同的书可能定义不一样
  - 节点的深度 :从根到该节点路径上的路径长度
  - 节点的高度 :从该节点往下的最长路径的路径长度
  - 树的高度 : 等于根节点的高度
  
空树的高度为-1，只有一个节点的树高度为0。
#### 树的性质

> 对于度为m的树，叶节点的个数为n0 = 1+$\sum_{i=1}^m{(i-1)ni}$

#### 树的表示
  - 父节点表示 : 对孩子节点和兄弟节点的访问不方便，均要遍历整个树
  - 孩子节点表示 : 找父节点和兄弟节点很慢
  - 父节点+孩子节点表示 : 这里的孩子节点是第一个孩子节点的指针,当前节点的所有孩子节点连成一个链表。
  - 长子+兄弟表示 : 若在设parent的引用, 访问parent也仅需要O(1)时间

#### 树的遍历
##### 深度优先遍历
A backtracking algorithm for stepping through a tree（回溯法）:
- At any node, proceed to the first child that has not yet been visited
- If we have visited all the children (of which a leaf node is a special case), backtrack to the parent and repeat this process


Each node is visited multiple times in such a scheme（节点会被多次访问）
- First time: before any children
- Last time: after all children, before backtracking

###### Application
Displaying information about directory structures and the files contained within
- Printing a hierarchical structure
- Determining memory usage

##### 广度优先遍历
The easiest implementation is to use a queue:
1. Place the root node into a queue
2. While the queue is not empty:
     - Pop the node at the front of the queue
     - Push all of its children into the queue

#### 二叉树
  - 二叉树:节点度数不超过2的树,同一节点的孩子和子树，均以左右区分(隐含有序)
  - 满二叉树:所有分支节点都有左孩子和右孩子,并且叶子节点都集中在二叉树的最下面一层
  - 完全二叉树:各节点的编号与对应的深度为k的满二叉树相同

##### 二叉树的一些性质：

> 设度数为0,1,2的节点各有n0,n1,n2个,则：
1. 节点数 : n = n0+n1+n2
2. 边数 : e = n-1 = n1+2*n2 (节点数减一 or 所有的出度数)
3. 叶节点数 : n0 = n2+1 (由上面2的等式后两项相等可以推出)
   
> 高度(或者深度)为k的二叉树,则:
1. 整个树最多可能有的节点数 : 2^k - 1 （等比数列求和）
2. 二叉树的第i层最多可能的节点数 : 2^(i-1)
   
> 有n个节点的完全二叉树,若i是某个节点a的编号(编号的范围为1~n)
1. 若i!=1,则a的双亲节点编号为 : ⌊i/2⌋ 
2. 若2i<=n,a的左孩子编号为 : 2i
3. 若2i>n : a无左孩子
4. 若2i+1<=n,a的右孩子的编号为 : 2i+1
5. 若2i+1>n : a无右孩子
6. 完全二叉树的高度为 : ⌊logn⌋+1 或者⌈log(n+1)⌉（底数为二）(有2^(h-1) <= n < 2^h推得)

   

##### 二叉树的表示
- 顺序存储结构 : 用一维数组，最适合完全二叉树
- 链式存储结构 : 每个节点包含一个数据域和指向两个孩子的指针域

##### 遍历二叉树
> 站在图的角度去看待先序，中序，后序遍历二叉树时，其实都是基于深度优先遍历。区别在于对于根节点的访问时间于子树访问时间的相对关系。
  - 先序遍历
  - 中序遍历
  - 后序遍历 : 表达式树
  - 层次遍历
  
 > 由先序或者后序任一种遍历加上中序遍历可以唯一确定一颗二叉树。同时，由中序遍历和层次遍历也能唯一确定一颗二叉树。原理为: 
  > - 先序（后序）遍历确定根
  > - 中序遍历确定左右子树

关于单独给出先序遍历的序列，可以确定的不同形态二叉树的个数为Catalan数。这个用分治法的思路很好证明（即用递推公式）。

>  Catalan数：1/(n+1) * C(n, 2n) 

##### 线索二叉树
- 前序线索化
- 中序线索化
- 后序线索化

##### 二叉树的重构

#### 树和森林与二叉树的相互转换
> 树在转化成二叉树时，非终端节点的孩子中的最右子节点的右指针为空，对应二叉树中根节点的右孩子指针也为空。也就有 所有空右指针个数=非终端节点数+1（根除了其最右孩子的右指针为空外，自己的也为空）；
>  每一个非终端节点都对应了其相应二叉树中一个右指针为空的节点减一。

- 树的先根遍历序列等于该树对应的二叉树的先序序列
- 树的后根遍历序列等于该树对应的二叉树的中序序列

#### 树的算法实例
  ##### 二叉排序树（又称二叉搜索树）
  ###### Definition
In a binary search tree, we require that 
- all objects in the left sub-tree to be less than the object stored in the root node
- all objects in the right sub-tree to be greater than the object in the root object
- the two sub-trees are themselves binary search trees
  ###### 算法和实现
  - 查找: 减而治之,时间复杂度为O(h),h为BST高度
  - 插入: 
    - If we find the object already in the tree, we will return
      - The object is already in the binary search tree (no duplicates)
    - Otherwise, we will arrive at an empty node
    - The object will be inserted into that location
    - The run time is O(h)
  - 删除: 存在两种如下情况
    <table>
    <tr>
    <td><img src="./imgs/BST_1.png"></td>
    <td><img src="./imgs/BST_1_1.png"></td>
    </tr>
      <tr>
    <td><img src="./imgs/BST_2.png"></td>
    <td><img src="./imgs/BST_2_2.png"></td>
    </tr></table>

  ##### 平衡二叉树（包含AVL）
    ###### 介绍
    A binary search tree is said to be AVL balanced if:
    - The difference in the heights between the left and right sub-trees is at most 1, and
    - Both sub-trees are themselves AVL trees

    ###### AVL树节点个数的上下界
    - upper bound :an AVL tree of height h is a perfect binary tree with 2^(h+1)–1 nodes
    - lower bound :
        <table>
          <tr>
        <td><img src="./imgs/AVL_height_1.png"></td>
        <td><img src="./imgs/AVL_height_2.png"></td>
        <td><img src="./imgs/AVL_height_3.png"></td>
        </tr></table>

    ###### AVL树的插入删除
    等价BBST与旋转调整
      <table>
        <tr>
      <td><img src="./imgs/BBST_1.png"></td>
      <td><img src="./imgs/BBST_2.png"></td>
      <td><img src="./imgs/BBST_3.png"></td>
      </tr></table>
    > 对于失衡情况，从最深的那个失衡节点开始考虑推导最方便，下面的插入删除的失衡情况的复盘就是这么得来的
    - 插入:插入导致失衡,肯定是将节点插到最深的失衡节点的最长的分支上
        <table>
        <tr>
        <td>zag和zig</td>
        <td>zigzag和zagzig</td>
        <td>实现</td>
        </tr>
          <tr>
        <td><img src="./imgs/AVL_insert_1.png"></td>
        <td><img src="./imgs/AVL_insert_2.png"></td>
        <td><img src="./imgs/AVL_insert_3.png"></td>
        </tr></table>
    - 删除:删除导致失衡,肯定是将失衡节点较短的左分支或者右分枝上的节点删除
        <table>
          <tr>
        <td><img src="./imgs/AVL_remove_1.png"></td>
        <td><img src="./imgs/AVL_remove_2.png"></td>
        <td><img src="./imgs/AVL_remove_3.png"></td>
        </tr></table>
    - 旋转:旋转操作的实现是3+4算法，旋转只是为了帮助理解
        <table>
        <tr>
        <td><img src="./imgs/AVL_rotation_1.png"></td>
        <td><img src="./imgs/AVL_rotation_2.png"></td>
        <td><img src="./imgs/AVL_rotation_3.png"></td>
        </tr></table>
  ##### 哈夫曼（Huffman）树和哈夫曼编码
  ###### 介绍
  > 哈夫曼树又叫做最优二叉树。他的特点是带权路径最短。

  - 带权路径长度: 该节点到根之间的路径长度*节点权值
  ###### 算法
  > 前缀码:任一字符的编码都不是另一字符编码串的前缀;前缀码与树的联系:根通往任一叶子节点的路径都不可能是通往其余叶子节点的子路径
  
  > 哈夫曼编码算法流程:
  1. Scan text to be compressed and count frequencies of all characters.
  2. Prioritize characters based on their frequencies in text.
  3. Build Huffman code tree based on prioritized list.
  4. Perform a traversal of tree to determine all code words.
  5. Encode the text using the Huffman codes.

  > 哈夫曼树的构造算法:
  
  While priority queue contains two or more nodes
  1. Create new node
  2. Dequeue node and make it left subtree
  3. Dequeue next node and make it right subtree
  4. Frequency of new node equals sum of frequency of left and right children
  5. Enqueue new node back into queue

  >通过遍历哈夫曼树得到哈夫曼编码

  Perform a traversal of the tree to obtain new code words
  1. Going left is a 0 
  2. Going right is a 1
  3. Code word is only completed when a leaf node is reached 
  ###### 哈夫曼树的特点
  - 权值越大的节点离根节点越近
  - 树中没有度为1的节点。这类树叫做正则（严格）二叉树
  - 树的带权路径长度最短

### 并查集（用于不相交集合的数据结构）

#### 实现
##### 不相交集合的链表表示
##### 不相交集合森林

###### 改进运行时间的启发式策略
  - 按秩合并 : 对于每个节点，维护一个秩，他表示该节点的高度的一个上界。在使用按秩合并策略的UNION操作中，我们可以让具有较小秩的根指向具有较大秩的根。\
    特点:
    - point the root of the shorter tree to the root of the taller tree
    - The height of the taller will increase if and only if the trees are equal in height

  - 路径压缩 : 在FIND-SET操作中，使查找路径中的每个节点指向根。由于rank表示的是高度的上界，则此操作不改变节点rank。
  
<div align="center"> 
  <img src="./imgs/path_compression.png" width=70% height=70% /> 
</div>

带路径压缩的按秩合并的分析:
### 图
#### 图的性质
- 支撑树(spanning tree) 
- 最小支撑树(MST)
  
#### 特殊图的类型
- 有向无环图(DAG)
  
#### 图的存储结构
  - 邻接矩阵 :
    - 空间复杂度 O(n^2)空间,与边数无关，适合稠密图
  - 邻接表
  - 十字链表 : 有向图
  - 邻接多重表 : 无向图

#### 图的算法实例
   #####  图的遍历：深度优先搜索与广度优先搜索

  > 时间复杂度:\
  深搜与广搜的时间复杂度相同，只是访问顶点的顺序不同。而且图的遍历的过程实际上是对每个顶点查找其邻接顶点的过程。其时间复杂度与采用的存储结构有关。当用邻接矩阵时的时间复杂度为O(n^2)，用邻接表时为O(n+e)。

> DFS生成的生成树比BFS的高度相等或者更高。（可以想象BFS生成树为原图的一个子图，在其上面加边用DFS得到的生成树只可能更高）。

  边分类:
  <table>
    <tr>
  <td>BFS : 队列</td>
  <td>DFS : 栈</td>
  </tr>
    <tr>
  <td><img src="./imgs/bfs_edge.png"></td>
  <td><img src="./imgs/dfs_edge.png"></td>
  </tr></table>
  
 #####   优先级搜索 

  <table>
      <tr>
      <td>通用算法</td>
      <td>统一框架</td>
      <td>统一框架</td>
    </tr>
    <tr>
      <td><img src="./imgs/pfs.png"></td>
      <td><img src="./imgs/pfs_1.png"></td>
      <td><img src="./imgs/pfs_2.png"></td>
    </tr>
  </table>

   #####  最小生成(支撑)树 (MST)
> 属于贪心算法,MST是图的极小联通子图。
  
  ######  Prim
> prim 算法只与顶点数有关系与边数没有关系，适用于稠密图
  
  利用优先级排序的模版
    <table>
      <tr>
      <td>极短跨边</td>
      <td>极长环边</td>
    </tr>
    <tr>
      <td><img src="./imgs/prim_1.png"></td>
      <td><img src="./imgs/prim_2.png"></td>
    </tr>
    <tr>
      <td>算法</td>
      <td>实现</td>
    </tr>
    <tr>
      <td><img src="./imgs/prim.png"></td>
      <td><img src="./imgs/prim_3.png"></td>
    </tr>
  </table>

   ###### Kruskal
> 主要由最短边的选取算法上，所以该复杂度复杂度与顶点数无关，由边数决定。适用于稀疏图
  <table>
      <tr>
      <td>策略</td>
      <td>算法框架</td>
    </tr>
    <tr>
      <td><img src="./imgs/kruskal_1.png"></td>
      <td><img src="./imgs/kruskal_2.png"></td>
    </tr>
    <tr>
      <td>正确性</td>
      <td>复杂度</td>
    </tr>
    <tr>
      <td><img src="./imgs/kruskal_3.png"></td>
      <td><img src="./imgs/kruskal_4.png"></td>
    </tr>
  </table>

   #####  最短路径 (SPT)
注意 MST!=SPT 两者的优化方向并不一样
（形象的理解就是生成MST的过程是全面扩张，生成SPT的过程是以某个点为中心按路径长度发散）
  ###### Dijkstral
> 属于贪心算法
    按路径长度递增来产生一个点到其他所有点的最短路径。（从初始点按路径长度扩张）
    
    核心: 
      1. 被选中的节点全部是已经确认了到s的最短路径的（途径的节点全部在已被选中的节点集中）--这一点很重要
      2. 选取新的节点时，被选的新节点不可能经过其他未被选节点到s的路径最短。（新节点到s的路径只经过被选中的节点）
      3. 新的节点加入时，只影响其邻居节点到s的最短路径

应用条件：边不能有负数（由其贪心的本质决定，认为其他任何选择都会付出更大的代价）
  <table>
    <tr>
    <td>最短路径性质</td>
    <td>SPT与MST的优化方向不一样</td>
  </tr>
  <tr>
    <td><img src="./imgs/SPT_1.png"></td>
    <td><img src="./imgs/SPT_2.png"></td>
  </tr>
  <tr>
    <td>算法</td>
    <td>实现</td>
  </tr>
  <tr>
    <td><img src="./imgs/Dijkstra.png"></td>
    <td><img src="./imgs/Dijkstra_implement.png"></td>
  </tr>
  </table>
  
  ###### Floid-Warshall  
  > Floyd算法是一个经典的动态规划算法。

应用条件：可以有负边但是不能有负权回路（如果有负权环，那么最短路将无意义，因为我们可以不断走负权环，这样最短路径值便成为了负无穷。）\
参考链接：https://houbb.github.io/2020/01/23/data-struct-learn-03-graph-floyd
  <table>
    <tr>
    <td>最优解的结构特征</td>
    <td>递归实现</td>
  </tr>
  <tr>
    <td><img src="./imgs/floyd_1.png"></td>
    <td><img src="./imgs/floyd_2.png"></td>
  </tr>
  <tr>
    <td>动态规划</td>
    <td>实现</td>
  </tr>
  <tr>
    <td><img src="./imgs/floyd_3.png"></td>
    <td><img src="./imgs/floyd_4.png"></td>
  </tr>
  </table>


> 所有点对之间的最短距离,应用:搜索图的中心点

  #####   拓扑排序（Topological Sort）(AOV)
  > 有向无环图可以拓扑排序，其邻接矩阵没有明显特征，但是如为三角矩阵，则一定可以拓扑排序
  ###### Motivation
  Dependency between tasks: one task is required to be done before the other task can be done
  Dependencies form a partial ordering 
  - A partial ordering on a finite number of objects can be represented as a directed acyclic graph (DAG)
  ###### Task
  Given a set of tasks with dependencies, is there an order in which we can complete the tasks?
  ###### Theorem:
    A graph is a DAG if and only if it has a topological sorting
    Proof strategy:
    Such a statement is of the form a ↔ b and this is equivalent to:
    a → b and b → a
  ###### lemmas
  First, we need a two lemmas:
  - A DAG always has at least one vertex with in-degree zero
    * That is, it has at least one source
  - Any sub-graph of a DAG is a DAG
  ###### Algorithm
  Idea:
- Given a DAG V, iterate:
  * Find a vertex v in V with in-degree zero
  * Let v be the next vertex in the topological sort
  * Continue iterating with the vertex-induced sub-graph V \ {v}

implement:
  - Use a queue (or other container) to temporarily store those vertices with in-degree zero
  - Each time the in-degree of a vertex is decremented tozero, push it onto the queue

  ###### Analysis

  Therefore, the run time of a topological sort is:∂
  - Q(|V| + |E|)  if we use an adjacency list
  - Q(|V|^2) if we use an adjacency matrix
  
and the memory requirements is Q(|V|)

  #####   关键路径(AOE)
> The critical time of each task is the earliest time that it could be completed after the start of execution \
The critical path is the sequence of tasks determining the minimum time needed to complete the project: \
If a task on the critical path is delayed, the entire project will be delayed

###### 相关定义:
（事件为顶点,活动为边）
- 事件最早开始时间:
- 事件最迟必须开始时间:
- 活动最早开始时间:
- 活动最迟必须开始时间:
- 关键活动: 最早开始时间等于最迟必须开始时间的活动
  
###### 算法流程:
1. 进行拓扑排序，求出每个事件的最早发生时间。(求max)
2. 令最后一个结束事件的最迟发生时间等于其最早开始时间，然后进行逆拓扑排序，计算每个事件的最迟必须开始时间.(求min)
3. 求出各活动的最早和最迟发生时间()
   > 事件的最早开始时间 = 该事件发出的活动的最早开始时间 \
   事件的最迟发生时间-以它为结束点的活动的持续时间 = 该活动的最迟发生时间   
   若某条弧的最早和最迟发生时间相等,则这条弧为关键活动

###### 应用分析
若某些活动不为关键路径共享，减少他并不能影响其他关键路径，总时间仍然不变。

#### 应用实例 
- 检测回路：深度优先搜索，拓扑排序
- 关节点：利用DFS
## 算法基础
### 算法分析基础

#### 时间复杂度
> 复杂度类P即为所有可以由一个确定型图灵机在多项式表达的时间内解决的问题；类NP由所有可以在多项式时间内验证它的解是否正确的决定问题组成，或者等效的说，那些可以在非确定型图灵机上在多项式时间内找出解的问题的集合。很可能，计算理论最大的未解决问题就是关于这两类的关系的：P和NP相等?


- ##### 渐进分析
  <table>
  <tr>
  <td><img src="./imgs/big_O.png"></td>
  <td><img src="./imgs/symbols.png"></td>
  </tr></table>
  
- ##### 复杂度层次
  <table><tr>
  <td><img src="./imgs/growth_speed.png"></td>
  <td><img src="./imgs/complexity.png"></td>
  </tr></table>
- ##### 复杂度分析的主要方法：
  1. **迭代**：级数求和
  2. **递归**：递归跟踪 + 递推方程
  3. 猜测 + 验证

#### NP完全性:
  - P 问题: 存在多项式算法的问题
  - NP 问题: 在多项式时间能验证的问题

  <table>
  <tr>
    <td>  <img src="./imgs/NPC.png"></td>
    <td><img src="./imgs/P_problem.png"></td>
  </tr>
  <tr>
    <td><img src="./imgs/NP_problem.png"></td>
    <td><img src="./imgs/NP_complete.png"></td>
  </tr>
  </table>

##### 判定问题与优化问题
  <table><tr>
  <td><img src="./imgs/decision_problem.png"></td>
  <td><img src="./imgs/decision_optimization.png"></td>
  </tr></table>

##### 归约
  > 通过将问题P的求解归约为对问题Q的求解，就可以利用问题Q的易求解性来证明P的易求解性。一般，当P可以多项式时间归约到Q，说明Q问题比P问题更难。

  <table><tr>
  <td><img src="./imgs/reduction.png"></td>
  <td><img src="./imgs/polynomial_reduction.png"></td>
  </tr></table>

  
##### 例子
NP-complete
<div align="center"> 
  <img src="./imgs/NPC_problems.png" width=70% height=70% /> 
</div>

  - SAT问题:布尔表达式的可满足性
  - 3-SAT问题:3-CNF(3合取范式)形式的布尔表达式的可满足性
  - 最大团问题:团是图结构中最大的完全子图，最大团问题就是求一个图的最大团的顶点数
  - 顶点覆盖问题
  - 图着色问题:最少用多少种颜色对图进行着色
  - bin packing
  - CNF-satisfiability
  - 哈密尔顿回路
  - 旅行商问题

NP-hard
  - Arithmetic SAT
   
### 迭代与递归
迭代算法一般较为常见，递归算法更为直观。因为递归算法需要大量空间资源，所以经常需要将其改写成迭代算法，这里为体现算法的思想，我主要考虑以递归为出发点的思想来理解算法。

#### 迭代算法实例
  - 数组求和
  - 数组最大值

#### 尾递归
>当递归调用是整个函数体中最后执行的语句且它的返回值不属于表达式的一部分时，这个递归调用就是尾递归。尾递归函数的特点是在回归过程中不用做任何操作，这个重要特性很重要，因为大多数现代的编译器会利用这种特点自动生成优化的代码。当编译器检测到一个函数调用是尾递归的时候，它就覆盖当前的活动记录而不是在栈中去创建一个新的。编译器可以做到这点，因为递归调用是当前活跃期内最后一条待执行的语句。于是当这个调用返回时栈帧中并没有其他事情可做，因此也就没有保存栈帧的必要了。通过覆盖当前的栈帧而不是在其之上重新添加一个，这样所使用的栈空间就大大缩减了，这使得实际的运行效率会变得更高。因此，只要有可能我们就需要将递归函数写成尾递归的形式。

以下为递归算法的两种主要思想：
#### 减而治之（Decrease and conquer）

<div align="center"> 
  <img src="./imgs/Decrease_and_conquer.png" width=70% height=70% /> 
</div>

##### 减而治之的实例：
  - 数组求和：线性递归
  - 数组倒置
#### 分而治之（Divide and conquer）

<div align="center"> 
  <img src="./imgs/Divide_and_conquer.png" width=70% height=70% /> 
</div>

##### 分而治之的实例：
  - 数组求和：二分递归
  - 数组的最大值

| 数据结构 | 问题名称 | 问题描述                                           |
| :------: | :------: | :------------------------------------------------- |
|   数组   |   Max2   | 从数组区间A[lo,hi)中找出最大的两个整数A[x1]和A[x2] |
#### 递归消除：尾递归

<div align="center"> 
  <img src="./imgs/tail_recursive.png" width=70% height=70% /> 
</div>

### 动态规划
> 朴素的递归算法(减而治之或分而治之)之所以效率低，是因为他们反复求解相同的子问题。

动态规划的原理:
- 最优子结构性质 : 问题的最优解由相关子问题的最优解组合而成，而这些子问题可以独立求解。
  
  如何发觉最优子结构?这里给出一个通用模式:
  1. 做出一个选择
  2. 假定已经知道了这种选择(先不关心这种选择如何得到)
  3. 考虑这种选择会产生哪些子问题, 以及如何最好刻画子问题空间
  4. 证明构成原问题最优解的组成部分(即每个子问题)的解就是它本身的最优解(一般是反证法)

- 重叠子问题 : 
- 重构最优解

动态规划有两种等价的实现方法:
- 带备忘的自顶向下法(top-down with memoization)
- 自底向上法(bottom-up method)

为构建动态规划的解决方案,一些必要的过程:
- 子问题图
- 重构解
  
例子:

| 数据结构 | 问题名称 | 问题描述                     |
| :------: | :------: | :--------------------------- |
|    串    |   LCS    | 求两个子序列的最长公共子序列 |

### 贪心法 

- 最小生成树
- 单源最短路径的Dijkstra算法
- 分数背包问题

## 其他算法领域
### 近似算法
### 随机算法
> 如在快排中随机选取pivot

- 蒙特卡洛方法

## 算法实战

### 排序

> 有一个问题需要说明：关于用递归实现快排时，如果每次先处理较短的分区能不能降低递归次数和递归栈的深度。我对于这个问题的理解是，都不能，这和网上的很多理解以及严慧敏老师书中的理解不一样。因为当我们直接分析快排的递归树时，一个节点代表一次递归调用，树的高度代表递归栈的深度，不论怎么调用，其实深度和次数都是不变的。

简介：

|   算法名称   | 类别     | 算法描述                                                                  | 稳定性 | 就地 | 时间复杂度（最坏） | 时间复杂度（最好） | 时间复杂度（最好） |
| :----------: | :------- | :------------------------------------------------------------------------ | :----- | :--- | :----------------- | :----------------- | :----------------- |
|   冒泡排序   | 交换排序 |                                                                           | 是     | 是   | O(n^2)             | O(n)               |                    |
|   快速排序   | 交换排序 |                                                                           | 否     | 是   | O(n^2)             | O(nlogn)           | O(nlogn)           |
|   插入排序   | 插入排序 | 把序列看成 sorted[0,)+unsorted[r,n) 两部分,把l[r]插入到有序部分的合适位置 | 是     |      | O(n^2)             | O(n)               | O(n^2)             |
| 一般选择排序 | 选择排序 | 从未排序的元素中挑选最大者,并使其就位                                     | 否     |      | O(n^2)             | O(n^2)             | O(n^2)             |
|    堆排序    | 选择排序 |                                                                           | 否     |      |                    |                    |                    |
| 二路归并排序 | 归并排序 |                                                                           | 是     | 否   | O(nlogn)           | O(nlogn)           |                    |
|   基数排序   | 基数排序 |                                                                           | 是     |      |                    |                    |                    |
|   希尔排序   | 基数排序 |                                                                           | 否     |      |                    |                    |                    |



算法分析：
  <table>
      <tr>
      <td>算法描述</td>
      <td>算法分析</td>
    </tr>
    <tr>
      <td><img src="./imgs/bubblesort.png"></td>
      <td><img src="./imgs/bubblesort_complexity.png"></td>
    </tr>
    <tr>
      <td><img src="./imgs/quicksort.png"></td>
      <td><img src="./imgs/quicksort_2.png"></td>
    </tr>
    <tr>
      <td><img src="./imgs/insertionsort.png"></td>
      <td><img src="./imgs/insertionsort_2.png"></td>
    </tr>
    <tr>
      <td><img src="./imgs/selectionsort.png"></td>
      <td><img src="./imgs/selectionsort_2.png"></td>
    </tr>
    <tr>
      <td><img src="./imgs/mergesort.png"></td>
      <td><img src="./imgs/mergesort_2.png"></td>
    </tr>
  </table>

### 字符串匹配

#### 暴力匹配算法
  <table>
    <tr>
  <td><img src="./imgs/string.png"></td>
  <td><img src="./imgs/string_2.png"></td>
  </tr></table>

#### KMP算法
##### 改进思路
  <table>
    <tr>
    <td><img src="./imgs/KMP_1.png"></td>
    <td><img src="./imgs/KMP_2.png"></td>
    <td><img src="./imgs/KMP_3.png"></td>
    </tr>
  </table>

##### 实现
  <table>
    <tr>
    <td><img src="./imgs/KMP_implement_1.png"></td>
    <td><img src="./imgs/KMP_implement_2.png"></td>
    </tr>
  </table>

##### 算法原理
  <table>
    <tr>
    <td><img src="./imgs/KMP_next_1.png"></td>
    <td><img src="./imgs/KMP_next_2.png"></td>
    </tr>
    <tr>
    <td><img src="./imgs/KMP_next_3.png"></td>
    <td><img src="./imgs/KMP_next_4.png"></td>
    </tr>
  </table>

#### BM算法
> 。。。。

| 算法名称 | 问题描述       | 算法描述 | 时间复杂度 |
| :------: | :------------- | :------- | :--------- |
|   LCS    | 最长公共子序列 |          |            |
|   KMP    | 字符串模式匹配 |          |            |



### 动态规划例子
- 钢条切割
- 矩阵链乘法
- LCS
- 0-1背包问题

## 参考资料
> 这里包含了我整理时用到的所有课件。
- [清华大学邓俊晖老师的相关课件](http://howie.DiskStation.me:5000/sharing/lu8ER3hAg)
- [上海科技大学的算法课课件](http://howie.DiskStation.me:5000/sharing/cJGN2YGFH)
  
> 这是我写的代码部分生成的doxygen文档介绍 
http://howie.diskstation.me:8000/