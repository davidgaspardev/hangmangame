CC=gcc

DIR_BIN=bin
DIR_BUILD=build

all: setup main.o
	$(CC) $(DIR_BUILD)/main.o -o $(DIR_BIN)/hangmangame
	./$(DIR_BIN)/hangmangame

main.o:
	$(CC) -c main.c -o $(DIR_BUILD)/main.o

setup:
	@mkdir -p $(DIR_BIN)
	@mkdir -p $(DIR_BUILD)

clean:
	@rm -rf $(DIR_BIN)
	@rm -rf $(DIR_BUILD)