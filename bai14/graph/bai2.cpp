#include<bits/stdc++.h>
using namespace std;
vector<int>ke[1001];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
                int x,y;cin>>x>>y;
                ke[x].push_back(y);
                ke[y].push_back(x);
    }
    for(int i =1;i<=n;i++){
    sort(ke[i].begin(), ke[i].end());
        cout<<i << " : ";
    
    for(int x: ke[i]){
        cout<< x << " ";
    }
    cout<<endl;
    }
}