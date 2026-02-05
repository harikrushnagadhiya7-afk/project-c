#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_ITEMS 100
#define MAX_MEMBERS 100
#define MAX_CART 50

char ad_user[10]="admin";
char ad_pass[10]="admin";
char sf_user[10]="staff";
char sf_pass[10]="staff";

//for admin use >>> username: admin; password: admin
//for staff use >>> username: staff; password: staff

void mainManu();
void admin();
void adminDashboard();
void inventory();
void add();
void login();
void view();
void del();
void edit();
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
void staffDashboard();
void loadDefaultProducts();
void printHeader(char title[]);
void printLine();

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

int main(){
    loadDefaultProducts(); // Load 5 default products on startup
    mainManu();
    return 0;
}

void printHeader(char title[]){
    int i, len = strlen(title);
    printf("\n");
    for(i=0; i<60; i++) printf("=");
    printf("\n");
    printf("%*s\n", (60+len)/2, title);
    for(i=0; i<60; i++) printf("=");
    printf("\n");
}

void printLine(){
    int i;
    for(i=0; i<60; i++) printf("-");
    printf("\n");
}

void loadDefaultProducts(){
    // Product 1: Milk
    shop[0].pCode = 101;
    strcpy(shop[0].pName, "Milk");
    shop[0].pPrice = 55.00;
    shop[0].pStock = 50;
    strcpy(shop[0].pCategory, "Dairy");
    
    // Product 2: Bread
    shop[1].pCode = 102;
    strcpy(shop[1].pName, "Bread");
    shop[1].pPrice = 40.00;
    shop[1].pStock = 30;
    strcpy(shop[1].pCategory, "Bakery");
    
    // Product 3: Rice (1kg)
    shop[2].pCode = 103;
    strcpy(shop[2].pName, "Rice_1kg");
    shop[2].pPrice = 65.00;
    shop[2].pStock = 100;
    strcpy(shop[2].pCategory, "Grains");
    
    // Product 4: Sugar (1kg)
    shop[3].pCode = 104;
    strcpy(shop[3].pName, "Sugar_1kg");
    shop[3].pPrice = 50.00;
    shop[3].pStock = 80;
    strcpy(shop[3].pCategory, "Groceries");
    
    // Product 5: Tea Powder
    shop[4].pCode = 105;
    strcpy(shop[4].pName, "Tea_Powder");
    shop[4].pPrice = 120.00;
    shop[4].pStock = 45;
    strcpy(shop[4].pCategory, "Beverages");
    
    nProducts = 5;
}

void mainManu(){
    int choice;
    while(1){
        printHeader("AYH MART - SELF CHECKOUT SYSTEM");
        printf("\n  [1] Customer Self-Checkout\n");
        printf("  [2] Staff / Admin Login\n");
        printf("  [3] View Store Info\n");
        printf("  [0] Exit Application\n");
        printLine();
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                cust();
                break;
            case 2:
                admin();
                break;
            case 3:
                info();
                break;
            case 0:
                printf("\n  Thank you for using AYH Mart!\n\n");
                return;
            default:
                printf("\n  [ERROR] Invalid Option! Please try again.\n");
                break;
        }
    }
}

void admin(){
	login();
} 

void login(){
	char username[10], password[10];
	
    printHeader("LOGIN PORTAL");
	printf("\n  Enter Username: ");
	scanf("%s",username);
	printf("  Enter Password: ");
	scanf("%s",password);
	
	if(strcmp(username,ad_user)==0 && strcmp(password,ad_pass)==0){
		printf("\n  [SUCCESS] Logged in as Admin...\n");
		adminDashboard();
	}else if(strcmp(username,sf_user)==0 && strcmp(password,sf_pass)==0){
		printf("\n  [SUCCESS] Logged in as Staff...\n");
		staffDashboard();
	}else{
		printf("\n  [ERROR] Incorrect Username or Password!\n");
        mainManu();
	}
}

