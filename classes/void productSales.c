void productSales(){
    printf("\nPRODUCT SALES REPORT\n");
    printf("CODE\tNAME\tQTY\tTOTAL\n");
    printf("----------------------------------\n");

    for(int i = 0; i < nSales; i++){
        printf("%d\t%s\t%d\t%.2f\n",
               sales[i].pCode,
               sales[i].pName,
               sales[i].qty,
               sales[i].total);
    }
}