all: clear compile run clean 

compile: main.c util.c util.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c util.c -lm

run:
	
	@echo "================================================================================="
	./test
	@echo "================================================================================="


clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f test

clear:
	@clear

debug: main.c util.c util.h
	@gcc -o test -g main.c util.c -lm
	@gdb test