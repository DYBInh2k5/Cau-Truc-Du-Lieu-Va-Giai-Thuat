#include "graph.h"

int main(){
    Graph graph;
    graph_random(graph, 140);
    graph_display(graph);
    graph_draw(graph, 4);
    graph_free(graph);
    return 0;
}

