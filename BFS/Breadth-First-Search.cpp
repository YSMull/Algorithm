#include<iostream>
#include<vector>
#include<deque>
#include<fstream>
using namespace std;
const int INF=0x7fffffff;//大数
//输入
char **maze;//存储迷宫的字符数组
int **d;//标记距离的数组，d[i][j]的值表示从起点到(i,j)的最短距离
int sx, sy;
int gx, gy;

int dx[4]= {1, 0, -1, 0};
int dy[4]= {0, 1, 0, -1};
int N, M;
void Init(int N, int M)//动态创建maze和d,N+1行M+1列
{
    maze =new char*[N+1];
    for(int i = 0; i <= N; i++)
        maze[i] = new char[M+1];
    d = new int*[N + 1];
    for(int i = 0; i <= N; i++)
        d[i] = new int[M+1];
}
void Delete()
{
    for(int i = 1; i <= N; i++)
        delete [] maze[i],d[i];
    delete[] maze,d;
}
int BFS()
{
    deque<pair<int, int> > que;
    que.push_back(pair<int, int>(sx,sy));
    d[sx][sy] = 0;

    while(que.size())
    {
        pair<int, int> p = que.front();
        //输出队列中的所有元素
        deque<pair<int, int> >::iterator it;
        for(it = que.begin(); it != que.end(); ++it)
            cout<<"("<<(*it).first<<","<<(*it).second<<")  ";
        cout<<endl;

        que.pop_front();//队头元素出队
        if(p.first == gx && p.second == gy) break;
        //搜索四个方向
        for(int i = 0; i < 4; i++)
        {
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            cout<<"nx="<<nx<<",ny="<<ny<<endl;//输出所有待判断的坐标
            if(1 <= nx && nx <= N && 1 <= ny && ny <= M && maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                cout<<"d["<<nx<<"]["<<ny<<"]"<<endl;//输出所有可以走的坐标
                que.push_back(pair<int, int>(nx,ny));//入队（到队尾）
                d[nx][ny] = d[p.first][p.second]+1;//从点p走到新坐标，更新新坐标的距离值
            }
        }
        cout<<endl;
    }
    return d[gx][gy];
}
int main()
{
    ifstream cin("maze.txt");
    cin>>N>>M;
    Init(N, M);//初始化数组
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            d[i][j] = INF;//初始化距离数组的每个元素值为INF（未访问状态）
            cin>>maze[i][j];
            if(maze[i][j] == 'S')//找到入口坐标
                sx=i,sy=j;
            if(maze[i][j] == 'G')//找到出口坐标
                gx=i,gy=j;
        }
    cout<<BFS()<<endl;
    Delete();
    return 0;
}
