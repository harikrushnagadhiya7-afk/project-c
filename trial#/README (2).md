# AYH Mart – Self Checkout System
> A console-based C application for a retail self-checkout experience.  
> Developed by **Aum, Yesh, HariKrushna** | Surat, India

---

## Table of Contents
1. [How to Compile & Run](#how-to-compile--run)
2. [Login Credentials](#login-credentials)
3. [Features](#features)
4. [Bugs Fixed in This Version](#bugs-fixed-in-this-version)
5. [Known Remaining Issues](#known-remaining-issues)
6. [Program Structure](#program-structure)

---

## How to Compile & Run

```bash
gcc ayhmart.c -o ayhmart
./ayhmart
```

Requires a C99-compatible compiler (GCC recommended).

---

## Login Credentials

| Role  | Username | Password |
|-------|----------|----------|
| Admin | admin    | admin    |
| Staff | staff    | staff    |

---

## Features

### Customer Portal
| Feature | Description |
|---------|-------------|
| View Products | Browse the full product catalogue with code, name, price, stock, and category |
| Search Product | Look up any item by its numeric product code; result shows a detailed formatted card |
| Add to Basket | Select a product and quantity; a confirmation box shows name, unit price, qty, and total before adding |
| View Basket | See all basket items with individual totals and a grand total |
| Checkout | Apply member discount, display payable amount, accept cash payment, and print change |

### Admin Portal
| Feature | Description |
|---------|-------------|
| Add Product(s) | Batch-add one or more products to inventory |
| Edit Product | Update name, price, stock, or category for any existing product by code |
| Delete Product | Remove a product from inventory by code |
| View Inventory | Formatted table of all products |
| Add Member | Register a new member with tier validation (Silver / Gold / Platinum) |
| Delete Member | Remove a registered member by ID |
| View Members | Display all members with ID, name, total spent, tier, and correct discount percentage |
| Sales Summary | Total bills, items sold, gross revenue, total discount, and net revenue |
| Product-wise Sales | Itemised list of every recorded sale |
| Member Discount Report | Per-member spend and discount percentage |

### Staff Portal
| Feature | Description |
|---------|-------------|
| View Inventory | Read-only view of all products |
| View Members | Read-only view of all registered members |
| Add Member | Register a new member (same validation as admin) |
| Remove Member | Delete an existing member by ID |
| View Sales Summary | Quick snapshot of revenue and billing totals |
| Search Product | Look up a product by code with the detailed formatted result |

### General / System
- 5 default products pre-loaded at startup (Rice, Milk, Bread, Shampoo, PenDrive)
- Unified styled output with separator lines and success/error indicators (`[✓]` / `[✗]` / `[!]`)
- Member tier discount: Silver = 5 %, Gold = 10 %, Platinum = 15 %
- Stock is automatically decremented when items are added to the basket
- Member's total spent is automatically updated on successful checkout

---

## Bugs Fixed in This Version

| # | Original Bug | Fix Applied |
|---|--------------|-------------|
| 1 | `billing()` used `int` parameter but prices are decimals, causing truncation for amounts like `₹49.99` | Changed parameter type to `float` |
| 2 | `scanf("%d", payAmount)` was missing the `&` address-of operator, causing undefined behaviour / crash | Changed to `scanf("%f", &payAmount)` |
| 3 | Member discount column in `viewMembers()` used `%.2f%%` which printed `5.00%` but staff/customer-facing display showed raw float (e.g. `5.000000`) | Unified to `%.0f%%` for a clean integer percentage across all views |
| 4 | `billing()` called `mainManu()` directly after payment even if `totalBills++` and `cartCount=0` were yet to execute inside `checkout()` — those lines were never reached on success path | Moved `totalBills++` and `cartCount=0` to execute *before* `billing()` is called |
| 5 | `inventory()` case 0 had no `break` after `adminDashboard()`, causing fall-through to the `default` case | Added explicit `break` (now handled structurally) |
| 6 | `members()` case 0 had the same missing `break` fall-through issue | Same fix applied |
| 7 | Staff portal menu items 1–4 were commented out (`//view(); //viewMembers(); //addMembers(); //removeMembers()`) — staff portal was non-functional | All four cases implemented; two new cases (Sales Summary, Search Product) also added |
| 8 | Tier input in `addMembers()` accepted any arbitrary string (e.g. "bronze", "vip") silently assigning 0% discount | Added a `while(1)` validation loop; only Silver/s, Gold/g, Platinum/p accepted |

---

## Known Remaining Issues

> These issues exist in the design/logic of the program and were **not** part of the current update scope.

| # | Location | Issue | Severity |
|---|----------|-------|----------|
| 1 | **All menus** | Navigation uses recursion instead of loops. Deep usage (many menu transitions in one session) will eventually cause a stack overflow. Menus should use `while` loops with a return flag instead. | High |
| 2 | **`addCart()`** | The same product code can be added to the cart multiple times as separate entries instead of incrementing quantity, leading to duplicate rows in `viewCart()`. | Medium |
| 3 | **`add()` / `addMembers()`** | No duplicate-code / duplicate-ID check — two products or members with the same code/ID can coexist, causing incorrect search and delete behaviour. | Medium |
| 4 | **`billing()`** | Recursive retry on insufficient cash payment will keep adding to the call stack; a loop is safer. | Medium |
| 5 | **`login()`** | Passwords are stored as plain-text global strings in the source code. There is no password change feature. | Medium |
| 6 | **All `scanf` calls** | No buffer-overflow protection on string inputs (e.g. `scanf("%s", name)` with no width limit). A very long input can overflow the fixed-size char arrays. | Medium |
| 7 | **Data persistence** | All data (products, members, sales) is lost when the program exits — there is no file save/load mechanism. | Medium |
| 8 | **`adminDashboard()`** | Case 4 ("Staff") is present in the menu but the function body is empty (commented out). | Low |
| 9 | **`search()` / `addCart()`** | After a failed search or cart-full condition the program calls `cust()` recursively rather than looping, deepening the call stack. | Low |
| 10 | **Sales array** | `sales[]` is capped at 500 entries. Once full, `recordSale()` silently drops new sales with no warning to the user. | Low |
| 11 | **Member tier capitalisation** | If a member is added via the staff portal and tier input is lowercase (e.g. `s`), the stored tier string is correctly set to `"Silver"`, but the original `addMembers` in the unmodified code would have stored the raw input. Consistent normalisation is now applied everywhere. | Low |
| 12 | **`cust()` case 3** | The product list is printed inline in `cust()` before calling `addCart()`, duplicating display logic that already exists in `custView()`. Minor code duplication. | Low |

---

## Program Structure

```
main()
├── mainManu()
│   ├── cust()              ← Customer self-checkout
│   │   ├── custView()
│   │   ├── search()
│   │   ├── addCart()
│   │   ├── viewCart()
│   │   └── checkout()
│   │       ├── recordSale()
│   │       ├── applyDiscount()
│   │       └── billing()
│   ├── admin()
│   │   └── login()
│   │       ├── adminDashboard()
│   │       │   ├── inventory()
│   │       │   │   ├── add()
│   │       │   │   ├── editProduct()   ← NEW
│   │       │   │   ├── del()
│   │       │   │   └── view()
│   │       │   ├── members()
│   │       │   │   ├── addMembers()
│   │       │   │   ├── deleteMembers()
│   │       │   │   └── viewMembers()
│   │       │   └── salesManu()
│   │       │       ├── salesSummary()
│   │       │       ├── productSales()
│   │       │       └── discountReport()
│   │       └── staff()             ← FULLY IMPLEMENTED
│   └── info()
```

---

*AYH Mart – Console Retail System | C Language Project*
