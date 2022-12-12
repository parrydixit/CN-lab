#include<stdio.h>

int compute(int a,int m,int n){
    int y=1;
    while(m>0){
        if(m%2==1)
            y= (y*a)%n;
        a= a*a%n;
        m/=2;
    }
    return y;
}

void main(){
    int p,g;
    printf("enter a prime number and a value of alpha: ");
    scanf("%d %d",&p,&g);

    int a,b,A,B;
    
    a=rand();
    printf("Xa: %d\n",a);
    A= compute(g,a,p);
    printf("Ya: %d\n",A);

    b=rand();
    printf("Xb: %d\n",b);
    B= compute(g,b,p);
    printf("Yb: %d\n",B);

    int keyA,keyB;
    
    keyA= compute(B,a,p);
    keyB= compute(A,b,p);
    printf("A private key: %d\nB private key: %d\n",keyA,keyB);

}