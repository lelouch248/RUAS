#include <stdio.h>
void main()
{
    int sent[30], received[30], length, parity_sent, parity_received, i;
    int counter;

    printf("enter the length of the data\n");
    scanf("%d", &length);

    printf("enter the sent data with a space\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &sent[i]);
    }

    /*parity check for the received data*/
    for (i = 0; i < length; i++)
    {
        if (sent[i] == 1)
        {
            counter++;
        }
    }
    if (counter % 2 == 0)
    {
        printf("even parity\n");
        parity_sent = 0;
    }
    else
    {
        printf("odd parity\n");
        parity_sent = 1;
    }
    printf("displaying the sent array \n  ");
    for (i = 0; i < length; i++)
    {
        printf("%d ", sent[i]);
    }
    printf("%d \n ", parity_sent);

    /* received data from the user*/
    printf("enter the received data with a space\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &received[i]);
    }
    counter = 0;

    for (i = 0; i < length; i++)
    {

        if (received[i] == 1)
        {
            counter++;
        }
    }
    if (counter % 2 == 0)
    {
        printf("even parity\n");
        parity_received = 0;
    }
    else
    {
        printf("odd parity\n");
        parity_received = 1;
    }

    if (parity_sent == parity_received)
    {
        printf("there is no error in the received data ");
    }
    else
    {
        printf("there is error in the received data");
    }
}
