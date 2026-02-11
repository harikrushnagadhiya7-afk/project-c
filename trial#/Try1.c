#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_MEMBERS 100
#define MAX_CART 50
#define MAX_SALES 500

// Credentials
char ad_user[10] = "admin";
char ad_pass[10] = "admin";
char sf_user[10] = "staff";
char sf_pass[10] = "staff";

// Function Prototypes
void mainManu();
void admin();
void adminDashboard();
void inventory();
void add();
void login();
void view();
void del();
void info();
void cust();
void custView();
void members();
void addMembers();
void deleteMembers();
void viewMembers();
void search();
void addCart();
void viewCart();
void checkout();
void salesManu();
void salesSummary();
void productSales();
void discountReport();
void recordSale(int, char[], int, float);
float applyDiscount(int, float);
void billing(float finalAmount);
void staff();

// Structures
struct Product {
    int pCode;
    char pName[50];
    float pPrice;
    int pStock;
    char pCategory[30];
} shop[MAX_ITEMS];
int nProducts = 0;

struct Member {
    int mId;
    char mName[50];
    float mSpent;
    char mTier[20];
    float mDisc;
} Members[MAX_MEMBERS];
int nMembers = 0;

struct CartItem {
    int code;
    char name[50];
    float price;
    int qty;
} cart[MAX_CART];
int cartCount = 0;

struct Sale {
    int pCode;
    char pName[50];
    int qty;
    float price;
    float total;
} sales[MAX_SALES];
int nSales = 0;

float totalRevenue = 0;
float totalDiscount = 0;
int totalBills = 0;

int main() {
    mainManu();
    return 0;
}

void mainManu() {
    int choice;
    while (1) {
        printf("\n--- AYH MART MAIN MENU ---\n");
        printf("1. Customer Self-Checkout\n");
        printf("2. Staff / Admin Login\n");
        printf("3. View Store Info\n");
        printf("0. Exit Application\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: 
				cust(); 
				break;
            case 2: 
				login(); 
				break;
            case 3: 
				info(); 
				break;
            case 0: 
				return;
            default: 
				printf("Invalid Option!\n");
        }
    }
}

void login() {
    char username[10], password[10];
    printf("\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, ad_user) == 0 && strcmp(password, ad_pass) == 0){
        printf("Logged in as Admin.\n");
        adminDashboard();
    } else if (strcmp(username, sf_user) == 0 && strcmp(password, sf_pass) == 0) {
        printf("Logged in as Staff.\n");
        staff();
    } else {
        printf("Invalid credentials!\n");
    }
}

void adminDashboard() {
    int choice;
    while (1) {
        printf("\n--- ADMIN PORTAL ---\n");
        printf("1. Inventory Management\n");
        printf("2. Member Management\n");
        printf("3. Sales Reports\n");
        printf("0. Logout\n");
        printf("------------------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1){
			inventory();
		}else if (choice == 2){
			members();
		}else if (choice == 3){
			salesManu();
		}else if (choice == 0){
			return;
		}else{
			printf("Invalid choice.\n");
		}      	
    }
}

void inventory() {
    int choice;
    while (1) {
        printf("\n--- INVENTORY ---\n1. Add Product\n2. Delete Product\n3. View Products\n0. Back\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1){
			add();
		}else if (choice == 2){
			del();
		}else if (choice == 3){
			view();
		}else if (choice == 0){
			return;
		}
    }
}

void add() {
    int count, i;
    printf("\nHow many products to add: ");
    scanf("%d", &count);
    for (i=0; i<count; i++) {
        if (nProducts>=MAX_ITEMS){
            printf("Inventory Full!\n");
            return;
        }
        printf("\nProduct %d Details:\n", i + 1);
        printf("Code: "); 
		scanf("%d", &shop[nProducts].pCode);
        printf("Name: "); 
		scanf("%s", shop[nProducts].pName);
        printf("Price: "); 
		scanf("%f", &shop[nProducts].pPrice);
        printf("Stock: "); 
		scanf("%d", &shop[nProducts].pStock);
        printf("Category: "); 
		scanf("%s", shop[nProducts].pCategory);
        nProducts++;
    }
    printf("\nProducts added successfully.\n");
}

