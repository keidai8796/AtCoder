#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

//区間加算・区間和取得
struct S{
    long long value;
    int size;
};
using F=long long;
S op(S a,S b){return {a.value+b.value,a.size+b.size};}
S e(){return {0,0};}
S mapping(F f,S x){return {x.value+f*x.size,x.size};}
F composition(F f,F g){return f+g;}
F id(){return 0;}

int main(){
    int n,q;
    cin>>n>>q;
    lazy_segtree<S,op,e,F,mapping,composition,id>seg(vector<S>(n,{0,1}));
    while(q--){
        int t;cin>>t;
        if(t==1){
            int l,r;
            long long x;
            cin>>l>>r>>x;
            seg.apply(l,r+1,x);
        }else if(t==2){
            int l,r;
            cin>>l>>r;
            cout<<seg.prod(l,r+1).value<<endl;
        }
    }
}
