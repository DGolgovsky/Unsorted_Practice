/**
 * Author: http://HelloACM.com
 * http://CodingForSpeed.com
 */

#include <stdio.h>
#include <unistd.h> // for usleep function

const char rocket[] =
        "            _\n\
           /^\\\n\
           |-|\n\
           | |\n\
           |N|\n\
           |A|\n\
           |S|\n\
           |A|\n\
          /| |\\\n\
         / | | \\\n\
        |  | |  |\n\
         `-\"\"\"-`\n\
";

int main() {
    for (int i = 0; i < 50; i++)
        printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i++) {
        usleep(j); // move faster and faster,
        j = (int) (j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    printf("Visit http://HelloACM.com !\n");
    return 0;
}

