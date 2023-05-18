
Compile the program by executing the following command:

gcc -o circle circle.c -lm

The -lm option is used to link the math library explicitly.

Run the program by executing the following command

circle


The circle will be displayed in the CMD window.
By adding the -lm option during compilation, the math library will be linked, and the "undefined reference to `pow'" error should be resolved.

Make sure you have the GCC compiler installed and added to your system's PATH environment variable. Adjust the compilation and execution commands as needed based on your specific development environment.