void adminDashboard() {
	int choice;
    printHeader("ADMIN PORTAL");
	printf("\n  [1] Inventory Management\n");
	printf("  [2] Member Management\n");
	printf("  [3] Sales Reports\n");
	printf("  [4] Staff Portal\n");
	printf("  [0] Logout\n");
   	printLine();
	printf("  Enter your choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			inventory();
			break;
		case 2:
			members();
			break;
		case 3:
			salesManu();
			break;
		case 4:
			staffDashboard();
			break;
		case 0:
			printf("\n  [INFO] Logging out...\n\n");
			mainManu();
			break;
		default:
			printf("\n  [ERROR] Invalid Option! Please try again.\n");
			adminDashboard();
			break;
	}
}

void inventory(){
    int choice;
    printHeader("INVENTORY MANAGEMENT");
    printf("\n  [1] Add Product\n");
    printf("  [2] Edit Product\n");
    printf("  [3] Delete Product\n");
    printf("  [4] View All Products\n");
    printf("  [0] Back to Admin Dashboard\n");
    printLine();
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            del();
            break;
        case 4:
            view();
            break;
        case 0:
            adminDashboard();
            break;
        default:
            printf("\n  [ERROR] Invalid Option!\n");
            inventory();
    }
}

void add(){
	int count,i;
    printf("\n\n  How many products to add: "); 
	scanf("%d", &count);
    
	for (i=0; i<count; i++) {
        if (nProducts>=MAX_ITEMS){
        	printf("\n  [ERROR] Product limit reached!\n");
        	inventory();
            return;
		}else{
			printf("\n  --- Product %d ---\n", i+1);
            printf("  Code: "); 
			scanf("%d", &shop[nProducts].pCode);
        	printf("  Name: "); 
			scanf(" %s", shop[nProducts].pName);
        	printf("  Price: "); 
			scanf("%f", &shop[nProducts].pPrice);
        	printf("  Stock: "); 
			scanf("%d", &shop[nProducts].pStock);
        	printf("  Category: "); 
			scanf("%s", shop[nProducts].pCategory);
        	nProducts++;
    	}
    }
    
	printf("\n  [SUCCESS] Product(s) Added Successfully!\n");
    inventory();
}

void edit(){
    int code, found=0, i, choice;
    printf("\n  Enter Product Code to Edit: ");
    scanf("%d", &code);
    
    for(i=0; i<nProducts; i++){
        if(shop[i].pCode == code){
            found = 1;
            printf("\n  Current Product Details:\n");
            printf("  Code: %d\n", shop[i].pCode);
            printf("  Name: %s\n", shop[i].pName);
            printf("  Price: %.2f\n", shop[i].pPrice);
            printf("  Stock: %d\n", shop[i].pStock);
            printf("  Category: %s\n", shop[i].pCategory);
            
            printf("\n  What do you want to edit?\n");
            printf("  [1] Name\n");
            printf("  [2] Price\n");
            printf("  [3] Stock\n");
            printf("  [4] Category\n");
            printf("  [5] Edit All\n");
            printf("  [0] Cancel\n");
            printf("  Enter choice: ");
            scanf("%d", &choice);
            
            switch(choice){
                case 1:
                    printf("  New Name: ");
                    scanf(" %s", shop[i].pName);
                    printf("  [SUCCESS] Name updated!\n");
                    break;
                case 2:
                    printf("  New Price: ");
                    scanf("%f", &shop[i].pPrice);
                    printf("  [SUCCESS] Price updated!\n");
                    break;
                case 3:
                    printf("  New Stock: ");
                    scanf("%d", &shop[i].pStock);
                    printf("  [SUCCESS] Stock updated!\n");
                    break;
                case 4:
                    printf("  New Category: ");
                    scanf("%s", shop[i].pCategory);
                    printf("  [SUCCESS] Category updated!\n");
                    break;
                case 5:
                    printf("  New Name: ");
                    scanf(" %s", shop[i].pName);
                    printf("  New Price: ");
                    scanf("%f", &shop[i].pPrice);
                    printf("  New Stock: ");
                    scanf("%d", &shop[i].pStock);
                    printf("  New Category: ");
                    scanf("%s", shop[i].pCategory);
                    printf("  [SUCCESS] All fields updated!\n");
                    break;
                case 0:
                    printf("  [INFO] Edit cancelled.\n");
                    break;
                default:
                    printf("  [ERROR] Invalid choice!\n");
            }
            break;
        }
    }
    
    if(!found){
        printf("\n  [ERROR] Product Code not found!\n");
    }
    
    inventory();
}

