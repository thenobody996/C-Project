#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"storesystem.h"
int CurrentCnt = 0;
void init_list(GamesList **pL)
{
    
    *pL = (GamesList *)malloc(sizeof(GamesList));//建立头节点
    (*pL)->next = NULL;//头节点目前不指向任何数据
    GamesList *ends= *pL;
    GamesInfo info;
    FILE *f;

    f = fopen(GAMES_FILE_NAME,"r");
    if(f == NULL)
    {
        perror("fopen has occurred an error");
    }

    while (fscanf(f,"%25s%35s%8f%4f%8f%8f|",
    info.game_id,info.game_name,&info.game_price_origin,&info.game_discount,&info.game_price_now,&info.game_price_history)
    != EOF)
    {
        GamesList *L = (GamesList *)malloc(sizeof(GamesList));//建立新的节点
        L->data = info;//添加数据
        ends->next = L;//将上一个节点的指针域指向这个新建的节点
        ends = L;
        CurrentCnt++;
        printf("|%-25s|%-35s|%-8.2f|%-4.1f|%-8.2f|%-8.2f|\n",info.game_id,info.game_name,info.game_price_origin,info.game_discount,info.game_price_now,info.game_price_history);
    }
    ends->next = NULL;
    
    fclose(f);
    f = NULL;
}