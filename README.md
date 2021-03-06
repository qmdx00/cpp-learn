### 数据结构实现
《数据结构（C语言版）》严蔚敏 & 吴伟民，c++ 实现，利用了c++的少量特性，如`&` 引用， `std::cout`，`std::cin` 输入输出。

### 完成进度

#### 线性表
- [x] [顺序表](linear_list/sequence_list)
- [x] [链表](linear_list/linked_list)
- [x] [静态链表](linear_list/static_linked_list)
- [x] [双向链表](linear_list/double_linked_list)

#### 栈
- [x] [顺序栈](stack/sequence_stack)
- [x] [链式栈](stack/linked_stack)

#### 队列
- [x] [链式队列](queue/linked_queue)
- [x] [顺序循环队列](queue/sequence_queue)

#### 串
- [ ] [KMP算法]()

#### 树
- [x] [二叉树](tree/binary_tree)
- [x] [线索二叉树](tree/threaded_binary_tree)
- [ ] [二叉排序树(BST)]()
- [ ] [平衡二叉树(AVL)]()
- [ ] [Huffman树]()

#### 图
- [ ] [广度优先搜索]()
- [ ] [深度优先搜索]()
- [ ] [Prim算法]()
- [ ] [Kruskal算法]()
- [ ] [Dijkstra算法]()
- [ ] [Floyd算法]()
#### 查找
- [ ] [二分查找]()
- [ ] [B树]()
- [ ] [散列表]()

#### 内部排序
- [x] [直接插入排序](sort/insert_sort.cpp)
- [x] [希尔排序](sort/shell_sort.cpp)
- [x] [冒泡排序](sort/bubble_sort.cpp)
- [x] [快速排序](sort/quick_sort.cpp)
- [x] [简单选择排序](sort/select_sort.cpp)
- [x] [堆排序](sort/heap_sort.cpp)
- [x] [归并排序](sort/merge_sort.cpp)
- [x] [基数排序](sort/radix_sort.cpp)

### 目录结构

> 以栈(Stack)的实现为例：

```bash
.
├── examples        // 栈的应用
│   ├── makefile
│   └── number_conversion.cpp   // 应用一：数制转换
├── linked_stack    // 链式栈的实现
│   ├── linked_stack.cpp
│   ├── linked_stack.h
│   ├── makefile
│   └── test.cpp
└── sequence_stack  // 顺序栈的实现
    ├── makefile
    ├── sequence_stack.cpp
    ├── sequence_stack.h
    └── test.cpp

3 directories, 10 files
```

### 使用方式
- clone 项目，需要`g++`编译器
- 进入每个单独的实现目录执行`make`命令即可生成二进制的可执行文件
- example 目录为该数据结构的一些应用，进入执行`make`命令即可生成对应的可执行文件
- `make all`显示执行的依赖文件
- `make clean`清除生成的链接文件和可执行文件

#### makefile如下：
```makefile
# $@ 目标文件集合
# $< 第一个依赖文件
# $^ 所有的依赖文件

CC = g++
CFLAGS = -Wall -g           # 编译参数
EXEC = test                 # 可执行文件
SRCS = $(wildcard *.cpp)    # 源文件集合
OBJS = $(SRCS:%.cpp=%.o)    # 目标文件集合

$(EXEC): $(OBJS)
	$(CC) ${CFLAGS} -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CC) ${CFLAGS} -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

all:
	@echo $(SRCS)
	@echo $(OBJS)
```