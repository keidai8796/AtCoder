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

long long powll(long long a,int b){
    long long res=1;
    for(int i=0;i<b;i++)res*=a;
    return res;
}

long long modpow(long long a,long long n,long long mod=998244353){
    a%=mod;
    if(a==0)return 0;
    long long res=1;
    while(n>0){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

template<class T>
void comp(vector<T>&a){
    set<T>s;
    for(auto x:a)s.insert(x);
    map<T,int>mp;
    int cnt=0;
    for(auto x:s)mp[x]=cnt++;
    for(auto&x:a)x=mp[x];
}

template<class T>
map<T,int> compmap(vector<T>&a){
    set<T>s;
    for(auto x:a)s.insert(x);
    map<T,int>mp;
    int cnt=0;
    for(auto x:s)mp[x]=cnt++;
    return mp;
}