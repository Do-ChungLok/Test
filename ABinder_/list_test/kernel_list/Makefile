NAME=list

PWD=$(shell pwd)
KDIR=/lib/modules/$(shell uname -r)/build
obj-m += ${NAME}.o

default:
	make -C $(KDIR) M=$(PWD) modules 

clean: 
	make -C $(KDIR) M=$(PWD) clean 

fclean: clean 
	rm -f ${NAME}.ko 

re: fclean all

insmod:
	insmod ${NAME}.ko
	chmod a+rw /dev/${NAME}

# 드라이버를 컴파일 & 테스트 하기 위해 필요한 최소한 ubuntu package 관련 설치
prepare:
	if [[ `dpkg -l | grep -c kmod` = 0 ]]; then apt-get install --yes kmod; fi
	apt-get install --yes linux-headers-`uname -r`
	
	
