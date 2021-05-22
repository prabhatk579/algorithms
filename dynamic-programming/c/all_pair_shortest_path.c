#include<stdio.h>
#define V 4
#define INF 99999
void displayMatrix(int dist[][V]){
	for (int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if (dist[i][j] == INF)
				printf("%5s", "INF");
			else
				printf ("%5d", dist[i][j]);
		}
		printf("\n");
	}
}
void APSP(int graph[][V]){
	int dist[V][V], i, j, k;
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for(k = 0; k < V; k++){
		for(i = 0; i < V; i++){ // Picking source vertex one by one
			for(j = 0; j < V; j++){ // Picking destination vertex one by one
				if(dist[i][k] + dist[k][j] < dist[i][j]) //If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
    printf("Matrix for the shortest distances between every pair of vertices:\n");
	displayMatrix(dist);
}
int main(){
	int graph[V][V] = { {0, 10, INF, 20},
						{INF, 0, 10, INF},
						{INF, INF, 0, 3},
						{INF, 8, INF, 0} };
    printf("The given matrix is: \n");
    displayMatrix(graph);
	APSP(graph);
	return 0;
}
