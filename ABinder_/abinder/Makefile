NAME=abinder

PWD=$(shell pwd)
KDIR=/lib/modules/$(shell uname -r)/build
obj-m += ${NAME}.o

default:
	make -C $(KDIR) M=$(PWD) modules 
clean: 
	make -C $(KDIR) M=$(PWD) clean 
	rm -f Module.symvers modules.order 
	rm -f ${NAME}.o ${NAME}.mod ${NAME}.mod.c ${NAME}.mod.o
fclean: clean 
	rm -f ${NAME}.ko 

re: fclean all
