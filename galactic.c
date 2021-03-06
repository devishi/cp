    #include <stdio.h>
     
    #define NMAX 100100
    #define INF 1000000000
     
    int parent[NMAX], cmin[NMAX], size[NMAX];
    int N, M, C, ncc, i, j, k, sum, Cmin;
     
    int Find(int x) {
    	int tx, rx;
    	tx = x;
    	while (parent[tx] > 0)
    		tx = parent[tx];
     
    	while (x != tx) {
    		rx = parent[x];
    		parent[x] = tx;
    		x = rx;
    	}
    	
    	return tx;
    }
     
    void Union(int i, int j) {
    	int ti = Find(i), tj = Find(j);
    	if (ti == tj)
    		return;
    	ncc--;
    	if (size[ti] >= size[tj]) {
    		parent[tj] = ti;
    		size[ti] += size[tj];
    	} else {
    		parent[ti] = tj;
    		size[tj] += size[ti];
    	}
    }
     
    int main() {
    	//freopen("x.txt", "r", stdin);
    	scanf("%d %d", &N, &M);
    	ncc = N;
     
    	for (i = 1; i <= N; i++) {
    		cmin[i] = -1;
    		parent[i] = 0;
    		size[i] = 1;
    	}
     
    	for (k = 1; k <= M; k++) {
    		scanf("%d %d", &i, &j);
    		Union(i, j);
    	}
     
    	if (ncc == 1) {
    		printf("0\n");
    		return 0;
    	}
    	
    	for (i = 1; i <= N; i++) {
    		scanf("%d", &C);
    		if (C < 0)
    			continue;
    		j = Find(i);
    		if (cmin[j] < 0 || C < cmin[j])
    			cmin[j] = C;
    	}
     
    	sum = 0;
    	Cmin = INF;
     
    	for (i = 1; i <= N; i++) {
    		if (parent[i] > 0)
    			continue;
    		if (cmin[i] < 0) {
    			printf("-1\n");
    			return 0;
    		}
    		sum += cmin[i];
    		if (cmin[i] < Cmin)
    			Cmin = cmin[i];
    	}
     
    	printf("%d\n", sum + (ncc - 2) * Cmin);
    	return 0;
    } 