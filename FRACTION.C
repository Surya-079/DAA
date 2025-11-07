
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
int itemId;
int weight;
int profit;
float pByw;
}Item;
int compareItems(const void*a,const void*b){
Item *itemA=(Item*)a;
Item *itemB=(Item*)b;
if(itemA->pByw<itemB->pByw){
return 1;
}
if(itemA->pByw>itemB->pByw){
return -1;
}
return 0;
}
float fractionalKnapsack(Item *items,int n,int capacity){
float totalProfit=0.0;
int currentWeight=0;
int i;
qsort(items,n,sizeof(Item),compareItems);
for(i=0;i<n;i++){
if(currentWeight+items[i].weight<=capacity){
currentWeight+=items[i].weight;
totalProfit+=items[i].profit;
printf("Added item %d(Weight:%d,Profit:%d)completely.Current Weight:%d,Total profit:%.2f\n",items[i].itemId,items[i].weight,items[i].profit,currentWeight,totalProfit);
}
else{
float remainingCapacity=capacity-currentWeight;
float fraction=remainingCapacity/items[i].weight;
totalProfit+=fraction*items[i].profit;
currentWeight+=remainingCapacity;
printf("Added %.2f%% of item %d(Weight:%d,Profit:%d).Current Weight:%d,Total profit:%.2f\n",fraction*100,items[i].itemId,items[i].weight,items[i].profit,currentWeight,totalProfit);
break;
}
}
return totalProfit;
}
int main(){
int n, knapsackCapacity;
int i;
float maxProfit;
clock_t start,end;
double total_time;
Item*items=(Item*)malloc(sizeof(Item)*n);
clrscr();
printf("Enter the number of items:");
scanf("%d",&n);
if(items==NULL){
printf("Memory allocation failed.\n");

return 1;
}
printf("Enter itemId,weight,and profit for each item:\n");
for(i=0;i<n;i++){
printf("Item %d:",i+1);
scanf("%d %d %d",&items[i].itemId,&items[i].weight,&items[i].profit);
items[i].pByw=(float)items[i].profit/items[i].weight;
}
printf("Enter the knapsack capacity:");
scanf("%d",&knapsackCapacity);
start=clock();
maxProfit=fractionalKnapsack(items,n,knapsackCapacity);
end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nMaximum Profit for the given capacity:%.2f\n",maxProfit);
printf("Execution Time:%f seconds",total_time);
free(items);
getch();
return 0;
}