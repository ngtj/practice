
# define macros
CC = g++ 
OLEVEL = -O0
CFLAGS = $(OLEVEL) -g -W
LDFLAGS =
INCLUDES = -I/usr/local/include
LIBS = 

TARGET = sample.exe
OBJS = sample/main.o

# .phony
.PHONY = all clean run

# define generate rules
all: $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm $(TARGET) $(OBJS) 

new: clean all

# suffix rules
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# shell
run:
	./$(TARGET)