void view() {
    if (nProducts==0) {
        printf("\nNo products in stock.\n");
        return;
    }
    printf("\nCODE\tNAME\tPRICE\tSTOCK\tCATEGORY\n");
    printf("------------------------------------------------\n");
    for (int i=0; i<nProducts; i++) {
        printf("%d\t%s\t%.2f\t%d\t%s\n", shop[i].pCode, shop[i].pName, shop[i].pPrice, shop[i].pStock, shop[i].pCategory);
    }
}

void del() {
    int code, found = 0;
    printf("Enter code to delete: ");
    scanf("%d", &code);
    for (int i=0; i<nProducts; i++) {
        if (shop[i].pCode==code) {
            for (int j=i; j<nProducts-1; j++) {
				shop[j] = shop[j + 1];
			}
            nProducts--;
            found = 1;
            printf("Product deleted.\n");
            break;
        }
    }
    if (!found) {
		printf("Product not found.\n");
	}
}

void info() {
    printf("\n==========================================\n");
    printf("\tSTORE INFORMATION\n");
    printf("==========================================\n");
    printf("Store Name: AYH Mart\nLocation: Surat, India\nTiming: 9 AM to 10 PM\n");
    printf("==========================================\n");
}

void cust() {
    int choice;
    while (1) {
        printf("\n--- CUSTOMER MENU ---\n1. View Products\n2. Search\n3. Add to Basket\n4. View Basket\n5. Checkout\n0. Back\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
				custView(); 
				break;
            case 2: 
				search(); 
				break;
            case 3: 
				addCart(); 
				break;
            case 4: 
				viewCart(); 
				break;
        	case 5: 
				checkout(); 
				break;
            case 0: 
				return;
			default:
				printf("Invalid choise");
        }
    }
}

void custView() {
    view();
}

void search() {
    int code, found = 0;
    printf("Enter Product Code: ");
    scanf("%d", &code);
    for (int i = 0; i < nProducts; i++) {
        if (shop[i].pCode == code) {
            printf("Found: %s | Price: %.2f | Stock: %d\n", shop[i].pName, shop[i].pPrice, shop[i].pStock);
            found = 1; break;
        }
    }
    if (!found){
		printf("Not found.\n");
	}
}

void addCart() {
    int code, qty, found = 0;
    if (cartCount >= MAX_CART) { 
		printf("Basket full!\n"); 
		return; 
	}
    printf("Enter Code: "); 
	scanf("%d", &code);
    printf("Enter Qty: "); 
	scanf("%d", &qty);
    for (int i=0;i<nProducts;i++) {
        if (shop[i].pCode==code) {
            if (shop[i].pStock>=qty) {
                cart[cartCount].code=shop[i].pCode;
                strcpy(cart[cartCount].name,shop[i].pName);
                cart[cartCount].price=shop[i].pPrice;
                cart[cartCount].qty=qty;
                shop[i].pStock-=qty;
                cartCount++;
                found = 1;
                printf("Added to basket.\n");
            } else {
                printf("Insufficient stock!\n");
                return;
            }
            break;
        }
    }
    if (!found){
		printf("Product not found.\n");
	}
}

void viewCart() {
    float total=0;
    if (cartCount==0){
		printf("Basket is empty.\n"); 
		return; 
	}
    printf("\nNAME\tPRICE\tQTY\tTOTAL\n");
    for (int i=0; i<cartCount; i++) {
        float amt=cart[i].price*cart[i].qty;
        total+=amt;
        printf("%s\t%.2f\t%d\t%.2f\n", cart[i].name, cart[i].price, cart[i].qty, amt);
    }
    printf("Grand Total: %.2f\n", total);
}

void checkout() {
    int mid;
    float total=0, discount=0;
    if (cartCount==0){
		return;
	} 
    for (int i=0; i<cartCount; i++) {
        total+=cart[i].price*cart[i].qty;
        recordSale(cart[i].code, cart[i].name, cart[i].qty, cart[i].price);
    }

    printf("Enter Member ID (0 if none): ");
    scanf("%d", &mid);
    discount = applyDiscount(mid, total);
    
    printf("\n--- FINAL BILL ---\nTotal: %.2f\nDiscount: %.2f\nPayable: %.2f\n", total, discount, total - discount);
    billing(total - discount);
    
    totalBills++;
    cartCount = 0; // Clear cart after checkout
}

