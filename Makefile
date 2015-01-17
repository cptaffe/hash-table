
CFLAGS = -g --std=c11

OBJ = hash.o table.o dict.o
MAIN = main.o
HDR = hash.h table.h dict.h
BIN = hash
LIB = hash.a

all: $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(MAIN)

lib: $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(OBJ): $(HDR)

clean:
	rm $(BIN) $(LIB) $(OBJ)
