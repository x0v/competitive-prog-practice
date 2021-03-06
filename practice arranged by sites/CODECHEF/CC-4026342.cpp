#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int main()
{
int t,i,j,x,y;
int n,e;
cin>>t;
while(t--)
{
cin>>n>>e;

vector< vector<int> >G(n);
int visited[n];
memset(visited,0,sizeof(visited));

for(i=0;i<e;i++)
{
cin>>x>>y;
G[x].push_back(y);
G[y].push_back(x);
}

int ans=0;
for(i=0;i<n;i++)
{
if(!visited[i])
{
queue<int>q;
q.push(i);
visited[i]=1;

while(!q.empty())
{
int p=q.front();
q.pop();
for(j=0;j<G[p].size();j++)
{
if(!visited[G[p][j]])
{
visited[G[p][j]]=1;
q.push(G[p][j]);
}
}
}
ans++;
}
}
cout<<ans<<"\n";
}
}