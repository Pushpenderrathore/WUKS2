CC = gcc
 CFLAGS = -Wall -Iinclude 
LIBS = -lssl -lcrypto 

all: test

test: src/core/encryption.c tests/test_encryption.c
    $(CC) $(CFLAGS) -o test_enc tests/test_encryption.c src/core/encryption.c $(LIBS) 

clean:
    rm -f test_enc 
