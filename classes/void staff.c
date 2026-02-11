void staff(){
	int choice;
	printf("Enter 1 to View Inventory\n");
	printf("Enter 2 to Show Members\n");
	printf("Enter 3 to Add New Member\n");
	printf("Enter 4 to Remove Old Member\n");
	printf("Enter 0 to Go Back\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
	
	switch(choice){
		case 1:
			//view();
			break;
		case 2:
			//viewMembers();
			break;
		case 3:
			//addMembers();
			break;
		case 4:
			//removeMembers();
			break;
		case 0:
			mainManu();
			break;
		default:
			printf("Invalid Option!\n");
			break;
	}
}