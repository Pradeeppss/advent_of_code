#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    char input[10000];
    fptr = fopen("two.txt", "r");
    int id = 0;
    int total = 0;
    int totalPower = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    while (fgets(input, 10000, fptr))
    {
        int truthy = 0;
        int started = 0;
        int temp = 0;
        int number = 0;
        int maxRed = 0;
        int maxBlue = 0;
        int maxGreen = 0;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!started && isdigit(input[i]))
            {
                temp = temp * 10 + input[i] - 48;
            }
            if (input[i] == ':')
            {
                id = temp;
                temp = 0;
                started = 1;
            }
            if (started && isdigit(input[i]))
            {
                temp = temp * 10 + input[i] - 48;
                number = 1;
            }
            else if (started && number == 1 && input[i] == ' ')
            {
                if (input[i + 1] == 'r')
                {
                    red = temp;
                    temp = 0;
                    number = 0;
                    if (red > 12)
                    {
                        truthy = 1;
                        break;
                    }
                    if (red > maxRed)
                    {
                        maxRed = red;
                    }
                }
                else if (input[i + 1] == 'b')
                {
                    blue = temp;
                    temp = 0;
                    number = 0;
                    if (blue > 14)
                    {
                        truthy = 1;
                        break;
                    }
                    if (blue > maxBlue)
                    {
                        maxBlue = blue;
                    }
                }
                else if (input[i + 1] == 'g')
                {
                    green = temp;
                    temp = 0;
                    number = 0;
                    if (green > 13)
                    {
                        truthy = 1;
                        break;
                    }
                    if (green > maxGreen)
                    {
                        maxGreen = green;
                    }
                }
            }
        }
        int power = maxBlue * maxGreen * maxRed;
        printf("power %d", power);
        totalPower = totalPower + power;
        printf("%d , truthy - %d\n", id, truthy);
        if (truthy == 0)
        {
            total = total + id;
        }
    }
    printf("%d\n", total);
    printf("%d", totalPower);
    return 0;
}