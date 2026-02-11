void viewMembers(){
	int i;
    if(nMembers==0){
        printf("\nNo Members Found.\n");
    }else{
        printf("\nID\tNAME\tSPENT\tTIER\tDISCOUNT\n");
        printf("------------------------------------------\n");
        for(i = 0; i < nMembers; i++){
            printf("%d\t%s\t%.2f\t%s\t%.2f%%\n",
                   Members[i].mId,
                   Members[i].mName,
                   Members[i].mSpent,
                   Members[i].mTier,
                   Members[i].mDisc);
        }
    }
    members();
}