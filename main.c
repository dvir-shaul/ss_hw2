#include <stdio.h>
#include "myBank.c"
void printAcc()
{
    printf("Please choose a transaction type:\n");
    printf("O-Open Account\n");
    printf("B-Balance Inquiry\n");
    printf("D-Deposit\n");
    printf("W-Withdrawal\n");
    printf("C-Close Account\n");
    printf("I-Interest\n");
    printf("P-Print\n");
    printf("E-Exit\n");
}
int main()
{
    char acction;
    printAcc();
    scanf("%c", &acction);
    while (acction != 'E')
    {
        switch (acction)
        {
        case 'O':
            openAccount();
            break;

        case 'B':
            checkAccount();
            break;

        case 'D':
            deposit();
            break;

        case 'W':
            withdrawal();
            break;

        case 'C':
            close();
            break;

        case 'I':
            interest_rate();
            break;

        case 'P':
            PrintAccounts();
            break;

        default:
            printf("Invalid transaction type\n");
            break;
        }
        printf("\n");
        printAcc();
        scanf(" %c", &acction);
    }
    printf("\n");
    End();

    return 0;
}