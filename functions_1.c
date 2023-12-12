#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

    gamesinfo.game_price_now = gamesinfo.game_price_origin * (1 - gamesinfo.game_discount / 100);
    gamesinfo.game_price_history = gamesinfo.game_price_now;

    return gamesinfo;
}

