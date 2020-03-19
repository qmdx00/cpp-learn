# huffman tree makefile

CC = g++
CFLAGS = -Wall -g
EXEC = test
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

$(EXEC): $(OBJS)
	$(CC) ${CFLAGS} -o $(EXEC) $(OBJS)

%.o: %.cpp
	$(CC) ${CFLAGS} -o $@ -c $<

clean:
	rm $(OBJS) $(EXEC)

all:
	@echo $(SRCS)
	@echo $(OBJS)

