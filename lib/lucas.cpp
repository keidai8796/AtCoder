#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

struct lucas{
    vector<mint>fac;
    vector<mint>finv;
    int p;
    lucas(int _p){
        p=_p;
        fac.resize(p+1);
        fac[0]=1;
        finv[0]=1;
        for(int i=1;i<=p;i++){
            fac[i]=fac[i-1]*i;
            finv[i]=finv[i-1]/i;
        }
    }
    mint nCk(long long n,long long k){
        mint ret=1;
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
        return ret;
    }
};

int main(){
    int n,k,p;
    cin>>n>>k>>p;
    lucas l(p);
    cout<<l.nCk(n,k).val()<<endl;
}