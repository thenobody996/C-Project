#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"

void inputnumCheck(int *a)
{
    while(!scanf("%d",a))
    {
        printf("输入错误, 应当输入一个数字");
    }
}

GamesList* SearchGame(GamesList *L, char *ch, int mode)
{
    GamesList *p = L;
    
    if(mode == 0)//ID查询
    {
        while(p && strcmp(p->data.game_id, ch))
            p = p->next;
        return p;
    }   
    if(mode == 1)//名称查询
    {
        while(p && strcmp(p->data.game_name, ch))
            p = p->next;
        return p;
    }
}

void Show_All(GamesList *L)
{
    GamesList *p = L;

    while(p->next)
    {
        Show_a_Game(p->next);
        p = p->next;
    }
}

void Show_a_Game(GamesList *p)
{
    printf("%-25s|%-35s|%-8.2f|-%-4.1f%%|%-8.2f|%-8.2f\n",p->data.game_id,p->data.game_name,p->data.game_price_origin,p->data.game_discount,p->data.game_price_now,p->data.game_price_history);
}