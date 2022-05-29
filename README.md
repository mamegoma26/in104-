# in104-
cyol means Create Your Own Language
cyol.c is the main file where we call all the functions 
biblio is a file with the grammar of our language
the file lexer.h does the function of a lexer, it read an open source file(with read_entry) and tokenize it(with the function tokenize);it calls severals functions from the file token.c
the parser.h has to build the AST(the function parse) and displays it(with the function display); it calls severals functions from the file ast.c
binder.c is the begening of the interpreter, but it's not finish
number_program.cyol is a small text to test the lexer
To run the programm you need to execute : make build clean, and bin/cyol resources/number_program.cyol in a terminal
you could have some errors due to the fact that the interprerter is not finish
