TARGET = main
SOURCE = main.c dictionary.c
CFLAGS = -g -Wall
LIBS = -lm
CC = gcc

all: $(TARGET)

$(TARGET): $(OBJF)
	$(CC) $(SOURCE) -o $(TARGET) $(OBJF) $(LIBS)

clean:
	rm -f $(OBJF)
