# sequence list makefile
# $@ 目标文件集合
# $< 第一个依赖文件
# $^ 所有的依赖文件

CC = g++
EXEC = test	# 可执行文件
DEPS = *.h	# 依赖文件集合
SRCS = test.cpp sequence_list.cpp	# 源文件集合
OBJS = $(SRCS:%.cpp=%.o)	# 表示将源文件中所有以.cpp结尾的文件替换成以.o结尾

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

