#include<stdio.h>
#include<stdlib.h>

#define INFINITY 1000000 /*INFINITY means Station A and Station B aren't connected.*/
#define MaxStationNum 501 /*The maximum number of the stations.*/

typedef int WeightType;
typedef struct GNode *PtrToGNode;

/*The data structure for the graph.*/
struct GNode {
    int Cmax;   // the maximum capacity of each station
    int N;      // the total number of stations
    int Sp;     // the index of the problem station 
    int M;      // the number of roads
    int Time[MaxStationNum][MaxStationNum];
    WeightType Capacity[MaxStationNum];
};

typedef PtrToGNode Graph;

void Init();
void DFS(int current);
void CheckStack();
void ResetPath();
void PrintResult();
void CaculateTimeAndBike();

int Known[MaxStationNum];
int Stack[MaxStationNum + 3]; 
int Path[MaxStationNum + 3]; 
int flag; 
int top; 
Graph G;

int main()
{
    Init();
    DFS(0);
    PrintResult();
    return 0;
}

void Init()
{
    G = (Graph)malloc(sizeof(struct GNode));
    scanf("%d %d %d %d", &(G->Cmax), &(G->N), &(G->Sp), &(G->M));
    int i, j, k;
    G->Capacity[0] = 0;
    for(i = 1; i <= G->N; i++) scanf("%d", &(G->Capacity[i]));
    for(i = 0; i <= G->N; i++) {
        for(j = 0; j <= G->N; j++) {
            G->Time[i][j] = INFINITY;
            if(i == j) G->Time[i][j] = 0;
        }
    }
    for(i = 1; i <= G->M; i++) {
        int StationA, StationB, time;
        scanf("%d %d %d", &StationA, &StationB, &time);
        G->Time[StationA][StationB] = time;
        G->Time[StationB][StationA] = time;
    }
    for(k = 0; k < MaxStationNum; k++) {
        Known[k] = 0;
        Stack[k] = -1;
        Path[k] = -1;
    }
    Path[MaxStationNum] = 0;
    Path[MaxStationNum + 1] = 0;
    Path[MaxStationNum + 2] = 0;
    top = -1;
    flag = 0;
}

void DFS(int current)
{
    Known[current] = 1;
    Stack[++top] = current;
    if(current == 0) Stack[MaxStationNum] = 0;
    else Stack[MaxStationNum] += G->Time[Stack[top - 1]][Stack[top]];
    if(current == G->Sp) {
        CheckStack();
        Stack[MaxStationNum] -= G->Time[Stack[top - 1]][Stack[top]];
        top--;
        Known[current] = 0;
        return;
    }
    if(flag == 1 && Stack[MaxStationNum] > Path[MaxStationNum]) {
        if(current != 0) Stack[MaxStationNum] -= G->Time[Stack[top - 1]][Stack[top]];
        top--;
        Known[current] = 0;
        return;
    }
    int i;
    for(i = 0; i <= G->N; i++) {
        if(Known[i] == 0 && G->Time[current][i] < INFINITY) {
            DFS(i);
        }
    }
    Stack[MaxStationNum] -= G->Time[Stack[top - 1]][Stack[top]];
    top--;
    Known[current] = 0;
}

void CheckStack()
{
    CaculateTimeAndBike();
    if(flag == 0) {
        ResetPath();
        flag = 1;
    }
    else if(Path[MaxStationNum] > Stack[MaxStationNum]) ResetPath();
    else if(Path[MaxStationNum] == Stack[MaxStationNum]) {
        if(Path[MaxStationNum + 1] > Stack[MaxStationNum + 1]) ResetPath();
        else if(Path[MaxStationNum + 1] == Stack[MaxStationNum + 1]) {
            if(Path[MaxStationNum + 2] > Stack[MaxStationNum + 2]) ResetPath();
        }  
    }
}

void ResetPath()
{
    int i;
    Path[MaxStationNum] = Stack[MaxStationNum];
    Path[MaxStationNum + 1] = Stack[MaxStationNum + 1];
    Path[MaxStationNum + 2] = Stack[MaxStationNum + 2];
    for(i = 0; i <= top; i++) Path[i] = Stack[i];
}

void CaculateTimeAndBike()
{
    int i, temp = 0;
    Stack[MaxStationNum] = 0;
    Stack[MaxStationNum + 1] = 0;
    Stack[MaxStationNum + 2] = 0;
    for(i = 0; i <= top; i++) {
        if(i < top) Stack[MaxStationNum] += G->Time[Stack[i]][Stack[i + 1]];
        if(i > 0) {
            if(G->Capacity[Stack[i]] >= G->Cmax / 2) 
                temp += (G->Capacity[Stack[i]] - G->Cmax / 2);
            else if(G->Capacity[Stack[i]] < G->Cmax / 2) {
                if(temp >= G->Cmax / 2 - G->Capacity[Stack[i]]) temp -= (G->Cmax / 2 - G->Capacity[Stack[i]]);
                else {
                    Stack[MaxStationNum + 1] += (G->Cmax / 2 - G->Capacity[Stack[i]] - temp);
                    temp = 0;
                }
            }
        }
    }
    Stack[MaxStationNum + 2] = temp;
}

void PrintResult()
{
    printf("%d ", Path[MaxStationNum + 1]);
    int i = 0;
    for(i = 0; ; i++) {
        printf("%d", Path[i]);
        if(Path[i] != G->Sp) printf("->");
        else {
            printf(" ");
            break;
        }
    }
    printf("%d", Path[MaxStationNum + 2]);
}