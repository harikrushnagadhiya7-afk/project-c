void discountReport(){
    int i;
	printf("\nMEMBER DISCOUNT REPORT\n");
    printf("ID\tNAME\tSPENT\tDISCOUNT\n");
    printf("----------------------------------\n");

    for(i = 0; i < nMembers; i++){
        printf("%d\t%s\t%.2f\t%.2f%%\n",
               Members[i].mId,
               Members[i].mName,
               Members[i].mSpent,
               Members[i].mDisc);
    }
}