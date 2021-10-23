obj-m := my_hello.o

KDIR := /home/chermi/projects/kernel/linux-stable
all:
	$(MAKE) -C $(KDIR) M=$$PWD