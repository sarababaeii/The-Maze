#include <stdio.h>
#define max_n 100

struct cor{
	int x;
	int y;
};

int a[max_n][max_n], mark[max_n];
int m, n;
struct cor sq[max_n];

void prepro(){
	int i, j, ind;
	for (i=0; i<=m+1; i++){
		a[i][0] = 1;
		a[i][n+1] = 1;
	}
	for (i=0; i<=n+1; i++){
		a[0][i] = 1;
		a[m+1][i] = 1;
	}
	for (i=0, ind=0; i<m+2; i++){
		for (j=0; j<n+2; j++,ind++){
			struct cor t;
			t.x = i;
			t.y = j;
			sq[ind] = t;
		}
	}
}

void input(){
	scanf("%d%d", &m, &n);
	int i, j;
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			scanf("%d", &a[i][j]);
}

int find_path(int from , int to){ //index of cordinate in array sq
	if (mark[to]==1 || a[sq[to].x][sq[to].y]==1)
		return -1;
	if (from==to)
		return from;
	mark[to] = 1;
	int t=find_path(from, to-1);
	if(t!=-1){
		t = to-1;
		printf("%d %d\n", sq[t].x-1, sq[t].y-1);
		return t;
	}
	t = find_path(from, to+1);
	if(t!=-1){
		t = to+1;
		printf("%d %d\n", sq[t].x-1, sq[t].y-1);
		return t;
	}
	t = find_path(from,to-n-2);
	if(t!=-1){
		t = to-n-2;
		printf("%d %d\n", sq[t].x-1, sq[t].y-1);
		return t;
	}
	t = find_path(from,to+n+2);
	if(t!=-1){
		t = to+n+2;
		printf("%d %d\n", sq[t].x-1, sq[t].y-1);
		return t;
	}
	return -1;
}

int main(){
	input();
	prepro();
	int i;
	int d=find_path(n+2+1,(m+2)*(n+2)-n-2-1-1);
	if(d==-1)
		printf("-1\n");
	else
		printf("%d %d\n", sq[(m+2)*(n+2)-n-2-1-1].x-1, sq[(m+2)*(n+2)-n-2-1-1].y-1);
	return 0;
}