void view(){
	int i;
    printHeader("AVAILABLE PRODUCTS");
   
    if (nProducts==0){
        printf("\n  [INFO] No products in inventory.\n\n");
    }else{
    	printf("\n%-8s %-20s %-10s %-10s %-15s\n", "CODE", "NAME", "PRICE", "STOCK", "CATEGORY");
    	printLine();
    	for (i = 0; i < nProducts; i++){
            printf("%-8d %-20s %-10.2f %-10d %-15s\n",
			shop[i].pCode, shop[i].pName, shop[i].pPrice,
    		shop[i].pStock, shop[i].pCategory);
    	}
        printf("\n");
	}
	inventory();
}

void del(){
    int code, found=0, i, j;
    printf("\n  Enter Product Code to delete: ");
    scanf("%d", &code);

    for(i=0; i<nProducts; i++){
        if(shop[i].pCode==code){
            for(j=i; j<nProducts-1; j++){
                shop[j]=shop[j+1];
            }
            nProducts--;
            found=1;
            printf("\n  [SUCCESS] Product Deleted Successfully!\n");
            break;
        }
    }

    if(!found){
        printf("\n  [ERROR] Product Code Not Found!\n");
    }
    
	inventory();
}

void info(){
    printHeader("STORE INFORMATION");
	printf("\n  Store Name    : AYH Mart\n");
	printf("  Location      : Surat, India\n");
	printf("  Timing        : 9 AM to 10 PM\n");
	printf("  Contact       : +91 1234567890\n");
	printf("  Email         : info@ayhmart.com\n");
	printf("  Developed By  : Aum, Yesh, HariKrushna\n\n");
	mainManu();
}

void cust(){
    int choice, i;
    printHeader("CUSTOMER MENU");
    printf("\n  [1] View Store Products\n");
    printf("  [2] Search for a Product\n");
    printf("  [3] Add Item to Cart\n");
    printf("  [4] View My Cart\n");
    printf("  [5] Checkout\n");
    printf("  [0] Return to Main Menu\n");
    printLine();
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            custView();
            break;
        case 2:
			search();
			break;
		case 3:
			printf("\n");
            printHeader("AVAILABLE PRODUCTS");
			if(nProducts==0){
				printf("\n  [INFO] No products available.\n\n");
   			}else{
				printf("\n%-8s %-20s %-10s %-10s %-15s\n", "CODE", "NAME", "PRICE", "STOCK", "CATEGORY");
				printLine();
				for(i=0; i<nProducts; i++) {
    				printf("%-8d %-20s %-10.2f %-10d %-15s\n", 
                        shop[i].pCode, shop[i].pName, shop[i].pPrice, 
                        shop[i].pStock, shop[i].pCategory);
    			}
                printf("\n");
			}
    		addCart();
    		break;
		case 4:
    		viewCart();
    		break;
		case 5:
    		checkout();
    		break;
        case 0:
        	mainManu();
            break;
        default:
            printf("\n  [ERROR] Invalid Option!\n");
            cust();
    }
}

void custView(){
	int i;
    printHeader("AVAILABLE PRODUCTS");
	
    if (nProducts==0) {
        printf("\n  [INFO] No products available.\n\n");
    }else{
    	printf("\n%-8s %-20s %-10s %-10s %-15s\n", "CODE", "NAME", "PRICE", "STOCK", "CATEGORY");
    	printLine();
    	for (i = 0; i < nProducts; i++){
        printf("%-8d %-20s %-10.2f %-10d %-15s\n",
			shop[i].pCode, shop[i].pName, shop[i].pPrice,
    		shop[i].pStock, shop[i].pCategory);
    	}
        printf("\n");
	}
	cust();
}

