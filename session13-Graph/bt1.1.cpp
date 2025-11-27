#include "graph.h"
#include "queue1.h"

void bfs(Graph &graph, int root){

}

int main(){
    Graph graph;
    graph_load(graph, "graph.txt");
    graph_display(graph);
    //graph_draw(graph, 2);

    bfs(graph, 0);

    graph_free(graph);
    return 0;
}