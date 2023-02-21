#include <stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;
typedef struct edge_list {
  edge data[MAX];
  int n;
} 
edge_list;
edge_list elist;
int Graph[MAX][MAX],n;
edge_list spanlist;
void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();
void kruskalAlgo() {
int belongs[MAX], i, j, cno1, cno2;
elist.n = 0;
for (i = 1; i < n; i++)
for (j = 0; j < i; j++) {
if (Graph[i][j] != 0) {
elist.data[elist.n].u = i;
elist.data[elist.n].v = j;
elist.data[elist.n].w=Graph[i][j];
elist.n++;
}
}
sort();
for(i=0;i<n;i++)
belongs[i]=i;
spanlist.n=0;
for(i=0;i<elist.n;i++)
{
cno1=find(belongs,elist.data[i].u);
cno2=find(belongs,elist.data[i].v);
if (cno1 != cno2) 
{
spanlist.data[spanlist.n]=elist.data[i];
spanlist.n=spanlist.n+1;
applyUnion(belongs,cno1,cno2);
}
}
}
