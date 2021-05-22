#include <stdio.h>
#include <stdlib.h>
struct Edge{
    int start;  //starting vertex (node) of the edge
    int end;    //ending vertex (node) of the edge
    int weight;    //weight of the edge
};
struct Graph{
    int E;    //number of edges in the graph
    int V;    //number of vertices in the graph
    struct Edge* edge;  //pointer to array of edges
};
struct subset{
    int parent;    //this is the parent of the subset
    int rank;    //this is the rank of the subset
};
struct Graph* createGraph(int E, int V){
    struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph)); //creating graph pointer
    graph->E = E; //assign no. of edge and no. of vertex
    graph->V = V; 
    graph->edge = (struct Edge*) malloc (graph->E * sizeof(struct Edge)); //pointer to edge
    return graph;
}
int Find(struct subset subsets[], int i){ // finds the subset to which i belongs to
    if(subsets[i].parent != i){
        subsets[i].parent = Find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(struct subset subsets[], int vertXSubset, int vertYSubset){ // joins two subsets
    int rootOfX = Find(subsets, vertXSubset);
    int rootOfY = Find(subsets, vertYSubset);
    if(subsets[rootOfX].rank < subsets[rootOfY].rank){
        subsets[rootOfX].parent = rootOfY;
    }
    else if(subsets[rootOfX].rank > subsets[rootOfY].rank){
        subsets[rootOfY].parent = rootOfX;
    }
    else{
        subsets[rootOfY].parent = rootOfX;
        subsets[rootOfX].rank++;
    }
}
void sort(struct Graph* graph){ // sort in ascending order wwrt weights
    int i, j, noOfEdges = graph->E;
    struct Edge* tempEdge = (struct Edge*) malloc (sizeof(struct Edge));
    for(i = 1; i < noOfEdges; i++){
        for(j = 0; j < noOfEdges - i; j++){
            if(graph->edge[j].weight > graph->edge[j+1].weight){
                tempEdge->start = graph->edge[j].start;
                tempEdge->end = graph->edge[j].end;
                tempEdge->weight = graph->edge[j].weight;
                graph->edge[j] = graph->edge[j+1];
                graph->edge[j+1].start = tempEdge->start;
                graph->edge[j+1].end = tempEdge->end;
                graph->edge[j+1].weight = tempEdge->weight;
            }
        }
    }
}
void displayMST(struct Graph* graphMST){
int i, noOfEdges = graphMST->E , sum = 0;
    for(i = 0; i < noOfEdges; i++){
        printf("Edge %d-->%d Weight: %d\n", graphMST->edge[i].start +1, graphMST->edge[i].end +1, graphMST->edge[i].weight);
        sum += graphMST->edge[i].weight;
    }
    printf("The total cost of MST is: %d", sum);
}
int hasCycle(struct Graph* graph){ // 0 -> No cycle, 1 -> Cycle
    int i, j, vertXSubset, vertYSubset;
    int V = graph->V;
    int E = graph->E;
    struct subset* subsets = (struct subset*) malloc (V * sizeof(struct subset));
    for(i = 0; i < V; i++){ 
        subsets[i].parent = i; //initialize subset
        subsets[i].rank = 0;
    }
    for(j = 0; j < E; j++){ //detect cycle
        vertXSubset = Find(subsets, graph->edge[j].start);
        vertYSubset = Find(subsets, graph->edge[j].end);
        if(vertXSubset == vertYSubset){
            return 1;
        }
        Union(subsets, vertXSubset, vertYSubset);
    }
    return 0;
}
void kruskal(struct Graph* graph){
    int i, j;
    int E = graph->E;
    int V = graph->V;
    sort(graph);
    struct Graph* graphMST = createGraph(V - 1, V);
    for(i = 0, j = 0; i < E && j < V - 1; i++){
        graphMST->edge[j] = graph->edge[i];
        graphMST->E = j + 1;
        if(!hasCycle(graphMST)){
            j++;
        }
    }
    displayMST(graphMST);
}
int main(){
    int E = 5;
    int V = 4;
    struct Graph* graph = createGraph(E, V);
    //edge: 1 -- 2
    graph->edge[0].start = 0;
    graph->edge[0].end = 1;
    graph->edge[0].weight = 2;
    //edge: 1 -- 3
    graph->edge[1].start = 0;
    graph->edge[1].end = 2;
    graph->edge[1].weight = 2;
    //edge: 2 -- 3
    graph->edge[2].start = 1;
    graph->edge[2].end = 2;
    graph->edge[2].weight = 1;
    //edge: 2 -- 4
    graph->edge[3].start = 1;
    graph->edge[3].end = 3;
    graph->edge[3].weight = 5;
    //edge: 4 -- 3
    graph->edge[4].start = 3;
    graph->edge[4].end = 2;
    graph->edge[4].weight = 3;
    kruskal(graph);
    return 0;
}
