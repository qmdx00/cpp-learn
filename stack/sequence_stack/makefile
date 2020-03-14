# sequence stack makefile

CC = g++ -g
CFLAGS = -Wall -g
EXEC = test
DEPS = *.h
SRCS = test.cpp sequence_stack.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(EXEC): $(OBJS)
	$(CC) ${CFLAGS} -o $(EXEC) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CC) ${CFLAGS} -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

