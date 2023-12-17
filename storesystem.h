#define GAMES_FILE_NAME "gamesinfo.txt"
#define MAX_ID 25
#define MAX_NAME_LEN 35
#define MAX_ORIGINAL_PRICE 20
#define PASS_WD "403forbidden"

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

void init_list(GamesList **pL);
bool Add_a_Game(GamesList *L, GamesInfo info, int location);
bool Delete_a_Game(GamesList *L, char *id);
bool Fix_Game(GamesList *L, char *id, GamesInfo info);
GamesList* SearchGame(GamesList *L, char *ch,int mode);//最后的整数如果是1，则按名称查询，如果为0，则按ID查询.
GamesInfo Read_Game_Info();
void Show_a_Game(GamesList *p);
void Show_All(GamesList *L);
int SAVE_FILE(GamesList *L);
void Sort_Game(GamesList *L);
void destory_list(GamesList **pL);
void destory_list_and_file(GamesList **pL);
void sort_Game(GamesList *L);
void sort_Game_pricenow(GamesList *L);
void sort_Game_history(GamesList *L);
void sort_Game_discount(GamesList *L);
void inputnumCheck(int *a);