void search(){
    int code, found=0, i;
    printf("\n  Enter Product Code to search: ");
    scanf("%d", &code);

    for(i=0; i<nProducts; i++){
        if(shop[i].pCode == code){
            found = 1;
            printf("\n  ===== PRODUCT FOUND =====\n");
            printf("  Product Code     : %d\n", shop[i].pCode);
            printf("  Product Name     : %s\n", shop[i].pName);
            printf("  Product Price    : Rs. %.2f\n", shop[i].pPrice);
            printf("  Product Stock    : %d units\n", shop[i].pStock);
            printf("  Product Category : %s\n", shop[i].pCategory);
            printf("  =========================\n\n");
            break;
        }
    }

    if(!found){
        printf("\n  [ERROR] Product not found!\n\n");
    }
    
    cust();
}

void addCart(){
    int code, qty, found=0, i;
    char confirm;
    
    if(cartCount>=MAX_CART){
    	printf("\n  [ERROR] Cart is full!\n");
    	cust();
    	return;
	}

    printf("  Enter Product Code: ");
    scanf("%d", &code);
    printf("  Enter Quantity: ");
    scanf("%d", &qty);
	
    for(i=0; i<nProducts; i++){
        if(shop[i].pCode==code){
            if(shop[i].pStock>=qty){
                // Verification before adding to cart
                printf("\n  ----- VERIFY DETAILS -----\n");
                printf("  Product Name  : %s\n", shop[i].pName);
                printf("  Unit Price    : Rs. %.2f\n", shop[i].pPrice);
                printf("  Quantity      : %d\n", qty);
                printf("  Total Price   : Rs. %.2f\n", shop[i].pPrice * qty);
                printf("  --------------------------\n");
                printf("  Confirm adding to cart? (y/n): ");
                scanf(" %c", &confirm);
                
                if(confirm == 'y' || confirm == 'Y'){
                    cart[cartCount].code=shop[i].pCode;
                    strcpy(cart[cartCount].name, shop[i].pName);
                    cart[cartCount].price=shop[i].pPrice;
                    cart[cartCount].qty=qty;

                    shop[i].pStock-=qty;
                    cartCount++;
                    found=1;
                    printf("\n  [SUCCESS] Item Added to Cart!\n");
                } else {
                    printf("\n  [INFO] Item not added to cart.\n");
                }
            } else {
                printf("\n  [ERROR] Insufficient stock! Available: %d\n", shop[i].pStock);
            }
            break;
        }
    }

    if(!found && confirm != 'n' && confirm != 'N'){
        printf("\n  [ERROR] Product unavailable!\n");
    }
    cust();
}

void viewCart(){
    float total=0;
	int i;
	
    if(cartCount==0){
        printf("\n  [INFO] Cart is empty!\n");
    } else {
        printHeader("MY SHOPPING CART");
        printf("\n%-8s %-20s %-10s %-8s %-10s\n", "CODE", "NAME", "PRICE", "QTY", "TOTAL");
        printLine();
        for(i=0; i<cartCount; i++){
            float amt=cart[i].price*cart[i].qty;
            total+=amt;
            printf("%-8d %-20s %-10.2f %-8d %-10.2f\n", 
                cart[i].code, cart[i].name, cart[i].price, cart[i].qty, amt);
        }
        printLine();
        printf("%48s %.2f\n", "Grand Total: Rs.", total);
        printf("\n");
    }
    
    cust();
}

void checkout(){
    int mid, i;
    float total=0, discount=0, finalAmount;

    if(cartCount==0){
        printf("\n  [ERROR] Cart is empty. Add items first.\n");
        cust();
        return;
    }

    for(i=0; i<cartCount; i++){
        total += cart[i].price * cart[i].qty;
	}

    for(i=0; i<cartCount; i++){
        recordSale(cart[i].code, cart[i].name, cart[i].qty, cart[i].price);
	}

    printHeader("CHECKOUT");
    printf("\n  Enter Member ID (0 if not a member): ");
    scanf("%d", &mid);

    discount=applyDiscount(mid, total);
    finalAmount=total-discount;

    printf("\n");
    printLine();
    printf("  Subtotal        : Rs. %.2f\n", total);
    printf("  Discount        : Rs. %.2f\n", discount);
    printLine();
    printf("  PAYABLE AMOUNT  : Rs. %.2f\n", finalAmount);
    printLine();
	
	billing(finalAmount);
    totalBills++;
    cartCount=0;
}

