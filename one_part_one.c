#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    fptr = fopen("one.txt", "r");
    char input[1000];
    // fgets(input, 100, fptr);
    int start = 0;
    int end = 0;
    int open = 0;
    int count = 0;
    while (fgets(input, 1000, fptr))
    {
        for (int i = 0; i < strlen(input); i++)
        {
            if (open == 0 && isdigit(input[i]))
            {
                start = input[i] - 48;
                end = input[i] - 48;
                open = 1;
            }
            if (open == 1 && isdigit(input[i]))
            {
                end = input[i] - 48;
            }
        }
        count = count + (start * 10 + end);
        open = 0;
        start = 0;
        end = 0;
    }
    printf("%d", count);
    return 0;
}