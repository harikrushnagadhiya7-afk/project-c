void salesSummary(){
    printf("\n===== SALES SUMMARY =====\n");
    printf("Total Bills Generated : %d\n", totalBills);
    printf("Total Items Sold      : %d\n", nSales);
    printf("Total Revenue         : %.2f\n", totalRevenue);
    printf("Total Discount Given  : %.2f\n", totalDiscount);
    printf("Net Revenue           : %.2f\n",totalRevenue - totalDiscount);
}