#include "graph.h"

int main(){
    Graph graph;
    graph_load(graph, "graph.txt");
    graph_display(graph);
    graph_draw(graph, 2);
    graph_free(graph);
    return 0;
}

