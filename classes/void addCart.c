void addCart(){
    int code, qty, found=0, i;
    
    if(cartCount>=MAX_CART){
    	printf("Cart is full!\n");
    	cust();
    	return;
	}

    printf("Enter Product Code: ");
    scanf("%d", &code);
    printf("Enter Quantity: ");
    scanf("%d", &qty);
	
    for(i=0; i<nProducts; i++){
        if(shop[i].pCode==code && shop[i].pStock>=qty){
            cart[cartCount].code=shop[i].pCode;
            strcpy(cart[cartCount].name, shop[i].pName);
            cart[cartCount].price=shop[i].pPrice;
            cart[cartCount].qty=qty;

            shop[i].pStock-=qty;
            cartCount++;
            found=1;
            printf("Item Added to Cart\n");
            break;
        }
    }

    if(!found){
        printf("Product unavailable or insufficient stock\n");
    }
    cust();
}