
CFLAGS = -g

OBJ = hash.o main.o table.o
HDR = hash.h table.h
BIN = hash

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

$(OBJ): $(HDR)
