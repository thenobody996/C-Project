#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"storesystem.h"

GamesInfo Read_Game_Info()
{
    GamesInfo gamesinfo;

    printf("请输入游戏ID: ");
    fgets(gamesinfo.game_id, MAX_ID, stdin);

    printf("请输入游戏名称: ");
    fgets(gamesinfo.game_name, MAX_NAME_LEN, stdin);

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

            printf("游戏已成功插入到列表尾部");
            return true;
        }
        case 1:  //插入到头部
        {
            p = malloc(sizeof(GamesList));
            p->data = info;
            p->next = L->next;
            L->next = p;
            CurrentCnt++;

            printf("游戏已成功插入到列表头部");
            return true;
        }
        default:  //插入到中间
        {
            for(int i = 1; i <= location - 1; i++)
                p = p->next;
            GamesList *q = malloc(sizeof(GamesList));
            q->next = p->next;
            q->data = info;
            p->next = q;
            CurrentCnt++;

            printf("游戏已成功插入到列表第%d位", location);
            return true;
        }
    }
}

bool Delete_a_Game(GamesList *L,char id)
{
    GamesList *cur = L, *del = cur->next;
    
    for(; del; del = del->next, cur = cur->next)
    {
        if(!strcmp(del->data.game_id, id))
        {
            cur->next = del->next;
            free(del);
            CurrentCnt--;

            printf("ID为 %s 的游戏删除成功! ", id);
            return true;
        }
    }
    
    printf("删除失败! 没有ID为 %s 的游戏", id);
    return false;
}

