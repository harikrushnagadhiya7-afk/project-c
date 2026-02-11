void login(){
	char username[10], password[10];
	
	printf("\n\nEnter Username: ");
	scanf("%s",username);
	printf("Enter Password: ");
	scanf("%s",password);
	
	if(strcmp(username,ad_user)==0 && strcmp(password,ad_pass)==0){
		printf("Login as admin...\n\n");
		adminDashboard();
	}else if(strcmp(username,sf_user)==0 && strcmp(password,sf_pass)==0){
		printf("Login as staff...\n\n");
		staff();
	}else{
		printf("Enter correct Username or Password");
	}
}