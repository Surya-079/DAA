
#include<stdio.h>
#include<time.h>
int findSubset(int set[],int subset[],int n,int index,int target,int currentSum){
int i;
int found=0;
if(currentSum==target){
printf("Subset Found:");
for(i=0;i<index;i++){
printf("%d ",subset[i]);
}
printf("\n");
return 1;
}
if(currentSum>target ||  n==0){
return 0;
}
subset[index]=set[0];
found |=findSubset(set+1,subset,n-1,index+1,target,currentSum+set[0]);
found |=findSubset(set+1,subset,n-1,index,target,currentSum);
return found;
}
int main(){
int a,target,i,n;
clock_t start,end;
double total_time;
int set[100];
int subset[100];
int found=0;
clrscr();
printf("Enter the number of elements in the set:");
scanf("%d",&n);
printf("Enter the elements of the set:");
for(i=0;i<n;i++){
scanf("%d",&set[i]);
}
printf("Enter the target sum:");
scanf("%d",&target);
printf("Subsets with sum %d:\n",target);
start=clock();
a=findSubset(set,subset,n,0,target,0);
end=clock();
if(a==0){
printf("Subsets not Found.\n");
}
total_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nExecution Time: %.4f seconds.\n",total_time);
getch();
return 0;
}