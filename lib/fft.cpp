#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

void dft(vector<complex<double>>&f,bool inv=false){
    int sz=f.size();
    if(sz==1)return;
    vector<complex<double>>f0;
    vector<complex<double>>f1;
    for(int i=0;i<sz;i++){
        if(i&1)f1.push_back(f[i]);
        else f0.push_back(f[i]);
    }
    dft(f0,inv);
    dft(f1,inv);
    complex<double> x(1,0);
    complex<double> z;
    if(!inv)z=polar(1.0,2*acos(-1)/sz);
    else z=polar(1.0,-2*acos(-1)/sz);
    for(int i=0;i<sz;i++){
        f[i]=f0[i%(sz/2)]+x*f1[i%(sz/2)];
        x*=z;
    }
}

vector<ll> convolution(vector<ll>&a,vector<ll>&b){
    int sz=1;
    while(sz<a.size()+b.size())sz*=2;
    vector<complex<double>>na(sz),nb(sz);
    for(int i=0;i<a.size();i++)na[i].real(a[i]);
    for(int i=0;i<b.size();i++)nb[i].real(b[i]);
    dft(na);
    dft(nb);
    vector<complex<double>>c(sz);
    for(int i=0;i<sz;i++)c[i]=na[i]*nb[i];
    dft(c,true);
    vector<ll>res(sz);
    for(int i=0;i<sz;i++)res[i]=(ll)round(c[i].real()/sz);
    return res;
}