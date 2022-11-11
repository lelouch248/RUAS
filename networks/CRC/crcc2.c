#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define poly_len strlen(gen_poly)

char data[64], rem[32];
char gen_poly[] = " ";
char poly8[] = "100000111", poly10[] = "11000110101";
char poly16[] = "10001000000100001",
     poly32[] = "100000100110000010001110110110111";
int data_len, i, j, e, c, ch;

void chooseGeneratingPolynomial()
{
    printf("\nPress 1 for CRC-8 "
           "\nPress 2 for CRC-10 "
           "\nPress 3 for CRC-16 "
           "\nPress 4 for CRC-32 \nChoice :");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        strcpy(gen_poly, poly8);
        break;
    case 2:
        strcpy(gen_poly, poly10);
        break;
    case 3:
        strcpy(gen_poly, poly16);
        break;
    case 4:
        strcpy(gen_poly, poly32);
        break;
    default:
        printf("Invalid choice");
    }

    printf("\nGenerating polynomial is : %s", gen_poly);
}

void xor () {
    for (c = 1; c < poly_len; c++)
        rem[c] = ((rem[c] == gen_poly[c]) ? '0' : '1');
} 

void remCal()
{
    for (e = 0; e < poly_len; e++)
        rem[e] = data[e];
    do
    {
        if (rem[0] == '1')
            xor();
        for (c = 0; c < poly_len - 1; c++)
            rem[c] = rem[c + 1];
        rem[c] = data[e++];
    } while (e <= data_len + poly_len - 1);
}

void sender()
{
    data_len = strlen(data);
    for (i = data_len; i < data_len + poly_len - 1; i++)
        data[i] = '0';
    printf("\n\nModified data is: %s", data);
    remCal();
    printf("\n\nremainder is: %s", rem);
    for (i = data_len; i < data_len + poly_len - 1; i++)
        data[i] = rem[i - data_len];
    printf("\n\nFinal codeword being transmitted is: %s", data);
}

int checkError()
{
    remCal();
    printf("the remainder is  %s there fore there is an error in the received data. \n", rem);
    for (i = 0; (i < poly_len - 1) && (rem[i] != '1'); i++)
        ;
    if (i < poly_len - 1)
        printf("\nError detected, data processing aborted!!\n\n");
    else
        printf("\no error detected, proceed to data processing\n\n");
    return 0;
}

void receiver()
{
    printf("\nCode received!!\nPress 0 to detect error"
           "InPress 1 co introduce errors: ");
    scanf("%d", &i);
    if (i == 0)
        checkError();
    else if (i == 1)
    {
        do
        {
            printf("\n\nEnter the position where error is to be inserted : ");
            scanf("%d", &i);
            data[i - 1] = (data[i - 1] == '0') ? '1' : '0';
            printf("\nPress 1 to introduce more errors"
                   "\nPress 0 to continue\noption:");
            scanf("%d", &ch);
        } while (ch == 1);

        printf("\nData at receiver: %s\n", data);
        checkError();
    }
    else
        printf("Invalid option");
}
int main(int argc, char **argv)
{
    int data_size;
    printf("Enter data size (max 32 bits): ");
    scanf("%d", &data_size);
    printf("\nEnter the %d-bit data : ", data_size);
    scanf("%s", data);
    chooseGeneratingPolynomial();
    sender();
    receiver();
    return (EXIT_SUCCESS);
}