#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "storesystem.h"

void inputnumCheck(int *a)
{
    while (!scanf("%d",a))
    {
        printf("输入错误, 应当输入一个数字");
        while (getchar()!= '\n')
            continue;
    }
}

bool AdminCheck()
{
    char password[16] = {0};
    int i = 0;
    char input;
    if(admin)
    {
        return true;
    }
    printf("请输入管理员密码: ");
    while (1)
    {
        input = _getch();   //隐藏输入
        if (input == '\r')
        {
            break;
        }
        else if (input == '\b')
        {
            printf("\b \b");//退格
            i--;
        }
        else
        {
            password[i++] = input;
            printf("*");
        }
    }
    printf("\n");
    
    if (!strcmp(password,PASS_WD))
        {
            admin = true;
            return true;
        }   
    else
        return false;
    
}

GamesList* SearchGame(GamesList *L, char *ch, int mode)
{
    GamesList *p = L;
    
    if (mode == 0)   //ID查询
    {
        while (p && strcmp(p->data.game_id, ch))
            p = p->next;
        
        return p;
    }

    if (mode == 1)  //名称查询
    {
        while (p && strcmp(p->data.game_name, ch))
            p = p->next;
        
        return p;
    }
}

void Show_All(GamesList *L)
{
    GamesList *p = L;

    while (p->next)
    {
        Show_a_Game(p->next);
        p = p->next;
    }
}

void Show_a_Game(GamesList *p)
{
    printf("|%-25s|%-35s|%-8.2f|-%-4.1f%%|%-8.2f|%-8.2f|\n",
        p->data.game_id, p->data.game_name, p->data.game_price_origin, p->data.game_discount, p->data.game_price_now, p->data.game_price_history);
}