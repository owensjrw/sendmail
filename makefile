## If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

###
.POSIX:

CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

OBJ = sendmailwithpy.o

.SUFFIXES:
.SUFFIXES: .c .o

sendmailwithpy: $(OBJ)
	@echo Linking
	$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo Cleaning
	make clean

.c:
	@echo Compiling $@
	$(CC) $(CFLAGS) -c -o $@ $<

memcheck: *.c
	@echo Compiling with ASANFLAGS $@
	$(CC) $(CFLAGS) $(ASANFLAGS) -o $@ $<

clean:
	rm -rf *.o
