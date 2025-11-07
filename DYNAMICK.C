#include<stdio.h>
#include<time.h>
int max(int a,int b){
return(a>b)?a:b;
}
int knapsack(int W,int wt[],int val[],int n){
int i,w;
int knap[10][10];
for(i=0;i<=n;i++){
for(w=0;w<=W;w++){
if(i==0 ||w==0){
knap[i][w]=0;
}
else if(wt[i-1]<=w){
knap[i][w]=max(val[i-1]+knap[i-1][w-wt[i-1]],knap[i-1][w]);
}
else{
knap[i][w]=knap[i-1][w];
}
}
}
return knap[n][W];
}
int main(){
int val[]={60,100,120};
int wt[]={10,20,30};
int W=50;
int n;
clock_t start,end;
double total_time;
clrscr();
start=clock();
n=sizeof(val)/sizeof(val[0]);
printf("The Maximum value that can be put in the knapsack is:%d\n",knapsack(W,wt,val,n));
end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("Exection time:%f seconds\n",total_time);
getch();
return 0;
}