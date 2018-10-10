#define QUIT 5
#define HOTEL1 80.00
#define HOTEL2 125.00
#define HOTEL3 135.00
#define HOTEL4 200.00
#define DISCOUNT 0.95
#define STARS "*****************"

//选项列表
int menu(void);
//天数
int getnights(void);
//按照不同旅馆和几晚显示价格
void showprice(double, int);
