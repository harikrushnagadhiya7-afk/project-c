void recordSale(int code, char name[], int qty, float price){
	if(nSales >= 500){
		return;
	}else{
    	sales[nSales].pCode=code;
    	strcpy(sales[nSales].pName, name);
    	sales[nSales].qty=qty;
    	sales[nSales].price=price;
    	sales[nSales].total=qty*price;
    	totalRevenue+=sales[nSales].total;
    	nSales++;
	}
}