void billing(float finalAmount){
	float payAmount;
	printf("\n  Enter Cash Amount: Rs. ");
	scanf("%f", &payAmount);
	
	if(payAmount >= finalAmount){
        float change = payAmount - finalAmount;
		printf("\n  [SUCCESS] Payment Successful!\n");
        if(change > 0){
            printf("  Your Change: Rs. %.2f\n", change);
        }
        printf("\n  ========================================\n");
        printf("     THANK YOU FOR SHOPPING AT AYH MART!\n");
        printf("            VISIT AGAIN SOON!\n");
        printf("  ========================================\n\n");
		mainManu();
	}else{
		printf("\n  [ERROR] Insufficient amount! Please pay Rs. %.2f\n", finalAmount);
		billing(finalAmount);
	}
}                          

void members(){
    int choice;
    
    printHeader("MEMBER MANAGEMENT");
    printf("\n  [1] Add New Member\n");
    printf("  [2] Delete Member\n");
    printf("  [3] View All Members\n");
    printf("  [0] Back to Admin Dashboard\n");
    printLine();
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            addMembers();
            break;
        case 2:
            deleteMembers();
            break;
        case 3:
            viewMembers();
            break;
        case 0:
            adminDashboard();
            break;
        default:
            printf("\n  [ERROR] Invalid Option!\n");
            members();
    }
}

void addMembers(){
    int count, i;
    char tierInput[20];
    printf("\n  How many Members to add: ");
    scanf("%d", &count);

    for(i=0; i<count; i++){
        if(nMembers>=MAX_MEMBERS){
            printf("\n  [ERROR] Member limit reached!\n");
            break;
        }

        printf("\n  --- Member %d ---\n", i+1);
        printf("  Member ID: ");
        scanf("%d", &Members[nMembers].mId);

        printf("  Name: ");
        scanf("%s", Members[nMembers].mName);

        printf("  Total Amount Spent: Rs. ");
        scanf("%f", &Members[nMembers].mSpent);

        // Tier validation
        while(1){
            printf("  Tier (Silver/s, Gold/g, Platinum/p): ");
            scanf("%s", tierInput);
            
            // Convert to lowercase for comparison
            for(int j=0; tierInput[j]; j++){
                tierInput[j] = tolower(tierInput[j]);
            }
            
            if(strcmp(tierInput, "silver") == 0 || strcmp(tierInput, "s") == 0){
                strcpy(Members[nMembers].mTier, "Silver");
                Members[nMembers].mDisc = 5.0;
                break;
            }else if(strcmp(tierInput, "gold") == 0 || strcmp(tierInput, "g") == 0){
                strcpy(Members[nMembers].mTier, "Gold");
                Members[nMembers].mDisc = 10.0;
                break;
            }else if(strcmp(tierInput, "platinum") == 0 || strcmp(tierInput, "p") == 0){
                strcpy(Members[nMembers].mTier, "Platinum");
                Members[nMembers].mDisc = 15.0;
                break;
            }else{
                printf("  [ERROR] Invalid tier! Please enter Silver/s, Gold/g, or Platinum/p\n");
            }
        }
        
        nMembers++;
    }
    printf("\n  [SUCCESS] Member(s) Added Successfully!\n");
    members();
}

void deleteMembers(){
    int i, id, found=0, j;
    printf("\n  Enter Member ID to delete: ");
    scanf("%d", &id);

    
    for(i=0; i<nMembers; i++){
        if(Members[i].mId==id){
            for(j=i; j<nMembers-1; j++){
                Members[j] = Members[j+1];
            }
            nMembers--;
            found=1;
            printf("\n  [SUCCESS] Member Deleted Successfully!\n");
            break;
        }
    }

	if(!found){
        printf("\n  [ERROR] Member ID not found!\n");
    }
    members();
}

