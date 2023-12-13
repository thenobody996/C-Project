#define GOODS_FILE_NAME gamesinfo.txt
#define MAX_ID 25
#define MAX_NAME_LEN 35
#define MAX_ORIGINAL_PRICE 20

typedef struct 
{
    char game_id[MAX_ID];
    char game_name[MAX_NAME_LEN];
    float game_price_origin;//原价
    float game_price_now;//当前价格
    float game_price_history;//史低
    float game_discount;//折扣
}GamesInfo;

typedef struct node
{
    GamesInfo data;
    struct node *next;
}GamesList;

extern int CurrentCnt;

void priceUpdate(GamesList *p);
void init_list(GamesList **L);
bool Add_a_Game(GamesList *L, GamesInfo info, int location);
bool Delete_a_Game(GamesList *L, char *id);
bool Fix_Game(GamesList *L, char *id, GamesInfo info);
GamesList* SearchGame(GamesList *L, char *id);
GamesInfo Read_Game_Info();
void Show_a_Game(GamesList *p);
void Show_All(GamesList *L);
void SAVE_FILE(GamesList *L);
void Sort_Game(GamesList *L);
void destory_list(GamesList **L);
void destory_list_and_file(GamesList **L);
void sort_Game(GamesList *L);
void sort_Game_pricenow(GamesList *L);
void sort_Game_history(GamesList *L);
void sort_Game_discount(GamesList *L);
void inputnumCheck(int *a)
{
    while(!scanf("%d",a))
    {
        printf("输入错误，应当输入一个数字");
    }
}