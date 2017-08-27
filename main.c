#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 16000

int num1[MAX_SIZE],num2[MAX_SIZE],sum[MAX_SIZE];
int *memoryBuff;
long long totlen=0;
void fixZero(int []);
int multiplyThis();
int length(int );
int lengthArray(int []);
void populateArray(int ,int []);
void multiply();
void adder();
void printArray(int []);

int main(){
    int number,i,t;
    long long length;
    printf("enter no of test cases: ");
    scanf("%d",&t);
while(t--){
    printf("enter number to find  fact: ");
    scanf("%d",&number);
    populateArray(1,num1);
    for(i=1;i<=number;i++){
        populateArray(i,num2);
        multiplyThis();
        fixZero(num1);
    }
    //printf("the factorial is:\n");
    //printf("\n\ndigits long: %d\n",printArray(num1));
    printArray(num1);
    printf("\nlength: %d\n",lengthArray(num1));
    printf("\n");
}
    return 0;
}
int multiplyThis()
{
    totlen=0;
    totlen+=lengthArray(num1);
    totlen+=lengthArray(num2);
    memoryBuff=malloc(sizeof(int)*lengthArray(num2)*totlen);
    multiply();
    free(memoryBuff);
    return 0;
}
int length(int number){
    int counter=0;
    while(number){
        counter++;
        number/=10;
    }
    return counter;
}
int lengthArray(int array[]){
    long long i=0;
    while(array[i]!='\0'){
        i++;
    }
    return i;
}
void populateArray(int source,int array[]){
    int i=0,remainder,pos=length(source)-1;
    for(i=0;source>0;i++){
        remainder=source%10;
        source/=10;
        array[pos--]=remainder+'0';
    }
    array[i]='\0';
}
void multiply(){
    int len1=lengthArray(num1),len2=lengthArray(num2);
    int i,j,k,p,q;
    for(j=len2-1;j>=0;j--){
        //leading zero
        for(p=0;p<j;p++){
            memoryBuff[k++]='0';
        }
        for(i=0;i<=len1-1;i++){
            memoryBuff[k++]=((num1[i]-'0')*(num2[j]-'0'))+'0';
        }
        //trailing zero
        for(p=len2-1-j;p>0;p--){
            memoryBuff[k++]='0';
        }
    }
    memoryBuff[k]='\0';
    adder();
}
void adder(){
    int k,i,j,adder,size=lengthArray(num2),carry,loopCounter,pos=0;
    carry=0;
    for(k=totlen-2;k>=0;k--){
        adder=carry;
        loopCounter=0;
        for(i=k;loopCounter<size;i+=(totlen-1)){
            loopCounter++;
            adder+=memoryBuff[i]-'0';
        }
        carry=adder/10;
        sum[pos++]=adder%10;
    }
    sum[pos++]=carry;
    loopCounter=0;
//value of num1 is changed here,, stores the last product
    num1[pos]='\0';
    k=pos;
    for(i=0;i<pos;i++){
        num1[i]=sum[--k]+'0';
    }
}
void printArray(int array[]){
    int size=lengthArray(array),i,counter=0;
    //printf("\n");
    for(i=0;i<size;i++){
        counter++;
        printf("%d",array[i]-'0');
        if(counter%3==0){
            printf(" ");
            counter=0;
        }
    }
}
void fixZero(int array[]){
    int i,len=lengthArray(array);
    int jump=0;
    for(i=0;i<len;i++){
        if(array[i]!='0')
            break;
    }
    jump=i;
    for(i;i<len;i++){
        num1[i-jump]=num1[i];
    }
    num1[i-jump]='\0';
}
