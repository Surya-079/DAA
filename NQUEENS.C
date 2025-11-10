#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#define N 8
void printSolution(int board[N][N])
{
int i,j;
for(i=0;i<N;i++){
for(j=0;j<N;j++){
printf("%c",board[i][j]?'Q':'.');
}
printf("\n");
}
printf("\n");
}
bool isSafe(int board[N][N],int row,int col){
int i,j;
for(i=0;i<col;i++){
if(board[row][i]){
return false;
}
}
for(i=row,j=col;i>=0 && j>=0;i--,j--){
if(board[i][j]){
return false;
}
}
for(i=row,j=col;i<N && j>=0;i++,j--){
if(board[i][j]){
return false;
}
}
return true;
}
bool solveNQUtil(int board[N][N],int col){
int i;
if(col>=N){
return true;
}
for(i=0;i<N;i++){
if (isSafe(board,i,col)){
board[i][col]=1;
if(solveNQUtil(board,col+1)){
return true;
}
board[i][col]=0;
}
}
return false;
}
void solveNQ(){
int board[N][N]={0};
int i,j;
if(!solveNQUtil(board,0)){
printf("Solution does not exist.\n");
return;
}
printSolution(board);
}
int main(){
clock_t start,end;
double total_time;
clrscr();
start=clock();
solveNQ();
end=clock();
total_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nExecution Time: %.4f seconds.\n",total_time);
getch();
return 0;
}