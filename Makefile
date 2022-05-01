default:
	mkdir -p bin
	rm -rf bin/*
	gcc -c src/lexer.c -o bin/lexer.o
	gcc cyol.c bin/lexer.o -o bin/cyol