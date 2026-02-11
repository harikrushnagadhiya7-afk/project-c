void mainManu(){
    int choice;
    while(1){
        printf("\nEnter 1 Customer Self-Checkout\n");
        printf("Enter 2 Staff / Admin Login\n");
        printf("Enter 3 View Store Info\n");
        printf("Enter 0 Exit Application\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                cust();
                break;
            case 2:
                admin();
                break;
            case 3:
                info();
                break;
            case 0:
                return;
            default:
                printf("Invalid Option!\n");
                break;
        }
    }
}