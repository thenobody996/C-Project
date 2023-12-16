#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"storesystem.h"
int CurrentCnt = 0;
void init_list(GamesList **L)
{
    
    *L = (GamesList *)malloc(sizeof(GamesList));//建立头节点
    (*L)->next = NULL;//头节点目前不指向任何数据
    GamesList *ends= *L;
    GamesInfo info;
    FILE *f;

    f = fopen(GOODS_FILE_NAME,"r");
    if(f == NULL)
    {
        perror("fopen has occurred an error");
    }

    while (fscanf(f,"%-25s\t%-35s\t%-8.2f\t-%-4.1f%%\t%-8.2f\t%-8.2f\n",
    info.game_id,info.game_name,&info.game_price_origin,&info.game_discount,&info.game_price_now,&info.game_price_origin)
    != EOF)
    {
        GamesList *L = (GamesList *)malloc(sizeof(GamesList));//建立新的节点
        L->data = info;//添加数据
        ends->next = L;//将上一个节点的指针域指向这个新建的节点
        ends = L;
        CurrentCnt++;
    }
    ends->next = NULL;
    
    fclose(f);
    f = NULL;
}