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

vector<long long> fac,finv,inv;
void init_C(int size,long long mod=998244353){
    fac.resize(size);
    finv.resize(size);
    inv.resize(size);
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<size;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
long long C(int n,int k,int mod=998244353){
    if(n<k)return 0;
    if (n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

vector<long long>pw(19);
void init_pow(){
    pw[0]=1;
    for(int i=1;i<19;i++)pw[i]=pw[i-1]*10;
}

long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}

long long lcm(long long num1,long long num2){return num1*num2/gcd(num1,num2);}

vector<long long>primeFactors(long long n){
    vector<long long> res;
    while(n%2==0){
        res.push_back(2);
        n/=2;
    }
    for(long long i=3;i*i<=n;i+=2){
        while(n%i==0){
            res.push_back(i);
            n/=i;
        }
    }
    if(n>2)res.push_back(n);
    return res;
}

vector<long long> enumPrime(long long n){
    vector<long long> res;
    for(long long i=2;i*i<=n;i++){
        bool f=false;
        while(n%i==0){
            if(!f){
                res.push_back(i);
                f=true;
            }
            n/=i;
        }
    }
    if(n>2)res.push_back(n);
    return res;
}