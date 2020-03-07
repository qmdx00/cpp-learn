# linked list makefile

CC = g++
EXEC = test
DEPS = *.h
SRCS = test.cpp linked_list.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

