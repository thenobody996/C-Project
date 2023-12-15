#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"

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