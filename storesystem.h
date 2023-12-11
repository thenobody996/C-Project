#define GOODS_FILE_NAME gamesinfo.txt
#define MAX_ID 25
#define MAX_NAME_LEN 35
#define MAX_ORIGINAL_PRICE 20
typedef struct {
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

