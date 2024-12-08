#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

//トライ木
//文字列の集合を木構造として表すことで検索を高速にできる
//mを文字列の長さとして以下をO(m)でできるらしい
//文字列の検索（未実装）
//文字列の挿入
//文字列の削除（未実装）
//辞書順で前・次の文字は何か（未実装）

struct Trie{
    vector<vector<int>> next;
    vector<set<int>> accept;
    
    Trie(){
        next.push_back(vector<int>(26,-1));
        accept.emplace_back();
    }
    
    void insert(string word,int word_id=0){
        int now_id=0;
        for(int i=0;i<word.size();i++){
            int c=word[i]-'a';
            int next_id=next[now_id][c];
            if(next_id==-1){
                next_id=next.size();
                next[now_id][c]=next_id;
                next.push_back(vector<int>(26,-1));
                accept.emplace_back();
            }
            now_id=next_id;
        }
    }
};