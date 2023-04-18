CC = cc -c
CFLAGS =
LINKEAR  = cc


all: fameChecker.c

# prompt: prompt.o
# 	$(CC) $(CFLAGS) -o prompt prompt.o hashtable.o

# prompt.o: hashtable
# 	$(CC) $(CFLAGS) -c prompt.c

# hashtable: hashtable.o
# 	$(CC) $(CFLAGS) -c hashtable.c hashtable.h

# hashtable.o:
# 	$(CC) $(CFLAGS) -o hashtable hashtable.h

OBJETOS  =  directorySearch.o fameChecker.o 

fameChecker: $(OBJETOS)
	$(LINKEAR) $(OBJETOS) -o fameChecker

fameChecker.o: fameChecker.c
	$(CC) fameChecker.c -o fameChecker.o

directorySearch.o : directorySearch.c
	$(CC) directorySearch.c -o directorySearch.o

all: fameChecker

clean:
	rm *.o