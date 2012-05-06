# memory/makefile

TESTLIBS = $(GTEST_DIR)make/gtest_main.a
TEST_INCLUDES = -I$(GTEST_DIR)include 

LIB_OBJS = Memory/Manager.o

# sample
OBJS = $(LIB_OBJS) sample/main.o
TARGET = sample.exe

# test
ifdef TEST_MODE
OBJS = $(LIB_OBJS) \
	   Test/MemoryManager.o
TARGET = test.exe
endif

SRCS = $(subst .o,.cpp,$(OBJS))

# include c++ makefile
include ../makefile.in

ROOTDIR = $(shell pwd)
INCLUDES += -I$(ROOTDIR)

# DO NOT DELETE THIS LINE -- make depend depends on it.
