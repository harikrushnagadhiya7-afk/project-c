void add(){
	int count,i;
    printf("\n\nHow many products: "); 
	scanf("%d", &count);
    
	for (i=0; i<count; i++) {
        if (nProducts>=MAX_ITEMS){
        	printf("Product MaxOut!");
        	inventory();
		}else{
			printf("\nCode: "); 
			scanf("%d", &shop[nProducts].pCode);
        	printf("Name: "); 
			scanf(" %s", shop[nProducts].pName);
        	printf("Price: "); 
			scanf("%f", &shop[nProducts].pPrice);
        	printf("Stock: "); 
			scanf("%d", &shop[nProducts].pStock);
        	printf("Cat: "); 
			scanf("%s", shop[nProducts].pCategory);
        	nProducts++;
    	}
    }
    
	printf("\nProduct Added");
    inventory();
}
