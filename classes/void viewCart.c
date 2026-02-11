void viewCart(){
    float total=0;
	int i;
	
    if(cartCount==0){
        printf("Cart is empty\n");
    } else {
        printf("\nCODE\tNAME\tPRICE\tQTY\tTOTAL\n");
        for(i=0; i<cartCount; i++){
            float amt=cart[i].price*cart[i].qty;
            total+=amt;
            printf("%d\t%s\t%.2f\t%d\t%.2f\n", cart[i].code, cart[i].name, cart[i].price, cart[i].qty, amt);
        }
        printf("Grand Total: %.2f\n", total);
    }
    
    cust();
}