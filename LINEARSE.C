#include<stdio.h>
#include<time.h>
int recursiveLinearSearch(int arr[],int size,int key,int index){
if(index>=size){
return -1;
}if(arr[index]==key){
return index;
}
return recursiveLinearSearch(arr,size,key,index+1);
}
int main(){
int n=10000
int arr[n];
int i,result;
int key=n-1;
clock_t start,end;
double cpu_time_used;
for(i=0;i<n;i++){
arr[i]=i;
}

start=clock();
result=recursiveLinearSearch(arr,n,key,0);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
if(result!=-1){
printf("Element found at index %d\n",result);
}
else{
printf("Element not found\n");
}
printf("Execution Time:%f seconds\n",cpu_time_used);
getch();
return 0;

}