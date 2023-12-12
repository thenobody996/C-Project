#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"storesystem.h"

int main(void){
    int code;
    GamesList *gamesList;
    //init_list(&gamesList);
    char ID[MAX_ID];

system("chcp 65001 & cls");//支持中文输出
//用户界面
for (size_t i = 0; i < 40; i++)
{
    printf("*");
}
printf("\n");
printf("      ");
printf("欢迎使用游戏商城比价数据库！");
printf("      \n");
for(size_t i = 0;i<10;i++)
printf("-");
printf("拯救钱包，拒绝背刺！");
for(size_t i = 0;i<10;i++)
printf("-");
while (1)
{
    for (size_t i = 0; i < 40; i++)
{
    printf("*");
}
    puts("输入数字以启用对应功能，仅输入的第一个数字有效：");
    puts("---1.显示所有游戏相关信息");
    puts("---2.查找游戏");
    puts("---3.添加游戏信息");
    puts("---4.删除指定游戏信息");
    puts("---5.更改指定游戏信息");
    puts("---6.按照特定条件排序");
    puts("---7.删除所有数据");
    puts("---8.使用文件批量添加游戏");
    puts("---0.保存数据并退出系统");
    for (size_t i = 0; i < 40; i++)
{
    printf("*");
}
    printf("\n在此处输入数字以启用功能:");
    scanf("%d",&code);
    /*switch (code)
    {
    case 1:
       
        break;
    case 0:
    //SAVE_FILE(gamesList);
    return 0;
    default:
    puts("输入错误，请重试");
        break;
    }*/
    return 0;
}


}