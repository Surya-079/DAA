#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}
int partition(int arr[],int low,int high){
int i,j,pivot;
pivot=arr[high];
i=(low-1);
for(j=low;j<=high-1;j++){
if(arr[j]<=pivot){
i++;
swap(&arr[i],&arr[j]);
}
}
swap(&arr[i+1],&arr[high]);
return(i+1);
}
void quickSort(int arr[],int low,int high){
int pIndex;
if(low<high){
pIndex=partition(arr,low,high);
quickSort(arr,low,pIndex-1);
quickSort(arr,pIndex+1,high);

}
}
void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++){
printf("%d ",arr[i]);
}
printf("\n");
}
int main(){
int n;
int arr[]={10,7,8,9,1,5};
clock_t start,end;
double cpu_time_used;
clrscr();
n=sizeof(arr)/sizeof(arr[0]);
printf("Original Array:");
printArray(arr,n);
start=clock();
quickSort(arr,0,n-1);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("Sorted Array: ");
printArray(arr,n);
printf("\nExecution Time: %f seconds",cpu_time_used);
getch();
return 0;
}