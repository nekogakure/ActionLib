CC = gcc
CFLAGS = -Wall
OBJ = catLog_test.o catLog.o
EXEC = catLog

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

catLog_test.o: catLog_test.c ../../include/catLog.h
	$(CC) $(CFLAGS) -c catLog_test.c

catLog.o: ../../bin/catLog.c ../../include/catLog.h
	$(CC) $(CFLAGS) -c ../../bin/catLog.c

clear:
	rm -f $(OBJ) $(EXEC)
