#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "storesystem.h"

void destory_list(GamesList **pL)
{
    GamesList *cur = *pL, *des;

    for (; cur->next; des = cur->next, cur->next = des->next)
        free(des);
    free(*pL);
    *pL = NULL;
    CurrentCnt = 0;
}

void destory_list_and_file(GamesList **pL)
{
    destory_list(pL);
    remove(GAMES_FILE_NAME);
}

int SAVE_FILE(GamesList *L)
{
    if(!L)
        return -1;

    GamesList *p;
    FILE* file = fopen(GAMES_FILE_NAME, "w");

    int cnt = 0;
    for(p = L->next; p; p = p->next)
    {
        fprintf(file, "%-25s%-35s%-8.2f%-4.1f%-8.2f%-8.2f\n", 
        p->data.game_id, p->data.game_name, p->data.game_price_origin, p->data.game_discount, p->data.game_price_now, p->data.game_price_history);
        cnt++;
    }

    fclose(file);
    return cnt;
}