# AYH MART - Self Checkout System

A comprehensive Point of Sale (POS) system built in C language for self-checkout functionality with inventory management, membership programs, and sales reporting.

---

## 📋 Project Information

**Project Name:** AYH Mart Self Checkout System  
**Language:** C  
**Developed By:** Aum, Yesh, HariKrushna  
**Location:** Surat, India  

---

## ✨ Features

### 1. **Customer Portal**
- ✅ View all available products
- ✅ Search products by code
- ✅ Add items to shopping cart with verification
- ✅ View cart with detailed pricing
- ✅ Checkout with member discount support
- ✅ Cash payment with change calculation

### 2. **Admin Portal**
- ✅ Complete inventory management (Add, Edit, Delete, View)
- ✅ Member management (Add, Delete, View)
- ✅ Comprehensive sales reports:
  - Sales summary
  - Product-wise sales
  - Member discount reports
- ✅ Staff portal access

### 3. **Staff Portal**
- ✅ View inventory
- ✅ View member list
- ✅ Add new members
- ✅ Delete members
- ✅ View sales summary

### 4. **Inventory Management**
- ✅ 5 default products pre-loaded on startup
- ✅ Add new products
- ✅ **Edit existing products** (Name, Price, Stock, Category, or All)
- ✅ Delete products
- ✅ View all products with formatted display

### 5. **Membership System**
- ✅ Three tier system:
  - **Silver** (5% discount) - accepts "Silver" or "s"
  - **Gold** (10% discount) - accepts "Gold" or "g"
  - **Platinum** (15% discount) - accepts "Platinum" or "p"
- ✅ **Strict tier validation** - only accepts valid tier names
- ✅ Track member spending
- ✅ Automatic discount calculation
- ✅ **Discount properly displayed in member view**

### 6. **Enhanced Features**
- ✅ **Product verification before adding to cart** with price display
- ✅ **Improved search format** with detailed product information:
  ```
  Product Code     : XXX
  Product Name     : XXX
  Product Price    : Rs. XXX
  Product Stock    : XXX units
  Product Category : XXX
  ```
- ✅ **Fixed billing bug** - now accepts float values and calculates change
- ✅ **Professional styling** with headers, lines, and formatted output

---

## 🏗️ System Structure

### Data Structures

```c
struct Product {
    int pCode;
    char pName[50];
    float pPrice;
    int pStock;
    char pCategory[30];
}

struct Member {
    int mId;
    char mName[50];
    float mSpent;
    char mTier[20];
    float mDisc;
}

struct CartItem {
    int code;
    char name[50];
    float price;
    int qty;
}

struct Sale {
    int pCode;
    char pName[50];
    int qty;
    float price;
    float total;
}
```

---

## 🔐 Login Credentials

### Admin Access
- **Username:** admin
- **Password:** admin

### Staff Access
- **Username:** staff
- **Password:** staff

---

## 📦 Default Products

The system comes pre-loaded with 5 products:

| Code | Product Name | Price (Rs.) | Stock | Category  |
|------|-------------|-------------|-------|-----------|
| 101  | Milk        | 55.00       | 50    | Dairy     |
| 102  | Bread       | 40.00       | 30    | Bakery    |
| 103  | Rice_1kg    | 65.00       | 100   | Grains    |
| 104  | Sugar_1kg   | 50.00       | 80    | Groceries |
| 105  | Tea_Powder  | 120.00      | 45    | Beverages |

---

## 🚀 How to Compile and Run

### Compilation
```bash
gcc main.c -o checkout
```

### Run
```bash
./checkout
```

### For Windows
```bash
gcc main.c -o checkout.exe
checkout.exe
```

---

## 🎯 Usage Guide

### For Customers:
1. Select **"Customer Self-Checkout"** from main menu
2. Browse products or search by code
3. Add items to cart (with verification)
4. View cart to review items
5. Proceed to checkout
6. Enter member ID (or 0 for non-members)
7. Pay the final amount

### For Admin:
1. Login with admin credentials
2. Access inventory, members, or sales reports
3. Manage products (Add/Edit/Delete)
4. Manage members
5. View detailed sales analytics

### For Staff:
1. Login with staff credentials
2. View inventory and members
3. Add or remove members
4. View sales summary

---

## 🐛 Known Issues & Limitations

### Fixed Issues (Resolved in Latest Version):
1. ✅ **FIXED:** Billing function now accepts decimal values instead of integers
2. ✅ **FIXED:** Member discount now properly displayed in view members
3. ✅ **FIXED:** Tier validation now strictly enforces Silver/s, Gold/g, Platinum/p
4. ✅ **FIXED:** Search product format improved with detailed view
5. ✅ **FIXED:** Cart addition now includes verification step

