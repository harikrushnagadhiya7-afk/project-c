void cust(){
    int choice, i;
    printf("\nCUSTOMER MENU\n");
    printf("Enter 1 View Store Products\n");
    printf("Enter 2 Search for a Product\n");
    printf("Enter 3 Add Item to Basket\n");
    printf("Enter 4 View My Basket\n");
    printf("Enter 5 Final Checkout\n");
    printf("Enter 0 Return to Main Menu\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            custView();
            break;
        case 2:
			search();
			break;
		case 3:
			printf("\n\nAVAILABLE PRODUCTS \n");
			if(nProducts==0){
				printf("No products in shop.\n");
   			}else{
				printf("\nCODE \t NAME \t PRICE \t STOCK \t CATEGORY\n");
				printf("------------------------------------------------\n");
				for(i=0; i<nProducts; i++) {
    				printf("%d \t %s \t %.2f \t %d \t %s\n", shop[i].pCode, shop[i].pName, shop[i].pPrice, shop[i].pStock, shop[i].pCategory);
    			}
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
            printf("Invalid Option!\n");
    }
}