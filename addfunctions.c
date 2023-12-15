#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"

void inputnumCheck(int *a)
{
    while(!scanf("%d",a))
    {
        printf("输入错误，应当输入一个数字");
    }
}