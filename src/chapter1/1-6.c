#include <stdio.h>

void exercise_1_6()
{
    printf("Try typing some text now and press enter, you should get 1\n");
    printf("Then run the program again and type ctr-d (UNIX) or ctr-z (Windows)\n");
    printf("value of expression: %d", getchar() != EOF);
}

// NOTE: On Windows machines EOF is ctr+z while on UNIX like machines it is ctrl+d