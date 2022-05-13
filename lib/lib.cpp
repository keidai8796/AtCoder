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