TARGET2 = semp2
SOURCES2 = semp2.c

CLEAN-FILES = $(SOURCES2:.c=.o)
##################################

default : $(TARGET2)

$(TARGET2) : $(SOURCES2:.c=.o)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o ${CFLAGS} $@ $<

clean:
	rm -f $(CLEAN-FILES)


