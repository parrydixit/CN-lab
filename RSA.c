#include<stdio.h>
#include<math.h>

int gcd(int a, int h){
    while(1){
        int temp= a%h;
        if(temp==0)
            return h;
        a=h;
        h=temp;
    }
}

void main(){
    int p,q,msg,e=2,d=e;

    printf("enter two prime numbers: ");
    scanf("%d %d",&p,&q);
    printf("enter the message:");
    scanf("%d", &msg);

    int n=p*q, phiOfN=(p-1)*(q-1);

    while(e<phiOfN){
        if(gcd(e,phiOfN)==1)
            break;
        else
            e++;
    }

    while(1){
        if(fmod(d*e,phiOfN)==1)
            break;
        else
            d++;
    }

    long long encrypted= fmod(pow(msg,e),n);
    long long decrypted= fmod(pow(encrypted,d),n);
    printf("Message: %d\n", msg);
    printf("p: %d , q: %d\n",p,q);
    printf("n=pq: %d\n",n);
    printf("phi(n): %d\n",phiOfN);
    printf("e: %d , d: %d\n",e,d);
    printf("Encrypted: %lld\n",encrypted);
    printf("Decrypted: %lld\n",decrypted);
}