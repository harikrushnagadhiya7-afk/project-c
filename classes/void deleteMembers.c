void deleteMembers(){
    int i, id, found=0, j;
    printf("Enter Member ID to delete: ");
    scanf("%d", &id);

    
    for(i=0; i<nMembers; i++){
        if(Members[i].mId==id){
            for(j=i; j<nMembers-1; j++){
                Members[j] = Members[j+1];
            }
            nMembers--;
            found=1;
            printf("Member Deleted Successfully!\n");
            break;
        }
    }

	if(!found){
        printf("Member ID not found!\n");
    }
    members();
}