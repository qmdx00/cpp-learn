# linked list makefile

CC = g++
CFLAGS = -Wall -g
EXEC = test
DEPS = *.h
SRCS = test.cpp linked_list.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(EXEC): $(OBJS)
	$(CC) ${CFLAGS} -o $(EXEC) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) ${CFLAGS} -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

