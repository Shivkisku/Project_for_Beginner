#include <stdio.h>
#include <stdarg.h>

void say(const char* format, ...) {
    va_list args;
    va_start(args, format);
    
    vprintf(format, args);

    va_end(args);
}

int main() {
    say("Hello, %s!\n", "world");
    say("The answer is %d.\n", 42);
    say("The value of Pi is %.2f.\n", 3.14);

    return 0;
}
