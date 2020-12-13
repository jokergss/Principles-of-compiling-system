#include<stdio.h>

int main()
{
    int i,n,sum=1;
    printf("请输n(n=1,2..)：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sum=sum*i;
    printf("1x2x3x..n等于%d",sum);
   return 0;
}