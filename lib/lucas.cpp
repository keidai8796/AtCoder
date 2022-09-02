#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

//O(logpN)
struct lucas{
    vector<modint>fac;
    vector<modint>finv;
    int p;
    lucas(int _p){
        p=_p;
        fac.resize(p);
        finv.resize(p);
        for(int i=0;i<p;i++){
            fac[i].set_mod(p);
            finv[i].set_mod(p);
        }
        fac[0]=1;
        finv[0]=1;
        for(int i=1;i<p;i++){
            fac[i]=fac[i-1]*i;
            finv[i]=fac[i].inv();
        }
    }
    long long nCk(long long n,long long k){
        modint ret;
        ret.set_mod(p);
        ret=1;
        while(n>0){
            int a=n%p;
            int b=k%p;
            if(a<b){
                ret=0;
                break;
            }
            ret*=fac[a]*finv[b]*finv[a-b];
            n/=p;
            k/=p;
        }
        if(k>0)ret=0;
        return ret.val();
    }
};

int main(){
    int n,k,p;
    cin>>n>>k>>p;
    lucas l(p);
    cerr<<"ok"<<endl;
    cout<<l.nCk(n,k)<<endl;
}