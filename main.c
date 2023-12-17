#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"


int main(void)
{
    int code;
    int inputnum;
    GamesList *gamesList, *result;
    GamesInfo info;
    init_list(&gamesList);
    char respond;
    char ID[MAX_ID];
    char name[MAX_NAME_LEN];

    system("chcp 65001 & cls");//支持中文输出

    //用户界面
    for (size_t i = 0; i < 40; i++)
    {
       printf("*");
    }
    printf("\n");
    printf("      ");
    printf("欢迎使用游戏商城比价数据库!");
    printf("      \n");
    for(size_t i = 0;i<10;i++)
        printf("-");
    printf("拯救钱包, 拒绝背刺!");
    for(size_t i = 0;i<10;i++)
        printf("-");
    printf("\n");

    //循环主体
    while (1)
    {
        for (size_t i = 0; i < 40; i++)
            printf("*");
        printf("\n");
        printf("输入数字以启用对应功能, 仅输入的第一个数字有效: \n");
        printf("---1.显示所有游戏相关信息\n");
        printf("---2.查找游戏\n");
        printf("---3.添加游戏信息\n");
        printf("---4.删除指定游戏信息\n");
        printf("---5.更改指定游戏信息\n");
        printf("---6.按照特定条件排序\n");
        printf("---7.删除所有数据\n");
        printf("---8.不保存数据退出\n");
        printf("---0.保存数据并退出系统\n");
        for (size_t i = 0; i < 40; i++)
        {
            printf("*");
        }
        printf("\n在此处输入数字以启用功能: ");
        while(!scanf("%d",&code))
        {
            printf("输入错误, 应当输入一个数字\n");
            while (getchar()!= '\n')
                continue;
        }
        while (code > 10)
        {
            code = code / 10;
        }
        while(getchar() != '\n');

        //功能跳转
        switch (code)
        {
            case 1:

                Show_All(gamesList);
                break;

            case 2:
                printf("请输入你要查找的游戏对应名称: ");
                gets(name);
                result = SearchGame(gamesList,name,1);
                if(!result)
                {
                    printf("游戏名为 %s 的游戏不存在\n", name);
                    break;
                }
                Show_a_Game(result);
                break;

            case 3:
                info = Read_Game_Info();
                printf("要插入到链表的第几位？\n提示: 输入0视为添加到链表最后一位: ");
                while(!scanf("%d",&inputnum))
                {
                    printf("输入错误, 应当输入一个数字\n");
                    while (getchar()!= '\n')
                        continue;
                }
                if(SearchGame(gamesList, info.game_id, 0) || SearchGame(gamesList, info.game_name, 1))
                {
                    printf("此游戏已存在\n");
                    break;
                }
                Add_a_Game(gamesList,info,inputnum);
                break;

            case 4:
                printf("请输入你要删除的游戏对应的ID: ");
                gets(ID);
                result = SearchGame(gamesList,ID,0);
                if(!result)
                {
                    printf("ID为 %s 的游戏不存在\n", ID);
                    break;
                }
                Show_a_Game(result);
                printf("以上是你要删除的信息, 确认删除请输入y, 取消则输入n: ");
                while ((respond = getchar()) != 'n')
                {
                    if(respond = 'y')
                    {   
                        printf("已执行删除功能\n");
                        Delete_a_Game(gamesList,ID);
                        while (getchar()!= '\n')
                            continue;
                        break;
                    }
                    else
                    {
                        printf("输入错误, 请重新输入\n");
                        while (getchar()!= '\n')
                            continue;
                        continue;
                    }
                }
                break;

            case 5:
                printf("请输入你要修改的游戏对应的ID: ");
                gets(ID);
                result = SearchGame(gamesList,ID,0);
                if(!result)
                {
                    printf("ID为 %s 的游戏不存在\n", ID);
                    break;
                }
                Show_a_Game(result);
                printf("请输入你需要更正的信息\n");
                info = Read_Game_Info();
                if(SearchGame(gamesList, info.game_id, 0) || SearchGame(gamesList, info.game_name, 1))
                {
                    printf("此游戏已存在\n");
                    break;
                }
                Fix_Game(gamesList,ID,info);
                break;

            case 6: 
                break;

            case 7:
                destory_list_and_file(&gamesList);
                break;

            case 8:
                destory_list(&gamesList);
                return 0;

            case 0:
                SAVE_FILE(gamesList);
                destory_list(&gamesList);
                return 0;

            default:
                printf("输入错误, 请重试\n");
            break;
        }
    }
}