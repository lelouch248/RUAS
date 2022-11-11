#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
int i,j, row, column, count=0;
int Sent_data_bit[10] [10];

printf("Enter number of rows: "); 
scanf("%d", &row);
printf("Enter number of columns: ");
scanf("%d", &column);
printf("Enter the bit stream: \n");

for(j=0;j<row; j++) {
    for (i=0;i<column;i++) {
        scanf("%d", &Sent_data_bit[j] [i]);
    }
}

printf("initial bit stream is: ");

for (j=0;j<row; j++) {
    for (i=0;i<column;i++) {
printf("%d \t", Sent_data_bit[j] [i]);
printf("\n");
}
}

count=0;
for(j=0;j<row; j++){
    for (i=0;i<column;i++){
        if (Sent_data_bit[j] [i]==1)
            count++;
    }
if (count%2==0)
    Sent_data_bit[j] [column]=0;
else
    Sent_data_bit[j] [column]=1;
    count=0;
}

for (i=0;i<=column;i++){
    for(j=0;j<row; j++) {
        if (Sent_data_bit[j] [i]==1) 
            count++;
}
if (count%2==0)
    Sent_data_bit[row] [i]=0;
else
    Sent_data_bit[row] [i]=1;
    count=0;
}

printf("Output bit stream is: \n");
for(j=0;j<=row; j++) {
    for (i=0;i<=column;i++) {
        printf("%d", Sent_data_bit[j] [i]);
}
printf("\n"); 
}

return (EXIT_SUCCESS);
}