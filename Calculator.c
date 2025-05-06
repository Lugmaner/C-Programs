#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int z = 0;
    char YesNo;
    int MaxStored = 10;
    char operator;
    double* oldResults = malloc(MaxStored * sizeof(double));
    double num1, num2;
    bool isFull = false;

    for (int i = 0; i < MaxStored; i++)
    {
        printf("Do you want to list all saved results or clear a specific register? y, n or c for clear\n");
        scanf(" %c", &YesNo); 

        switch (YesNo)
        {
            case 'y':
            case 'Y':
                for (int j = 0; j < MaxStored; j++)
                {
                    if (oldResults[j] >= 0)
                        printf("    Result %d:  %lf\n", j + 1, oldResults[j]);
                    else
                        printf("    Result %d: %lf\n", j + 1, oldResults[j]);
                }
                break;
            case 'n':
            case 'N':
                printf("no list wanted\n");
                break;
            case 'c':
            case 'C':
                int delnum;
                double savefirst;
                double savelast;
                printf(" Which register do you want to delete?\n");
                scanf(" %d", &delnum);
                if (delnum < 1 || delnum > MaxStored)
                    {
                        printf("Invalid register number.\n");
                        break;
                    }
                else
                {
                    oldResults[delnum-1]=-0.000000;
                    for (int j = delnum-1; j < MaxStored-1; j++)
                        {
                            oldResults[j] = oldResults[j+1];
                        }
                    oldResults[MaxStored - 1] = -0.000000;
                    i--; // Damit gelöschter Slot wiederverwendet werden kann
                    if (i >= 0) {
                        oldResults[i] = -0.000000; // oder ein Markerwert
                    }
                    printf("Register %d has been deleted\n", delnum);
                    
                }
            default:
                printf("'%c' is not valid\n", YesNo);
                
        }

        if (i == MaxStored - 1)
            isFull = true;
        else
            isFull = false;

        printf("enter an operator ( + - * /): ");
        scanf(" %c", &operator);

        printf("enter the first number: ");
        scanf("%lf", &num1);

        printf("enter the second number: ");
        scanf("%lf", &num2);

        switch (operator)
        {
            case '+':
                oldResults[i] = num1 + num2;
                printf("result: %lf\n", oldResults[i]);
                fflush(stdout);
                break;
            case '-':
                oldResults[i] = num1 - num2;
                printf("result: %lf\n", oldResults[i]);
                fflush(stdout);
                break;
            case '*':
                oldResults[i] = num1 * num2;
                printf("result: %lf\n", oldResults[i]);
                fflush(stdout);
                break;
            case '/':
                if (num2 != 0)
                {
                    oldResults[i] = num1 / num2;
                    printf("result: %lf\n", oldResults[i]);
                }
                else
                {
                    printf("Division by zero is not allowed.\n");
                    oldResults[i] = 0;
                }
                fflush(stdout);
                break;
            default:
                printf("'%c' is not valid\n", operator);
                break;
        }

        while (z != 1)
        {
            printf("Do you want to continue? (y/n): ");
            scanf(" %c", &YesNo);

            if (YesNo == 'y' || YesNo == 'Y')
            {
                printf("Next calculation\n");
                z = 1;
            }
            else if (YesNo == 'n' || YesNo == 'N')
            {
                z = 1;
                break;
            }
        }

        z = 0;

        if (YesNo == 'n' || YesNo == 'N')
        {
            break;
        }
    }

    if (isFull == true)
    {
        printf("Storage is full; list of results:\n");
    }
    else
    {
        printf("List of results:\n");
    }

    for (int i = 0; i < MaxStored; i++)
    {
        if (oldResults[i] >= 0)
            printf("    Result %d:  %lf\n", i + 1, oldResults[i]);
        else
            printf("    Result %d: %lf\n", i + 1, oldResults[i]);
    }

    free(oldResults);
    return 0;
}
