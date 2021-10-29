TARGET1 = mmap
SOURCES1 = mmap.c

CLEAN-FILES = $(SOURCES1:.c=.o)
##################################

default : $(TARGET1)

$(TARGET1) : $(SOURCES1:.c=.o)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o ${CFLAGS} $@ $<

clean:
	rm -f $(TARGET1) $(CLEAN-FILES)


