void members(){
    int choice;
    
	printf("\nMember Portal\n");
    printf("Enter 1 Add New Member\n");
    printf("Enter 2 Delete Old Members\n");
    printf("Enter 3 View all Members\n");
    printf("Enter 0 Back\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            addMembers();
            break;
        case 2:
            deleteMembers();
            break;
        case 3:
            viewMembers();
            break;
        case 0:
            adminDashboard();
        default:
            printf("Invalid Option!\n");
    }
}