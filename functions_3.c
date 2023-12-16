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

GamesList* SearchGame(GamesList *L, char *ch,int mode)
{
    if(mode == 0)//ID查询
    {
        while(L!= NULL&&strcmp(L->data.game_id,ch))
            L = L->next;
        return L;
    }   
    if(mode == 1)//名称查询
    {
        while(L!= NULL&&strcmp(L->data.game_name,ch))
            L = L->next;
        return L;
    }
}

void Show_All(GamesList *L)
{
    while(L->next!=NULL)
    {
        Show_a_Game(L->next);
        L = L->next;
    }
}

void Show_a_Game(GamesList *p)
{
    printf("%s\t%s\t%f\t%f\t%f\t%f\n",p->data.game_id,p->data.game_name,p->data.game_price_origin,p->data.game_price_now,p->data.game_price_history,p->data.game_discount);
}