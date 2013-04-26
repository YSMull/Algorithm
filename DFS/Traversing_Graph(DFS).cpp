#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 8//顶点数
#define M 10//边数
int  EdgeData[2*M][2]=
{
    {1,2},{2,1},
    {1,3},{3,1},
    {1,4},{4,1},
    {2,5},{5,2},
    {3,5},{5,3},
    {3,6},{6,3},
    {4,6},{6,4},
    {4,7},{7,4},
    {6,8},{8,6},
    {7,8},{8,7},
};//10条边
void Create(vector<vector<int> > & s)//邻接表
{
    for(int i=1;i<=N;i++)
    {

        for(int j=0;j<20;j++)
        {
            if(EdgeData[j][0]==i)
                s[i].push_back(EdgeData[j][1]);
        }
    }
}
void Display(vector<vector<int> > & s)
{
    for(int i=1;i<=N;i++)
    {
        cout<<"顶点"<<i<<"=>";
        vector<int>::iterator it=s[i].begin();
        while(it!=s[i].end())
        {
            cout<<"["<<*it<<"]";
            ++it;
        }
        cout<<endl;
    }
}
//图的深度优先遍历
int vis[N+1]= {0}; //节点i是否被访问过(visited)
stack<int> ss;
void DFS(int V,vector<vector<int> > & s)
{
    int x=V;
    do
    {
        if(vis[x]==0)//节点未被访问
        {
            cout<<x<<" ";
            vis[x]=1;
            vector<int>::iterator it=s[x].begin();
            while(it!=s[x].end())
            {
                if(vis[*it]==0)
                    ss.push(*it);it++;
            }
        }
        x=ss.top();
        ss.pop();
    }while(!ss.empty()||vis[x]==0);
}

int main()
{
    vector<vector<int> > s(N+1);
    Create(s);
    Display(s);
    DFS(1,s);
    return 0;
}
