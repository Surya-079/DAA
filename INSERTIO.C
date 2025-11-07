#include<stdio.h>
#include<time.h>
void insertionSort(int array[],int n){
int i,element,j;
for(i=1;i<n;i++){
element=array[i];
j=i-1;
while(j>=0 && array[j]>element)
{
array[j+1]=array[j];
j=j-1;
}
array[j+1]=element;
}
}
void printArray(int array[],int n){
int i;
for(i=0;i<n;i++){
printf("%d",array[i]);
printf("\n");
}
}
int main(){
int n;
clock_t start,end;
double cpu_time_used;
int arr[]={50,23,9,18,32};
clrscr();
n=sizeof(arr)/sizeof(arr[0]);
printf("\nBefore Sorting:");
printArray(arr,n);
start=clock();
insertionSort(arr,n);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nAfter sorting:");
printArray(arr,n);
printf("Execution Time:%f seconds\n",cpu_time_used);
getch();
return 0;

}