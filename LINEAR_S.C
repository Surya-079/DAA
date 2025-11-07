#include<stdio.h>
#include<conio.h>
void main()
{
int n=0;
int i,j,key,arr[10];
clrscr();
printf("Enter n:");
scanf("&d",&n);
printf("Enter the values:\n");
for(j=0;j<n;j++)
{
scanf("%d",&arr[j]);
}
printf("Enter Key Value:");
scanf("%d",&key);
for(i=0;i<n;i++){
if(arr[i]==key){
printf("%d",i);
}
}
getch();
}