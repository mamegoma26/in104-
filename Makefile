CC = gcc
LIBFLAGS = -shared -fPIC
INCLIBFLAGS = -lcyol -Lbin -Wl,-rpath,bin
SRC = $(shell find src/ -name "*.c")
LIB_OBJ = $(SRC:src/%.c=bin/%.o)

bin/%.o: src/%.c
	@mkdir -p bin
	@echo "Compiling $< ..."
	@$(CC) $(LIBFLAGS) -c $< -o $@

bin/cyol.o: cyol.c
	@mkdir -p bin
	@echo "Compiling main target $< ..."
	@$(CC) -c $< -o $@
bin/libcyol.so: $(LIB_OBJ)
	@mkdir -p bin
	@echo "Linking lib target $@ ..."
	@$(CC) $(LIBFLAGS) -o $@ $^
bin/cyol: bin/cyol.o
	@mkdir -p bin
	@echo "Linking main target $@ ..."
	@$(CC) -o $@ $< $(INCLIBFLAGS)

clean:
	@rm -rf bin/

build: bin/libcyol.so bin/cyol
