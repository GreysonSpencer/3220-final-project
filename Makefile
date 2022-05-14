TARGET := main

CFLAGS := -Wall -Wextra -Werror -DNDEBUG -O2

SOURCES := main.cpp AES.cpp Decryptor.cpp Encryptor.cpp FileIO.cpp RC6.cpp

CC := g++

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $^ -lcryptopp -o $@

.PHONY : clean
clean :
	rm $(TARGET)