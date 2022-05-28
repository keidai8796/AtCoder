#include<bits/stdc++.h>
using namespace std;

class Mo{
    struct Q{
        int l,r,index;
    };
    vector<Q>q;
    int w;
    int sz;
    void add(int i);
    void del(int i);
    void query(int i);
public:
    Mo(int n):w(sqrt(n)),sz(0){}
    void insert(int l,int r){
        q.push_back(Q{l,r,sz++});
    }
    void solve(){
        sort(q.begin(),q.end(),[&](Q a,Q b){
            if(a.l/w==b.l/w)return a.r<b.r;
            return a.l/w<b.l/w;
        });
        int nl=0,nr=0;
        for(Q qi:q){
            while(nl>qi.l)add(--nl);
            while(nr<qi.r)add(nr++);
            while(nl<qi.l)del(nl++);
            while(nr>qi.r)del(--nr);
            query(qi.index);
        }
    }
};

void Mo::add(int i){

}

void Mo::del(int i){

}

void Mo::query(int i){

}