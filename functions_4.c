#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include "storesystem.h"

void sort_Game_history(GamesList *L);
void sort_Game_pricenow(GamesList *L);
void sort_Game_discount(GamesList *L);


void Sort_Game(GamesList **pL, int sortBy) {
    if (*pL == NULL || (*pL)->next == NULL) {
        return;  // 链表为空或只有一个节点，无需排序
    }

    switch (sortBy) {
        case 1:  // 按照当前价格从低到高排序
            sort_Game_pricenow(*pL);
            break;
        case 2:  // 按照史低价格从低到高排序
            sort_Game_history(*pL);
            break;
        case 3:  // 按照折扣百分比从高到低排序
            sort_Game_discount(*pL);
            break;
        default:
            printf("无效的排序选项\n");
            return;
    }

}

// 以下是按照不同标准进行排序的辅助函数
void sort_Game_history(GamesList *L) {
    if (L == NULL || L->next == NULL) {
        return;  // 链表为空或只有一个节点，无需排序
    }

    GamesList *sortedList = NULL;  // 排序后的链表
    GamesList *current = L;

    while (current != NULL) {
        GamesList *next = current->next;
        if (sortedList == NULL || sortedList->data.game_price_history > current->data.game_price_history) {
            // 如果排序后的链表为空，或者当前节点的史低价格小于排序后链表的第一个节点
            current->next = sortedList;
            sortedList = current;
        } else {
            // 在排序后的链表中找到合适的位置插入
            GamesList *temp = sortedList;
            while (temp->next != NULL && temp->next->data.game_price_history < current->data.game_price_history) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
            while (sortedList != NULL) 
            {
        GamesList *temp = sortedList;
        sortedList = sortedList->next;
        L->next = temp;
        L = L->next;
        }
}


void sort_Game_pricenow(GamesList *L) 
{
    if (L == NULL || L->next == NULL) {
        return;  // 链表为空或只有一个节点，无需排序
    }

    GamesList *sortedList = NULL;  // 排序后的链表
    GamesList *current = L;

    while (current != NULL) {
        GamesList *next = current->next;
        if (sortedList == NULL || sortedList->data.game_price_now > current->data.game_price_now) 
        {
            // 如果排序后的链表为空，或者当前节点的史低价格小于排序后链表的第一个节点
            current->next = sortedList;
            sortedList = current;
        } else {
        // 在排序后的链表中找到合适的位置插入
        GamesList *temp = sortedList;
        while (temp->next != NULL && temp->next->data.game_price_history < current->data.game_price_history) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
        while (sortedList != NULL) {
        GamesList *temp = sortedList;
        sortedList = sortedList->next;
        L->next = temp;
        L = L->next;
        }
}


void sort_Game_discount(GamesList *L) {
    if (L == NULL || L->next == NULL) {
        return;  // 链表为空或只有一个节点，无需排序
    }

    GamesList *sortedList = NULL;  // 排序后的链表
    GamesList *current = L;

    while (current != NULL) {
        GamesList *next = current->next;
        if (sortedList == NULL || sortedList->data.game_discount > current->data.game_discount) {
            // 如果排序后的链表为空，或者当前节点的史低价格小于排序后链表的第一个节点
            current->next = sortedList;
            sortedList = current;
        } else {
            // 在排序后的链表中找到合适的位置插入
            GamesList *temp = sortedList;
            while (temp->next != NULL && temp->next->data.game_price_history < current->data.game_price_history) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
        
    }
        while (sortedList != NULL) {
        GamesList *temp = sortedList;
        sortedList = sortedList->next;
        L->next = temp;
        L = L->next;
        }
}
