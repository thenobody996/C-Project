#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"

void Show_a_Game(GamesList *p)
{
    printf("%s\t%s\t%f\t%f\t%f\t%f\n",p->data.game_id,p->data.game_name,p->data.game_price_origin,p->data.game_price_now,p->data.game_price_history,p->data.game_discount);
}