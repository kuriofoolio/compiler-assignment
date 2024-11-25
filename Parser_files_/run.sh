# Compile the files by running:-
bash out.sh
flex lexer.l
bison -d parser.y

#The compilation will be automated using a simple MakeFile
#To build the project run
make

#To clean up the files run
#make clean

#Execute the file generated:-
./expression_evaluator


# ive removed expression_evaluator as an argument in rm -f in makefile
