#include <stdio.h>

int main(void)
{
    unsigned int space_count = 0;
    unsigned int tab_count = 0;
    unsigned int endl_count = 0;
    unsigned int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            tab_count++;
        else if (c == '\n')
            endl_count++;
        else
            space_count++;
    }
    
    printf("Spaces: %d\nTabs: %d\nEnd line: %d\n",
            space_count, tab_count, endl_count);

    return 0;
}
