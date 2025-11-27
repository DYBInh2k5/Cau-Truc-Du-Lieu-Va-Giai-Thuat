#include "graph.h"

int main(){
    Graph graph;
    graph_init(graph, 6);
    graph_add_edge(graph, 0, 1, 3, 5);
    graph_add_edge(graph, 0, 2, 1, 8);
    graph_add_edge(graph, 1, 5, 6, 2);
    graph_add_edge(graph, 2, 1, 4, 5);
    graph_add_edge(graph, 2, 3, 2, 7);
    graph_add_edge(graph, 2, 4, 5, 9);
    graph_add_edge(graph, 3, 4, 4, 8);
    graph_add_edge(graph, 3, 5, 2, 6);
    graph_display(graph);
    graph_draw(graph, 2);
    graph_free(graph);
    return 0;
}