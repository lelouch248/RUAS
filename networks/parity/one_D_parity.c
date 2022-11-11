#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main (){ 
    
int Counter_1,Counter,Parity,i,j,size,received_data[50],Parity_1;
int sent_data_bit[50]; 

//size of the array
printf("Enter the size of bit stream:\n"); 
scanf("%d",&size);

//data bit is given as input
printf("Enter the bit stream:\n");  
for(i=0;i<size;i++){
scanf("%d",&sent_data_bit[i]);
}

//representing the entered data bits
printf("Input the bit stream is: "); 
for(i=0;i<size;i++)
{   
    printf("%d ",sent_data_bit[i]);
}

//counting the number of bits
for(i=0;i<size;i++)                 
{        
    if (sent_data_bit[i]==1){
     Counter++;
    }
}

//if the counter is multliple of 2 then it is even parity
if(Counter%2==0){    
       printf("\n Even Parity "); 
       Parity=0;
} 

else {        //if the counter is not a multliple of 2 then it is even parity
       printf("\n Odd Parity "); 
       Parity=1;
}
printf("\n Thus the Parity bit is %d\n",Parity); //parity bit
printf("The final bit stream is\n");     //final bit stream
       
for(i=0;i<size;i++){   
    printf("%d",sent_data_bit[i]);
}

printf("%d \n",Parity);

printf("Enter the received data bit stream:\n"); 
for(j=0;j<size;j++){
scanf("%d",&received_data[j]);
}
for(j=0;j<size;j++)                 //counting the number of bits
{        
    if (received_data[j]==1){
     Counter_1++;
    }
}

if(Counter_1%2==0){    //if the counter is multliple of 2 then it is even parity
       printf("\n Even Parity "); 
       Parity_1=0;
} 

else {        //if the counter is not a multliple of 2 then it is even parity
       printf("\n Odd Parity "); 
       Parity_1=1;
}

if (Parity==Parity_1)
printf("data sent is matched with the sent one");
else
printf("data sent is not matched with the sent one"); 
}