### Current Limitations:
1. **No Data Persistence:** All data is lost when program exits (no file I/O)
2. **Limited Password Security:** Passwords stored in plain text
3. **Fixed Array Sizes:** 
   - Max 100 products (MAX_ITEMS)
   - Max 100 members (MAX_MEMBERS)
   - Max 50 cart items (MAX_CART)
   - Max 500 sales records
4. **No Multi-session Support:** Only one user can use the system at a time
5. **No Barcode Scanner Support:** Manual code entry required
6. **Limited Error Recovery:** Some invalid inputs may cause unexpected behavior
7. **No Receipt Printing:** Only screen display available
8. **Cash-Only Payments:** No credit/debit card or digital payment support
9. **No Product Image Support:** Text-based product display only
10. **Single Currency:** Only supports Rupees (Rs.)

### Potential Improvements:
1. Add file I/O for data persistence
2. Implement password hashing
3. Add dynamic memory allocation for unlimited records
4. Implement receipt generation (text file)
5. Add more payment methods
6. Implement product categories filtering
7. Add low stock alerts
8. Implement sales trends analysis
9. Add tax calculation support
10. Create backup and restore functionality

---

## 📊 System Limits

- **Maximum Products:** 100
- **Maximum Members:** 100
- **Maximum Cart Items:** 50
- **Maximum Sales Records:** 500
- **Product Name Length:** 50 characters
- **Category Name Length:** 30 characters
- **Member Name Length:** 50 characters

---

## 🔧 Technical Details

### Compiler Requirements:
- C compiler (GCC recommended)
- Standard C library support
- No external dependencies

### Platform Compatibility:
- ✅ Linux
- ✅ Windows
- ✅ macOS
- ✅ Any system with C compiler

### Memory Usage:
- Static memory allocation
- Approximate memory: ~200KB

---

## 📝 Code Structure

```
main.c
├── Main Functions
│   ├── mainManu()          - Main menu navigation
│   ├── loadDefaultProducts() - Initialize default products
│   └── login()             - Authentication system
│
├── Admin Functions
│   ├── adminDashboard()    - Admin menu
│   ├── inventory()         - Inventory management
│   ├── add()               - Add products
│   ├── edit()              - Edit products
│   ├── del()               - Delete products
│   ├── view()              - View products
│   └── members()           - Member management
│
├── Staff Functions
│   └── staffDashboard()    - Staff portal
│
├── Customer Functions
│   ├── cust()              - Customer menu
│   ├── custView()          - View products
│   ├── search()            - Search products
│   ├── addCart()           - Add to cart
│   ├── viewCart()          - View cart
│   ├── checkout()          - Checkout process
│   └── billing()           - Payment processing
│
├── Member Functions
│   ├── addMembers()        - Add members
│   ├── deleteMembers()     - Delete members
│   ├── viewMembers()       - View members
│   └── applyDiscount()     - Calculate discounts
│
├── Sales Functions
│   ├── salesManu()         - Sales menu
│   ├── salesSummary()      - Sales summary
│   ├── productSales()      - Product-wise sales
│   ├── discountReport()    - Discount report
│   └── recordSale()        - Record sale transaction
│
└── Utility Functions
    ├── printHeader()       - Print styled header
    ├── printLine()         - Print separator line
    └── info()              - Store information
```

---

## 💡 Tips for Users

1. **For Best Experience:**
   - Use unique product codes
   - Keep member IDs unique
   - Regularly check sales reports
   - Monitor inventory stock levels

2. **Member Tiers:**
   - Enter 's' or 'Silver' for Silver tier
   - Enter 'g' or 'Gold' for Gold tier
   - Enter 'p' or 'Platinum' for Platinum tier

3. **Checkout Process:**
   - Always verify items before adding to cart
   - Enter exact member ID for discounts
   - Have exact cash or more for payment

---

## 📞 Support & Contact

For any issues or suggestions:
- **Email:** info@ayhmart.com
- **Phone:** +91 1234567890
- **Location:** Surat, India

---

## 📄 License

This project is developed for educational purposes.

---

## 👥 Contributors

- **Aum** - Core Development
- **Yesh** - Feature Implementation
- **HariKrushna** - Testing & Documentation

---

## 🔄 Version History

### Version 2.0 (Current)
- ✅ Added 5 default products
- ✅ Implemented product edit functionality
- ✅ Added strict tier validation
- ✅ Enhanced staff portal features
- ✅ Improved search product display format
- ✅ Added cart verification feature
- ✅ Fixed member discount display
- ✅ Fixed billing bug (float support)
- ✅ Added professional styling

### Version 1.0 (Initial)
- Basic POS functionality
- Simple inventory management
- Basic member system
- Sales tracking

---

**Thank you for using AYH Mart Self Checkout System!**
