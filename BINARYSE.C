#include<stdio.h>
#include<time.h>
int binarySearch(int arr[],int n,int key){
int low=0,high=n-1;
int mid;
while (low<=high){
mid=low+(high-low)/2;
if (arr[mid]==key){
return mid;
}
else if(arr[mid]<key){
low=mid+1
}
else{
high=mid-1;
}
return -1
}
int main(){
int result;
int n=100000;
int arr[n];
clock_t start,end;
double cpu_time_used;
start=clock();
result=binarySearch(arr,n,key);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
if (result!=-1){
printf("Element found at index %d\n",result);
}
else{
printf("Element not found\n");
}
printf("Execution Time:%f seconds\n",cpu_time_used);
return 0;
}
