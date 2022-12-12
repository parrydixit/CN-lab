#include<bits/stdc++.h>
using namespace std;

string addBinaryUtil(string a, string b){
    string res="";
    int s=0;
    int i=a.size()-1, j= b.size()-1;

    while(i>=0 || j>=0 || s==1){
        s+= (i>=0)?a[i]-'0':0;
        s+= (j>=0)?b[j]-'0':0;
        res= char(s%2+'0')+res;
        s/=2;
        i--;
        j--;
    }
    return res;
}

string checkSum(string arr[],int n,int x){
    string res="";
    for(int i=0;i<=n;i++){
        res= addBinaryUtil(res,arr[i]);
    }
    if(res.length()==x)
        return res;
    else{
        arr[0]= res.substr(0,res.length()-x);
        arr[1]= res.substr(res.length()-x,x);
        return checkSum(arr,2,x);
    }
}

int main(){
    int n,x;
    cout<<("enter number of bits:\n");
    cin>>x;
    cout<<("enter number of numbers:\n");
    cin>>n;
    
    string arr[n];
    cout<<"enter the numbers:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    string ans= checkSum(arr,n,x);
    cout<<"Ans:";
    for(int i=0;i<x;i++){
        ans[i]=='0'?cout<<'1':cout<<'0';
    }
    return 0;
}