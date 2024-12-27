#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln '\n'
#define tests int t; cin >> t; while(t--)
struct DSU{
  int sz ; vector <int> parent , group;
  DSU(int n){
    sz = n;
    parent = vector<int>(n + 1);
    iota(parent.begin() , parent.end() , 0);
    group = vector<int>(n + 1 , 1);
  }
  int find(int node){
    if(parent[node] == node)return parent[node];
    return find(parent[node]);
  }
  void merge(int u , int v){
    int l1 = find(u);
    int l2 = find(v);
    if(l1 == l2)return;
    if(group[l1] > group[l2])swap(l1,l2);
    parent[l1] = l2 ;
    group[l2] += group[l1];
  }
  bool sameGroup(int u , int v){
    return find(u) == find(v);
  }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  
    return 0;
}
