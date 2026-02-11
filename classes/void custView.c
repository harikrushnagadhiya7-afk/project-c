void custView(){
	int i;
	printf("\n\nAVAILABLE PRODUCTS \n");
	
    if (nProducts==0) {
        printf("No products in shop.\n");
    }else{
    	printf("\nCODE \t NAME \t PRICE \t STOCK \t CATEGORY\n");
    	printf("------------------------------------------------\n");
    	for (i=0; i<nProducts; i++) {
        printf("%d \t %s \t %.2f \t %d \t %s\n",
			shop[i].pCode, 
			shop[i].pName, 
			shop[i].pPrice,
    		shop[i].pStock, 
			shop[i].pCategory);
    	}
	}
	
	cust();
}