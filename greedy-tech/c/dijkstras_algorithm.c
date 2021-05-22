#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define V 4
int findMin(int x, int y){
    if(x < y){
        return x;
    }
    return y;
}
int isMarked(int v, int markedVertices[], int markedVerticesIdx){
    int i = 0;
    for(i = 0; i < markedVerticesIdx; i++){
        if(v == markedVertices[i]){
            return 1;
        }
    }
    return 0;
}
void dijkstra(int graph[V][V], int src, int dest){
    int i, r, c, tmpC, min, currVertex, edgeWt = 0, destValue = 0, markedValue = 0, wtTableR = 0;
    int markedVerticesIdx = 0;
    int shortestPathVertices[V] = {-1}; // -1 ~ empty
    int shortestPathVerticesIdx = 0;
    int weightTable[V][V];
    for(r = 0; r < V; r++){
        for(c = 0; c < V; c++){
            weightTable[r][c] = INF;
        }
    }
    weightTable[wtTableR++][src] = 0;
    int markedVertices[V] = {-1};
    markedVertices[markedVerticesIdx++] = src;
    currVertex = src;
    while(currVertex != dest){ //copy marked values to the next row of weightTable
        for(i = 0; i < markedVerticesIdx; i++){
            c = markedVertices[i];
            weightTable[wtTableR][c] = weightTable[wtTableR - 1][c];
        }
        for (c = 0; c < V; c++){ //find the weight from the current vertex to all the other vertices that are directly connected and not yet marked
            if (c != currVertex && !isMarked(c, markedVertices, markedVerticesIdx)){
                edgeWt = graph[currVertex][c];
                destValue = weightTable[wtTableR - 1][c];
                markedValue = weightTable[wtTableR][currVertex];
                min = findMin(destValue, markedValue + edgeWt);
                weightTable[wtTableR][c] = min;
            }

        }
        min = INF;
        for(c = 0; c < V; c++){ //find minimum unmarked vertices in current row
            if(!isMarked(c, markedVertices, markedVerticesIdx)){
                if(weightTable[wtTableR][c] < min){
                    min = weightTable[wtTableR][c];
                    tmpC = c;
                }
            }
        }
        markedVertices[markedVerticesIdx++] = tmpC; //a new vertex for marking
        currVertex = tmpC;
        wtTableR++;
    }
    c = dest; //finding the shortest path vertices
    shortestPathVertices[shortestPathVerticesIdx++] = c;
    markedValue = weightTable[wtTableR - 1][dest];
    for(r = wtTableR - 2; r >= 0; r--){
        if(weightTable[r][c] != markedValue){
            c = markedVertices[r];
            markedValue = weightTable[r][c];
            shortestPathVertices[shortestPathVerticesIdx++] = c;
        }
    }
    printf("Shortest Path between %d and %d\n", src, dest);
    for(i = shortestPathVerticesIdx-1; i >= 0; i--){
        printf("%d", shortestPathVertices[i]);
        if(i > 0){
            printf(" --> ");
        }
    }
    printf("\n");
    printf("Weight of the path: %d\n", weightTable[wtTableR-1][dest]);
}
int main(){
    int graph[V][V] = {
        {0, 5, 10, INF},
        {5, 0, 4, 11},
        {10, 4, 0, 5},
        {INF, 11, 5, 0}};
    int src = 0;
    int dest = 3;
    dijkstra(graph, src, dest);
    return 0;
}
