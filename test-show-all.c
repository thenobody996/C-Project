#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"storesystem.h"

void Show_All(GamesList *L)
{
    while(L->next!=NULL)
    {
        Show_a_Game(L->next);
        L = L->next;
    }
}