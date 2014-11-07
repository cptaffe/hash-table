
CFLAGS = -g

OBJ = hash.o main.o table.o dict.o
HDR = hash.h table.h dict.h
BIN = hash

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

$(OBJ): $(HDR)
