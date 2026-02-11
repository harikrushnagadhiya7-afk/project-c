void salesManu(){
    int choice;
    while(1){
        printf("\nSALES REPORT\n");
        printf("1. Summary Report\n");
        printf("2. Product-wise Sales\n");
        printf("3. Member Discount Report\n");
        printf("0. Back\n");
        printf("Enter choice: ");
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
                return;
            default:
                printf("Invalid option\n");
        }
    }
}