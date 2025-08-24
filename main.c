// Including libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Intialising variables
int guesses = 0;
char str[100] = "";
struct data
{
    int len;
    char inp[99];
};
struct data values;
char check_1;

// Functions
void print_man(int guess)
{
    if (guess == 1)
    {
        printf("*******************\n");
        for (int i = 0; i < 3; i++)
        {
            printf("         *\n");
        }
    }
    if (guess == 2)
    {
        printf("*******************\n");
        for (int i = 0; i < 3; i++)
        {
            printf("         *\n");
        }
        printf("        ***\n       *   *\n       *   *\n       *   *\n        ***\n");
    }
    if (guess == 3)
    {
        printf("*******************\n");
        for (int i = 0; i < 3; i++)
        {
            printf("         *\n");
        }
        printf("        ***\n       *   *\n       *   *\n       *   *\n        ***\n");
        for (int i = 0; i < 5; i++)
        {
            printf("         *\n");
        }
    }
    if (guess == 4)
    {
        printf("*******************\n");
        for (int i = 0; i < 3; i++)
        {
            printf("         *\n");
        }
        printf("        ***\n       *   *\n       *   *\n       *   *\n        ***\n");
        printf("         *\n");
        printf("       * * *\n");
        printf("      *  *  *\n");
        printf("     *   *   *\n");
        printf("         *\n");
    }
    if (guess == 5)
    {
        printf("*******************\n");
        for (int i = 0; i < 3; i++)
        {
            printf("         *\n");
        }
        printf("        ***\n       *   *\n       *   *\n       *   *\n        ***\n");
        printf("         *\n");
        printf("       * * *\n");
        printf("      *  *  *\n");
        printf("     *   *   *\n");
        printf("         *\n");
        printf("        * *\n");
        printf("       *   *\n");
        printf("      *     *\n");
        printf("     *       *\n");
        printf("    *         *\n");
        printf("You Lost!!");
        printf("The word was %s",values.inp);
    }
}

struct data intro()
{
    printf("Player 1 give the word (Word Limit is [5-9]) ----> ");
    char input[99];
    scanf("%s", input);
    for (int i = 0; i < 20; i++)
    {
        printf("\n");
    }
    for (int i = 0; input[i]; i++)
    {
        input[i] = tolower(input[i]);
    }
    int length = strlen(input);
    if (length > 9 || length < 5)
    {
        printf("Word limit is [5-9]. Try again.\n");
        intro();
    }
    else
    {
        printf("The word has %d letters\n", length);
        strcpy(values.inp, input);
        values.len = length;
        return values;
    }
}

void print_string()
{
    for (int i = 0; i < values.len; i++)
    {
        str[i] = '_';
    }
    str[values.len] = '\0';
    printf("%s", str);
}

int check(struct data values, char check_1)
{
    while (1)
    {
        char t_f = 'f';
        if (guesses == 5 || strcmp(str, values.inp) == 0)
        {
            break;
        }
        else
        {
            printf("\nPlayer 2 enter a letter ----> ");
            scanf(" %c", &check_1);
            check_1 = tolower(check_1);

            for (int i = 0; i < values.len; i++)
            {
                if (check_1 == values.inp[i])
                {
                    str[i] = values.inp[i];
                    t_f = 't';
                }
            }
            printf("%s\n", str);
            if (t_f == 'f')
            {
                guesses++;
                print_man(guesses);
                check(values, check_1);
            }
        }
    }      
}

// Main function starts from here
int main()
{
    intro();
    print_string();
    check(values, check_1);
    if (strcmp(str,values.inp)==0)
    {
        printf("You Won!!");
    }    
    return 0;
}