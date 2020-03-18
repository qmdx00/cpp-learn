# examples makefile
# 执行前先执行其它同级目录的 makefile

CC = g++
CFLAGS = -Wall -g

SOURCE = $(wildcard *.cpp)
TARGET = $(patsubst %.cpp, %, $(SOURCE))
OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
DEPS = $(shell find .. -path ../examples -prune -o -name "*.o" ! -name "test.o" -type f -print)



$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(DEPS)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(TARGET) $(OBJS)

all:
	@echo $(SOURCE)
	@echo $(TARGET)
	@echo $(OBJS)
	@echo $(DEPS)
