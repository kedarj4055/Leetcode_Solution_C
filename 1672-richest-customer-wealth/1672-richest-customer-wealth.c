int maximumWealth(int** a, int aS, int* aCS) {
    int i,j,sum,max=0;
    for(i=0;i<aS;i++){
        sum=0;
        for(j=0;j<aCS[i];j++){
            sum+=a[i][j];
        }
        if(sum>max)
        max=sum;
    }
    return max;
}