void viewMembers(){
	int i;
    if(nMembers==0){
        printf("\n  [INFO] No Members Found.\n\n");
    }else{
        printHeader("MEMBER LIST");
        printf("\n%-8s %-20s %-12s %-12s %-10s\n", "ID", "NAME", "SPENT", "TIER", "DISCOUNT");
        printLine();
        for(i = 0; i < nMembers; i++){
            printf("%-8d %-20s %-12.2f %-12s %-10.2f%%\n",
                   Members[i].mId,
                   Members[i].mName,
                   Members[i].mSpent,
                   Members[i].mTier,
                   Members[i].mDisc);
        }
        printf("\n");
    }
    members();
}

void recordSale(int code, char name[], int qty, float price){
	if(nSales >= 500){
		return;
	}else{
    	sales[nSales].pCode=code;
    	strcpy(sales[nSales].pName, name);
    	sales[nSales].qty=qty;
    	sales[nSales].price=price;
    	sales[nSales].total=qty*price;
    	totalRevenue+=sales[nSales].total;
    	nSales++;
	}
}

float applyDiscount(int memberId, float billAmount){
    int i;
	for(i=0; i<nMembers; i++){
        if(Members[i].mId==memberId){
            float discount=billAmount*(Members[i].mDisc/100);
            Members[i].mSpent+=(billAmount-discount);
            totalDiscount+=discount;
            return discount;
        }
    }
    return 0;
}

void salesManu(){
    int choice;
    while(1){
        printHeader("SALES REPORTS");
        printf("\n  [1] Sales Summary\n");
        printf("  [2] Product-wise Sales\n");
        printf("  [3] Member Discount Report\n");
        printf("  [0] Back to Admin Dashboard\n");
        printLine();
        printf("  Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                salesSummary();
                break;
            case 2:
                productSales();
                break;
            case 3:
                discountReport();
                break;
            case 0:
                adminDashboard();
                return;
            default:
                printf("\n  [ERROR] Invalid option!\n");
        }
    }
}

void salesSummary(){
    printHeader("SALES SUMMARY");
    printf("\n  Total Bills Generated : %d\n", totalBills);
    printf("  Total Items Sold      : %d\n", nSales);
    printf("  Total Revenue         : Rs. %.2f\n", totalRevenue);
    printf("  Total Discount Given  : Rs. %.2f\n", totalDiscount);
    printf("  Net Revenue           : Rs. %.2f\n\n", totalRevenue - totalDiscount);
}

void productSales(){
    int i;
    printHeader("PRODUCT SALES REPORT");
    printf("\n%-8s %-20s %-10s %-10s\n", "CODE", "NAME", "QTY", "TOTAL");
    printLine();

    for(i = 0; i < nSales; i++){
        printf("%-8d %-20s %-10d %-10.2f\n",
               sales[i].pCode,
               sales[i].pName,
               sales[i].qty,
               sales[i].total);
    }
    printf("\n");
}

void discountReport(){
    int i;
    printHeader("MEMBER DISCOUNT REPORT");
    printf("\n%-8s %-20s %-12s %-10s\n", "ID", "NAME", "SPENT", "DISCOUNT");
    printLine();

    for(i = 0; i < nMembers; i++){
        printf("%-8d %-20s %-12.2f %-10.2f%%\n",
               Members[i].mId,
               Members[i].mName,
               Members[i].mSpent,
               Members[i].mDisc);
    }
    printf("\n");
}

void staffDashboard(){
	int choice;
    printHeader("STAFF PORTAL");
	printf("\n  [1] View Inventory\n");
	printf("  [2] View Members\n");
	printf("  [3] Add New Member\n");
	printf("  [4] Delete Member\n");
	printf("  [5] View Sales Summary\n");
	printf("  [0] Logout\n");
    printLine();
    printf("  Enter your choice: ");
    scanf("%d", &choice);
	
	switch(choice){
		case 1:
			view();
			break;
		case 2:
			viewMembers();
			break;
		case 3:
			addMembers();
			break;
		case 4:
			deleteMembers();
			break;
		case 5:
			salesSummary();
			staffDashboard();
			break;
		case 0:
			printf("\n  [INFO] Logging out...\n\n");
			mainManu();
			break;
		default:
			printf("\n  [ERROR] Invalid Option!\n");
			staffDashboard();
			break;
	}
}
