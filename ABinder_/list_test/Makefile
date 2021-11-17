TARGET = list
SOURCES = list.c

OBJECTS = $(SOURCES:.c=.o)
CC = gcc
##################################

default : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -c -o ${CFLAGS} $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET)

