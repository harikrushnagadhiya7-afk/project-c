void adminDashboard() {
	int choice;
	printf("Admin Portal\n");
	printf("Enter 1 Inventory\n");
	printf("Enter 2 Members\n");
	printf("Enter 3 Sales Report\n");
	printf("Enter 4 Staff\n");
	printf("Enter 0 logout\n");
   	printf("------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			inventory();
			break;
		case 2:
			members();
			break;
		case 3:
			salesManu();
			break;
		case 4:
			//staff();
			break;
		case 0:
			printf("\n\n\n");
			mainManu();
			break;
		default:
			printf("Invalid Option!\n");
			printf("\n\n\nEnter choice Again\n");
			adminDashboard();
			break;
	}
}
