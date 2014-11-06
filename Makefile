
CFLAGS = -g

OBJ = hash.o main.o
HDR = hash.h
BIN = hash

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

$(OBJ): $(HDR)
