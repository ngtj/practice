# thread/makefile

TARGET = algorithm.exe
OBJS = source/main.o
SRCS = $(subst .o,.cpp,$(OBJS))

# include c++ makefile
include ../makefile.in

ROOTDIR = $(shell pwd)
INCLUDES += -I$(ROOTDIR)

# DO NOT DELETE THIS LINE -- make depend depends on it.

source/main.o: structure/List.h
