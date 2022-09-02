#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

template<class T>
class rerooting{
    vector<vector<int>>to;
    vector<vector<T>> dp;
    
    T e;
    function<T(T,T)> merge;
    function<T(T,int)> addRoot;
public:
    vector<T> res;
    rerooting(vector<vector<int>> _to,function<T(T,T)> _merge,function<T(T,int)> _addRoot,T _e){
        to=_to;
        merge=_merge;
        addRoot=_addRoot;
        e=_e;
        dp.resize(to.size());
        res.resize(to.size());
    }
    void build(){
        dfs(0);
        dfs2(0,e);
    }
    T dfs(int v,int p=-1){
        T s=e;
        dp[v].resize(to[v].size(),e);
        for(int i=0;i<to[v].size();i++){
            if(to[v][i]==p)continue;
            dp[v][i]=dfs(to[v][i],v);
            s=merge(s,dp[v][i]);
        }
        return addRoot(s,v);
    }

    void dfs2(int v,const T& d,int p=-1){
        for(int i=0;i<to[v].size();i++){
            if(to[v][i]==p){
                dp[v][i]=d;
            }
        }
        vector<T> dp_l(to[v].size()+1,e),dp_r(to[v].size()+1,e);
        for(int i=0;i<to[v].size();i++){
            dp_l[i+1]=merge(dp_l[i],dp[v][i]);
        }
        for(int i=to[v].size()-1;i>=0;i--){
            dp_r[i]=merge(dp_r[i+1],dp[v][i]);
        }
        res[v]=addRoot(dp_l[to[v].size()],v);
        for(int i=0;i<to[v].size();i++){
            if(to[v][i]==p)continue;
            dfs2(to[v][i],addRoot(merge(dp_l[i],dp_r[i+1]),v),v);
        }
    }
};

using T=int;
T m(T a,T b){
    return max(a,b);
}
T addRoot(T a,int v){
    return a+1;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>g(n);
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    T e=-1;
    rerooting<T> r(g,m,addRoot,e);
    r.build();
    rep(i,n)cout<<r.res[i]<<endl;
}