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
    char numberArr[9][7] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
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
            else if (open == 1 && isdigit(input[i]))
            {
                end = input[i] - 48;
            }
            else if (open == 0)
            {
                for (int j = 0; j < 9; j++)
                {
                    int truthy = 1;
                    for (int k = 0; k < strlen(numberArr[j]); k++)
                    {
                        if (numberArr[j][k] != input[i + k])
                        {
                            truthy = 0;
                            break;
                        }
                    }
                    if (truthy == 1)
                    {
                        start = j + 1;
                        end = j + 1;
                        open = 1;
                        break;
                    }
                }
            }
            else if (open == 1)
            {
                for (int j = 0; j < 9; j++)
                {
                    int truthy = 1;
                    for (int k = 0; k < strlen(numberArr[j]); k++)
                    {
                        if (numberArr[j][k] != input[i + k])
                        {
                            truthy = 0;
                            break;
                        }
                    }
                    if (truthy)
                    {
                        end = j + 1;
                        break;
                    }
                }
            }
        }
        count = count + (start * 10 + end);
        start = 0;
        end = 0;
        open = 0;
    }
    printf("%d", count);
    return 0;
}