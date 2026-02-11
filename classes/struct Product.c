struct Product{
    int pCode;
    char pName[50];
    float pPrice;
    int pStock;
    char pCategory[30];
}shop[MAX_ITEMS];
int nProducts=0;

struct Member{
    int mId;
    char mName[50];
    float mSpent;
    char mTier[20];
    float mDisc;
}Members[MAX_MEMBERS];
int nMembers=0;

struct CartItem {
    int code;
    char name[50];
    float price;
    int qty;
} cart[MAX_CART];
int cartCount=0;

struct Sale {
    int pCode;
    char pName[50];
    int qty;
    float price;
    float total;
} sales[500];
int nSales=0;
float totalRevenue=0;
float totalDiscount=0;
int totalBills=0;