void addMembers(){
    int count, i;
    printf("\nHow many Members to be Added: ");
    scanf("%d", &count);

    for(i=0; i<count; i++){
        if(nMembers>=MAX_MEMBERS){
            printf("Member limit reached!\n");
            break;
        }

        printf("\nMember ID: ");
        scanf("%d", &Members[nMembers].mId);

        printf("Name: ");
        scanf("%s", Members[nMembers].mName);

        printf("Total Amount Spent: ");
        scanf("%f", &Members[nMembers].mSpent);

        printf("Tier (Silver/Gold/Platinum): ");
        scanf("%s", Members[nMembers].mTier);


        if(strcmp(Members[nMembers].mTier, "Silver") == 0){
            Members[nMembers].mDisc = 5;
		}else if(strcmp(Members[nMembers].mTier, "Gold") == 0){
            Members[nMembers].mDisc = 10;
		}else if(strcmp(Members[nMembers].mTier, "Platinum") == 0){
            Members[nMembers].mDisc = 15;
		}else{
            Members[nMembers].mDisc = 0;
		}
        nMembers++;
    }
    printf("\nMember(s) Added Successfully!\n");
    members();
}