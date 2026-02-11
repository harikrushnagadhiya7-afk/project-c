float applyDiscount(int memberId, float billAmount){
    int i;
	for(i=0; i<nMembers; i++){
        if(Members[i].mId==memberId){
            float discount=billAmount*(Members[i].mDisc/100);
            Members[i].mSpent+=(billAmount-discount);
            totalDiscount+=discount;
            return discount;
        }
    }
    return 0;
}
