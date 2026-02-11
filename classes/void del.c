void del(){
    int code, found=0, i, j;
    printf("Enter code to delete: ");
    scanf("%d", &code);

    for(i=0; i<nProducts; i++){
        if(shop[i].pCode==code){
            for(j=i; j<nProducts-1; j++){
                shop[j]=shop[j+1];
            }
            nProducts--;
            found=1;
            printf("Product Deleted Successfully!\n");
            break;
        }
    }

    if(!found){
        printf("Product Code Not Found!\n");
    }
    
	inventory();
}