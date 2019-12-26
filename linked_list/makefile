# linked list makefile

CC = g++
OUT = test
DEPS = status.h linked_list.h
SRCS = test.cpp linked_list.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(OUT): $(OBJS)
	$(CC) -o $(OUT) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $<

clean:
	rm $(OBJS) $(OUT)
