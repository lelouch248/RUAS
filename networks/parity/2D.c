#include <stdio.h>

void main()
{
    int i, j, sent[30][30], row, column, count;
    int received[30][30], error;
    int error_row, error_col;
    /* accepting user data */
    printf("enter the number of rows and column:");
    scanf("%d %d", &row, &column);

    printf("enter the data that needs to be sent: \n ");
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            scanf("%d", &sent[i][j]);

    printf("displaying the array of bits \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            printf("%d \t", sent[i][j]);
        printf("\n");
    }

    for (i = 0; i < row; i++)
    {
        count = 0;
        for (j = 0; j < column; j++)
            if (sent[i][j] == 1)
                count++;
        if (count % 2 == 0)
            sent[i][column] = 0;
        else
            sent[i][column] = 1;
    }

    for (j = 0; j <= column; j++)
    {
        count = 0;
        for (i = 0; i < row; i++)
            if (sent[i][j] == 1)
                count++;
        if (count % 2 == 0)
            sent[row][j] = 0;
        else
            sent[row][j] = 1;
    }
    printf("displaying the array of bits after adding the parity \n");
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= column; j++)
        {
            printf("%d \t", sent[i][j]);
        }
        printf("\n");
    }

    /*received data bit processing */
    /*receiving the data */
    printf("enter the received bits: \n ");
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= column; j++)
        {
            scanf("%d", &received[i][j]);
        }
    }

    int received_modfied[30][30];

    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= column; j++)
        {
            received_modfied[i][j] = received[i][j];
        }
    }

    for (i = 0; i < row; i++)
    {
        count = 0;
        for (j = 0; j < column; j++)
            if (received[i][j] == 1)
                count++;
        if (count % 2 == 0)
            received_modfied[i][column] = 0;
        else
            received_modfied[i][column] = 1;
    }

    for (j = 0; j < column; j++)
    {
        count = 0;
        for (i = 0; i < row; i++)
            if (received[i][j] == 1)
                count++;
        if (count % 2 == 0)
            received_modfied[row][j] = 0;
        else
            received[row][j] = 1;
    }

    for (i = 0; i <= row; i++)
    {
        if (received[i][column] != received_modfied[i][column])
        {
            error_row = i;
            printf("error in row number %d \n", i);
            error = 1;
            break;
        }
    }

    for (j = 0; j <= column; j++)
    {
        if (received[row][j] != received_modfied[row][j])
        {
            error_col = j;
            printf("error in column number %d \n", j);
            error = 1;
            break;
        }
    }

    if (error != 1)
    {
        printf("no error found in the received data \n");
    }
    else
    {
        printf("error found in the received data \n");
        printf("error was found in the %d row and %d column which will correspond to the data %d \n", 
        error_row, error_col, received[error_row][error_col]);
    }
}