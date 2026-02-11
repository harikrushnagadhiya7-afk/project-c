void inventory(){
    int choice;
    printf("\nInventory\n");
    printf("Enter 1 Add\n");
    printf("Enter 2 Delete\n");
    printf("Enter 3 View\n");
    printf("Enter 0 Back\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            view();
            break;
        case 0:
            adminDashboard();
        default:
            printf("Invalid Option!\n");
    }
}
