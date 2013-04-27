//-utf8- -*.*-
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

typedef long long int LLI;

const LLI loopCnt = 1000000000LL;
const LLI arraySize = 16000001LL;

LLI x[arraySize];

void program_A(void);
void program_B(void);

int main(void)
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout<<"世界你好"<<endl;

    program_A();
    program_B();

    return 0;
}

void program_A(void)
{
    LLI step = 1LL;

    /*control program for read data in order*/
    memset(x, 0, sizeof(x));
    LLI nStartTime0 = clock();
    for (int i = 0, cnt = 0; cnt < loopCnt; cnt++, i = (i + step) % arraySize);
    LLI nEndTime0 = clock();
    double nTotalTime0 = double(nEndTime0 - nStartTime0) / CLOCKS_PER_SEC;

    /*experimetal program for read data in order*/
    memset(x, 0, sizeof(x));
    LLI nStartTime1 = clock();
    for (int i = 0, cnt = 0; cnt < loopCnt; cnt++, i = (i + step) % arraySize) x[i] += 0;
    LLI nEndTime1 = clock();
    double nTotalTime1 = double(nEndTime1 - nStartTime1) / CLOCKS_PER_SEC;

    printf("/****顺序读取****/\n");
    printf("对照程序运行时间：%.6lf\t秒\n", nTotalTime0);
    printf("实验程序运行时间：%.6lf\t秒\n", nTotalTime1);
    printf("数据操作时间：%.6lf\n", nTotalTime1 - nTotalTime0);
}

void program_B(void)
{
    LLI step = 0LL;

    /*control program for read data jumpily*/
    memset(x, 0, sizeof(x));
    LLI nStartTime0 = clock();
    for (int i = 0, cnt = 0; cnt < loopCnt; cnt++, i = (i + step) % arraySize);
    LLI nEndTime0 = clock();
    double nTotalTime0 = double(nEndTime0 - nStartTime0) / CLOCKS_PER_SEC;

    /*experimetal program for read data jumpily*/
    memset(x, 0, sizeof(x));
    LLI nStartTime1 = clock();
    for (int i = 0, cnt = 0; cnt < loopCnt; cnt++, i = (i + step) % arraySize) x[i] += 0;
    LLI nEndTime1 = clock();
    double nTotalTime1 = double(nEndTime1 - nStartTime1) / CLOCKS_PER_SEC;

    printf("/****跳跃读取****/\n");
    printf("对照程序运行时间：%.6lf\t秒\n", nTotalTime0);
    printf("实验程序运行时间：%.6lf\t秒\n", nTotalTime1);
    printf("数据操作时间：%.6lf\n", nTotalTime1 - nTotalTime0);
}
