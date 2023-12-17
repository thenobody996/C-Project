#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "storesystem.h"

GamesInfo Read_Game_Info()
{
    GamesInfo gamesinfo;

    printf("请输入游戏ID: ");
    gets(gamesinfo.game_id);

    printf("请输入游戏名称: ");
    gets(gamesinfo.game_name);

    printf("请输入游戏原价: ");
    scanf("%f", &gamesinfo.game_price_origin);

    printf("请输入游戏折扣(百分比,不用填写百分号): ");
    scanf("%f", &gamesinfo.game_discount);

    gamesinfo.game_price_now = gamesinfo.game_price_origin * (1 - gamesinfo.game_discount / 100);  //计算折后价格
    gamesinfo.game_price_history = gamesinfo.game_price_now;

    return gamesinfo;
}

bool Add_a_Game(GamesList *L, GamesInfo info, int location)
{
    GamesList *p = L;

    switch (location)
    {
        case 0:  //插入到尾部
        {
            while(p->next)
                p = p->next;
            p->next = malloc(sizeof(GamesList));
            p->next->data = info;
            p->next->next = NULL;
            CurrentCnt++;

            printf("游戏已成功插入到列表尾部\n");
            return true;
        }
        case 1:  //插入到头部
        {
            p = malloc(sizeof(GamesList));
            p->data = info;
            p->next = L->next;
            L->next = p;
            CurrentCnt++;

            printf("游戏已成功插入到列表头部\n");
            return true;
        }
        default:  //插入到中间
        {
            for(int i = 1; i <= location - 1; i++)
            {
                p = p->next;

                if(!p)
                {
                    printf("插入失败! 目标位置超出已有项目数量\n");
                    return false;
                }
            }

            GamesList *q = malloc(sizeof(GamesList));
            q->next = p->next;
            q->data = info;
            p->next = q;
            CurrentCnt++;

            printf("游戏已成功插入到列表第%d位\n", location);
            return true;
        }
    }
}

bool Delete_a_Game(GamesList *L, char *id)
{
    GamesList *cur = L, *del = cur->next;
    
    for(; del; del = del->next, cur = cur->next)
    {
        if(strcmp(del->data.game_id, id) == 0)
        {
            cur->next = del->next;
            free(del);
            CurrentCnt--;

            printf("ID为 %s 的游戏删除成功!\n", id);
            return true;
        }
    }
    
    return false;
}

bool Fix_Game(GamesList *L, char *id, GamesInfo info)
{
    GamesList *cur = L;
    
    for(; cur; cur = cur->next)
    {
        if(strcmp(cur->data.game_id, id) == 0)
        {
            strcpy(cur->data.game_id, info.game_id);
            strcpy(cur->data.game_name, info.game_name);
            cur->data.game_discount = info.game_discount;
            cur->data.game_price_origin = info.game_price_origin;
            cur->data.game_price_now = info.game_price_now;
            cur->data.game_price_history = cur->data.game_price_history < info.game_price_history ? cur->data.game_price_history : info.game_price_history;

            printf("ID为 %s 的游戏信息修改成功!\n", id);
            return true;
        }
    }
    
    return false;
}

