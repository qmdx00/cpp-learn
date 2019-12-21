# sequence list makefile
# $@ 目标文件
# $< 第一个依赖文件
# $^ 所有的依赖文件

CC = g++
OUT = test
DEPS = status.h sequence_list.h
SRCS = test.cpp sequence_list.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $<

clean:
	rm $(OBJS) $(OUT)
