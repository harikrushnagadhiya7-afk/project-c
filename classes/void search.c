void search(){
    int code, found=0, i;
    printf("Enter Product Code to Search: ");
    scanf("%d", &code);

    for(i=0; i<nProducts; i++){
        if(shop[i].pCode==code){
            printf("Found: %s | %.2f | Stock: %d\n", shop[i].pName, shop[i].pPrice, shop[i].pStock);
            found=1;
            break;
        }
    }

    if(!found){
        printf("Product Not Found\n");
    }

    cust();
}