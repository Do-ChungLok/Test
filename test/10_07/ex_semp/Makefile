TARGET2 = semp
SOURCES2 = semp.c

CLEAN-FILES = $(SOURCES2:.c=.o)
##################################

default : $(TARGET2)

$(TARGET2) : $(SOURCES2:.c=.o)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o ${CFLAGS} $@ $<

clean:
	rm -f $(TARGET2) $(CLEAN-FILES)


