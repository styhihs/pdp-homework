SRC=main.c

CC=gcc
INC=../include
UTIL=$(INC)/clutil.c
OBJ=$(SRC:.c=.o) $(UTIL:.c=.o)
SRCCL=$(SRC:.c=.cl)
TARGET=$(SRC:.c=)
CFLAG=-lOpenCL -g -I$(INC) -lm

all: $(TARGET)

$(TARGET): $(OBJ) $(SRCCL)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAG)

$(SRC:.c=.o): $(SRC)
	$(CC) -c $(SRC) $(CFLAG)

$(UTIL:.c=.o): $(UTIL)
	$(CC) -c -o $(UTIL:.c=.o) $(UTIL) $(CFLAG)

clean:
	rm -rf $(OBJ) $(TARGET)
