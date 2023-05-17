Compile the code using a C compiler. Assuming you have the GCC compiler installed, you can use the following command:

gcc color_to_bw.c -o color_to_bw

After a successful compilation, run the program using the following command:

./color_to_bw


Make sure you have a color image named "input.bmp" in the same directory as the program.

Once the program finishes running, it will generate a black and white version of the image named "output.bmp" in the same directory.

Note: The code assumes that the input image is in the BMP format and uses 24-bit color depth. Make sure to adjust the code accordingly if you have a different format or color depth.