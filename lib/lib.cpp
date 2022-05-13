#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

bool isPrime(long long n){
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(long long i=3;i*i<=n;i+=2)if(n%i==0)return false;
    return true;
}