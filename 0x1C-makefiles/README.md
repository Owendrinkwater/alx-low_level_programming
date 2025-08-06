0x1C. Makefiles
This directory contains practice files for learning how to use Makefiles in C programming, as part of the ALX Software Engineering curriculum.

🛠️ What is a Makefile?
A Makefile is a special file used to automate the build process of a program. It defines a set of rules that tell the make command how to compile and link the program.

Instead of compiling your .c files manually every time, you can write a Makefile to do it for you efficiently — only recompiling files that have changed.

📂 Files
File	Description
0-Makefile	First simple Makefile without variables. Compiles main.c and school.c into the school executable using a rule called all.
1-Makefile	Adds some complexity with clean and recompile rules.
2-Makefile	Introduces variables (CC, SRC, OBJ, NAME) and ensures only updated .c files are recompiled.
...	Other tasks that improve efficiency and structure of Makefiles (up to 5-Makefile or more).

🧪 How to Use
To compile the project using a specific Makefile:

bash
Copy
Edit
make -f 0-Makefile
This will run the commands defined in 0-Makefile and create an executable named school.

🔧 Variables Commonly Used
CC — the compiler (usually gcc)

SRC — the source .c files

OBJ — the object .o files

NAME — the name of the output file

💡 Key Concepts
Rule: Describes how to build a target.

Target: Usually the executable or object file you want to create.

Dependencies: Files that the target depends on (like .c files).

Commands: Shell commands that are run to build the target.

Phony Targets: Not real files — like clean or all.

📚 Example Rule
makefile
Copy
Edit
all:
	gcc main.c school.c -o school
This tells make that the all rule compiles the .c files into the school executable.

🧹 Cleaning Up
Many Makefiles include a clean rule to delete compiled files:

makefile
Copy
Edit
clean:
	rm -f *.o school
Then run:

bash
Copy
Edit
make clean
👨‍💻 Author
Owen Owade

Project part of ALX Software Engineering program


