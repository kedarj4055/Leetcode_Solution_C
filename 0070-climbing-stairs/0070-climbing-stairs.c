int climbStairs(int n) {
    int a=1,b=2,c,i;
    if(n==1)
    return 1;
    if(n==2)
    return 2;
    for(i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}