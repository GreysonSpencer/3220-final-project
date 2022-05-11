TARGET := main

CFLAGS := -Wall -Wextra -Werror -DNDEBUG -O2

SOURCES := $(wildcard *.cpp)

CC := g++

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $^ -lcryptopp -o $@

.PHONY : clean
clean :
	rm $(TARGET)