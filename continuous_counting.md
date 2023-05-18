In this example, the program uses a while loop with the condition while (1) to create an infinite loop. Inside the loop, the current value of the counter variable is printed, and then the counter is incremented by 1.

Compile the program by executing the following command

gcc -o continuous_counting continuous_counting.c


Run the program by executing the following command

continuous_counting


The program will start counting from 0 and continue indefinitely, printing the current count on each iteration. Since this program uses an infinite loop, you can stop it by manually terminating the program (e.g., by pressing Ctrl+C).

Please note that running an infinite loop may consume significant system resources and may not be appropriate in all situations. Make sure to consider the impact and purpose of your program before running such code.