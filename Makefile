TARGET := main

CFLAGS := -Wall -Wextra -Werror -DNDEBUG -O2 -lcryptopp

SOURCES := $(wildcard *.cpp)

CC := g++

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean :
	rm $(TARGET)