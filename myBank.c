#include <stdio.h>
#include "myBank.h"
#define AMUDA 50
#define SHURA 2

double bank[AMUDA][SHURA] = {0};

//O
void openAccount()
{
    printf("Please enter amount for deposit:");
    double sum;
    if (scanf("%lf", &sum))
    {
        if (sum < 0)
        {
            printf("Invalid Amount\n");
        }
        else
        {
            int ac = -1;
            for (int i = 0; i < 50; i++)
            {
                if (bank[i][1] == 0)
                {
                    ac = i + 901;
                    bank[i][1] = 1;
                    i = 100;
                }
            }
            if (ac == -1)
            {
                printf("CANT open new account because Max capacity\n");
            }
            else
            {
                bank[ac - 901][0] = sum;
                bank[ac - 901][1] = 1;
                printf("New account number is: %d\n", ac);
            }
        }
    }
    else
    {
        printf("Failed to read the amount\n");
    }
}

//B

void checkAccount()
{
    printf("enter account number \n");
    int number2;
    scanf("%d", &number2);
    if (number2 > 950 || number2 < 901)
    {
        printf("Invalid account number\n");
    }
    else
    {
        if ((bank[number2 - 901][1]) == 1)
        {
            printf("The balance of account number %d is: %.2lf\n", number2, bank[number2 - 901][0]);
        }
        else
        {
            printf("account is not activated\n");
        }
    }
}

//D

void deposit()
{
    printf("enter account number ");
    int number12;
    if (scanf("%d", &number12) == 1)
    {
        if (number12 > 950 || number12 < 901)
        {
            printf("Invalid account number\n");
        }
        else
        {
            if (bank[number12 - 901][1] == 0)
            {
                printf("This account is closed\n");
            }
            else
            {
                printf("Please enter amount for deposit:");
                double sum2;
                if (scanf("%lf", &sum2) == 1)
                {
                    if (sum2 < 0)
                    {
                        printf("Cannot deposit a negative amount\n");
                    }
                    else
                    {
                        bank[number12 - 901][0] += sum2;
                        printf("The new balance is: %.2f \n", bank[number12 - 901][0]);
                    }
                }
                else
                {
                    printf("Failed to read the amount\n");
                }
            }
        }
    }
    else
    {
        printf("Failed to read the account number");
    }
}

//W

void withdrawal()
{
    printf("enter account number: ");
    int accountNum;
    if (scanf("%d", &accountNum) == 1)
    {
        if (accountNum > 950 || accountNum < 901)
        {
            printf("Invalid account number\n");
        }
        else if (bank[accountNum - 901][1] == 0)
        {
            printf("This account is closed\n");
        }
        else
        {
            printf("Please enter the amount to withdraw:");
            double num3;
            scanf("%lf", &num3);
            if (num3 < 0)
            {
                printf("cant minus withdrawal\n");
            }
            else if (bank[accountNum - 901][0] - num3 >= 0)
            {
                bank[accountNum - 901][0] -= num3;
                printf("The new balance is:  %.2lf \n", bank[accountNum - 901][0]);
            }
            else
            {
                printf("cannot withdraw more than the balance \n");
            }
        }
    }
    else
    {
        printf("Failed to read the account number");
    }
}

//C
void close()
{
    printf("enter account number: ");
    int number;
    if (scanf("%d", &number) == 1)
    {
        if (number > 950 || number < 901)
        {
            printf("Invalid account number\n");
        }
        else if (bank[number - 901][1] == 0)
        {
            printf("This account is closed\n");
        }
        else
        {
            if (bank[number - 901][1] == 1)
            {
                bank[number - 901][1] = 0;
                bank[number - 901][0] = 0;
                printf("closed account number %d\n", number);
            }
        }
    }
    else
    {
        printf("Failed to read the account number");
    }
}

//I
void interest_rate()
{
    printf("Please enter interest rate: ");
    float rate;
    if (scanf("%f", &rate) == 1)
    {
        double rateio = 1 + (rate / 100);
        for (int i = 0; i < 50; i++)
        {
            if (bank[i][1] == 1)
            {
                bank[i][0] *= rateio;
            }
        }
    }
    else
    {
        printf("Failed to read the interest rate\n");
    }
}

//P
void PrintAccounts()
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[i][1] == 1)
        {
            printf("The balance of account number  %d is: %.2lf \n", (901 + i), bank[i][0]);
        }
    }
}

//E
void End()
{
    for (int i = 0; i < 50; i++)
    {
        bank[i][1] = 0;
        bank[i][0] = 0;
    }
}