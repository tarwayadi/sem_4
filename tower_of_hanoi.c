//TOWER OF HANOI
#include<stdio.h>
void tower_of_hanoi(int n,char from_rod,char to_rod,char aux_rod)
{
    if(n==1)
    {
        printf("\n move disk 1 from %c to rod %c",from_rod,to_rod);
        return;
    }
    tower_of_hanoi(n-1,from_rod,aux_rod,to_rod);
    printf("\n move disk %d from rod %c to rod %c",n,from_rod,to_rod);
    tower_of_hanoi(n-1,aux_rod,to_rod,from_rod);

}
int main()

{
    int n=4;
    tower_of_hanoi(n,'A','B','C');
    return 0;

}