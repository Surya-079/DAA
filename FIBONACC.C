#include<stdio.h>
#include<time.h>
int main(){
int n,i,t1=0,t2=1,nextTerm;
clock_t start,end;
double total_time;
clrscr();
printf("Enter the number of terms: ");
scanf("%d",&n);
printf("Fibonacci Series: %d %d",t1,t2);
start=clock();
for(i=3;i<=n;i++){
nextTerm=t1+t2;
printf(", %d",nextTerm);
t1=t2;
t2=nextTerm;
}
end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\n");
printf("Execution Time: %f seconds",total_time);
getch();
return 0;
}