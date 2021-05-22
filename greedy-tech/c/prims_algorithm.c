#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define V 4
void displayMST(int graph[V][V], int markedCell[V][V]){
    int r, c , sum = 0;
    for(r = 0; r < V-1; r++){
        for(c = r+1; c < V; c++){
            if(markedCell[r][c]){
                printf("Edge: %d -- %d\tWeight: %d\n", r, c, graph[r][c]);
                sum += graph[r][c];
            }
        }
    }
    printf("The total cost of MST is: %d",sum); 
}
void prim(int graph[V][V]){
    int i, r, c, solved = 0, count = 0, min, expectedR, expectedC;
    int markedCell[V][V] = {{0}};
    int markedVertex[V] = {0}; // 0 -> Unmarked, 1 -> Marked
    markedVertex[0] = 1; 
    while(!solved){
        min = INF;
        count = 0;
        expectedR = -1;
        expectedC = -1;
        for (r = 0; r < V; r++){//Loop for one half of the square matrix as a[i][j] = a[j][i] and a[i][i] = 0
            if(markedVertex[r] == 1){
                for(c = r; c < V; c++){
                    if(graph[r][c] != 0 && graph[r][c] < min && !markedCell[r][c]){ 
                        min = graph[r][c];
                        expectedR = r;
                        expectedC = c;
                    }
                }
            }
        }
        if(expectedR != -1 && expectedC != -1){ //Marking visited the vertices 
            markedCell[expectedR][expectedC] = 1;
            markedCell[expectedC][expectedR] = 1;
            markedVertex[expectedR] = 1;
            markedVertex[expectedC] = 1;
        }
        for(i = 0; i < V; i++){ //Checking if the graph is soved
            if(markedVertex[i]){
                count++;
            }
        }
        if(count == V){
            solved = 1;
        }
    }
    displayMST(graph, markedCell);
}
int main(){
    int graph[V][V] = {
        {0, 5, 10, INF},
        {5, 0, 4, 11},
        {10, 4, 0, 5},
        {INF, 11, 5, 0}};
    prim(graph);
    return 0;
}
