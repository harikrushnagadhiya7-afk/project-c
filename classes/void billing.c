void billing(int finalAmount){
	int payAmount;
	printf("Pay by Cash: ");
	scanf("%d", payAmount);
	
	if(payAmount==finalAmount){
		printf("Thank You Visit Again!");
		mainManu();
	}else{
		printf("Kindly Pay Approprate Amount");
		billing(finalAmount);
    	totalBills++;
    	cartCount=0;
	}
}