




_help:
	@echo "make all     :  compile all subdirs"
	@echo "make 1/      :  compile all subdir in 1_/"
	@echo "make 1.1     :  compile 1_/1_1.cpp"
	@echo 
	@echo "make clean   :  clean object files in all subdirs"


SUBDIRS = $(wildcard *_)

.PHONY: all $(SUBDIRS)

all clean:
	@for dir in $(SUBDIRS); do \
		make -C $$dir $@; done

%/:
	@make -C $(patsubst %/,%_/,$@) all

%:
	@target=`echo $@ | sed -ne "s:\([0-9]\+\)\.\([0-9]\+\):\1_ \1_\2:p"`; \
		   [ -n "$$target" ] && make -C $$target


