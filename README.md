### 数据结构实现
>《数据结构（C语言版）》严蔚敏 & 吴伟民，c++ 实现，利用了c++的少量特性，如`&` 引用， `std::cout`，`std::cin` 输入输出。

### 完成进度

#### 线性表
- [x] 顺序表
- [x] 链表
- [x] 静态链表
- [x] 双向链表

#### 栈
- [x] 顺序栈
- [x] 链式栈

#### 队列
- [x] 链式队列
- [x] 顺序循环队列

#### 串

#### 广义表

#### 树
- [ ] 二叉树

#### 图

#### 查找

#### 内部排序

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