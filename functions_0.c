#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"storesystem.h"

void init_list(GamesList **L)
{
    *L = (GamesList *)malloc(sizeof(GamesList));
    (*L)->next = NULL;
    

}