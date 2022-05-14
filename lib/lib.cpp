#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

//素数判定
bool isPrime(long long n){
    if(n<2)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    for(long long i=3;i*i<=n;i+=2)if(n%i==0)return false;
    return true;
}

//最長部分増加列
template<class T>
vector<T>lis(vector<T>&a,bool strict=true){
    vector<T>res;
    for(T x:a){
        class vector<T>::iterator it;
        if(strict)it=lower_bound(res.begin(),res.end(),x);
        else it=upper_bound(res.begin(),res.end(),x);
        if(it==res.end())res.push_back(x);
        else *it=x;
    }
    return res;
}

long long floor_sqrt(long long n){
    long long ok=0;
    long long ng=min((long long)(1e9)+1,n);
    while(ok+1<ng){
        long long m=(ng+ok)/2;
        if(m*m<=n)ok=m;
        else ng=m;
    }
    return ok;
}

long long ceil_sqrt(long long n){
    long long ng=-1;
    long long ok=min((long long)(1e9),n);
    while(ng+1<ok){
        long long m=(ng+ok)/2;
        if(m*m>=n)ok=m;
        else ng=m;
    }
    return ok;
}

long long floor_cbrt(long long n){
    long long ok=0;
    long long ng=min((long long)(1e6)+1,n);
    while(ok+1<ng){
        long long m=(ng+ok)/2;
        if(m*m*m<=n)ok=m;
        else ng=m;
    }
    return ok;
}

long long ceil_cbrt(long long n){
    long long ng=-1;
    long long ok=min((long long)(1e6),n);
    while(ng+1<ok){
        long long m=(ng+ok)/2;
        if(m*m*m>=n)ok=m;
        else ng=m;
    }
    return ok;
}
