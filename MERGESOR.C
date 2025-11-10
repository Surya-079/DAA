#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int left,int mid,int right){
int i,j,k,n1,n2;
int *L,*R;
n1=mid-left+1;
n2=right-mid;
*L=(int*)malloc(n1*sizeof(int));
*R=(int*)malloc(n2*sizeof(int));
for(i=0;i<n1;i++){
L[i]=arr[left+i];
}
for(j=0;j<n2;j++){
R[j]=arr[mid+1+j];
}
i=0;
j=0;
k=left;
while(i<n1 && j<n2){
if(L[i]<=R[j]){
arr[k]=L[i];
i++;
}
else{
arr[k]=R[j];
j++;
}
k++;
}
while(i<n1){
arr[k]=L[i];
i++;
k++;
}
while(j<n2){
arr[k]=R[j];
j++;
k++;
}
free(L);
free(R);
}
void mergeSort(int arr[],int left,int right){
int mid;
if(left<right){
mid=left+(right-left)/2;
mergeSort(arr,left,mid);
mergeSort(arr,mid+1,right);
merge(arr,left,mid,right);
}
}
void printArray(int arr[],int size){
int i;
for(i=0;i<size;i++){
printf("%d",arr[i]);
printf("\n");
}
printf("\n");
}
int main(){
int arr_size;
clock_t start,end;
double cpu_time_used;
int arr[]={12,11,13,5,6,7};
clrscr();
arr_size=sizeof(arr)/sizeof(arr[0]);
printf("Given Array is\n");
printArray(arr,arr_size);
start=clock();
mergeSort(arr,0,arr_size-1);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nSorted Array is\n");
printArray(arr,arr_size);
printf("Execution time: %f seconds\n",cpu_time_used);
getch();
return 0;
}