void billing(float finalAmount) {
    float pay;
    do {
        printf("Enter Payment Amount: ");
        scanf("%f", &pay);
        if (pay < finalAmount){
		printf("Insufficient! You still owe %.2f\n", finalAmount - pay);
		} 
    } while (pay < finalAmount);
    
	if (pay > finalAmount){
	printf("Change Returned: %.2f\n", pay - finalAmount);
    printf("Payment Successful! Thank you for shopping.\n");
	} 
}

void members() {
    int choice;
    while (1) {
        printf("\n--- MEMBERS ---\n1. Add\n2. Delete\n3. View\n0. Back\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1){
			addMembers();
		} 
        else if (choice == 2){
			deleteMembers();
		}
        else if (choice == 3){
			viewMembers();
		} 
        else if (choice == 0){
			return;
		} 
    }
}

void addMembers() {
    if (nMembers >= MAX_MEMBERS) return;
    printf("ID: "); scanf("%d", &Members[nMembers].mId);
    printf("Name: "); scanf("%s", Members[nMembers].mName);
    printf("Tier (Silver/Gold/Platinum): "); scanf("%s", Members[nMembers].mTier);
    
    if (strcmp(Members[nMembers].mTier, "Silver") == 0) Members[nMembers].mDisc = 5;
    else if (strcmp(Members[nMembers].mTier, "Gold") == 0) Members[nMembers].mDisc = 10;
    else if (strcmp(Members[nMembers].mTier, "Platinum") == 0) Members[nMembers].mDisc = 15;
    else Members[nMembers].mDisc = 0;

    nMembers++;
    printf("Member registered.\n");
}

void deleteMembers() {
    int id, found = 0;
    printf("Enter Member ID: ");
    scanf("%d", &id);
    for (int i = 0; i < nMembers; i++) {
        if (Members[i].mId == id) {
            for (int j = i; j < nMembers - 1; j++) Members[j] = Members[j + 1];
            nMembers--;
            found = 1; break;
        }
    }
    if (found) printf("Member deleted.\n");
}

void viewMembers() {
    printf("\nID\tNAME\tTIER\tDISC%%\n");
    for (int i = 0; i < nMembers; i++) 
        printf("%d\t%s\t%s\t%.0f%%\n", Members[i].mId, Members[i].mName, Members[i].mTier, Members[i].mDisc);
}

void recordSale(int code, char name[], int qty, float price) {
    if (nSales >= MAX_SALES) return;
    sales[nSales].pCode = code;
    strcpy(sales[nSales].pName, name);
    sales[nSales].qty = qty;
    sales[nSales].price = price;
    sales[nSales].total = qty * price;
    totalRevenue += sales[nSales].total;
    nSales++;
}

float applyDiscount(int mid, float total) {
    for (int i = 0; i < nMembers; i++) {
        if (Members[i].mId == mid) {
            float d = total * (Members[i].mDisc / 100);
            totalDiscount += d;
            return d;
        }
    }
    return 0;
}

void salesManu() {
    int choice;
    while (1) {
        printf("\n--- SALES REPORTS ---\n1. Summary\n2. Product-wise\n3. Discounts\n0. Back\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) salesSummary();
        else if (choice == 2) productSales();
        else if (choice == 3) discountReport();
        else if (choice == 0) return;
    }
}

void salesSummary() {
    printf("\nTotal Revenue: %.2f\nTotal Discount: %.2f\nNet: %.2f\nBills: %d\n", totalRevenue, totalDiscount, totalRevenue - totalDiscount, totalBills);
}

void productSales() {
    printf("\nCODE\tNAME\tQTY\tTOTAL\n");
    for (int i = 0; i < nSales; i++) 
        printf("%d\t%s\t%d\t%.2f\n", sales[i].pCode, sales[i].pName, sales[i].qty, sales[i].total);
}

void discountReport() {
    viewMembers();
}

void staff() {
    int choice;
    while (1) {
        printf("\n--- STAFF PORTAL ---\n1. View Inventory\n2. View Members\n3. Add Member\n0. Logout\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) view();
        else if (choice == 2) viewMembers();
        else if (choice == 3) addMembers();
        else if (choice == 0) return;
    }
}