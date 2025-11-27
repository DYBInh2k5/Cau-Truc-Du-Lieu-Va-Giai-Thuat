#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "visgraph.h"

#define NODE_DATA int
#define EDGE_DATA int

// biểu diễn cạnh
typedef struct Edge{
    int src, des;
    int weight;
    EDGE_DATA data;
    Edge *next;
} Edge;

// biểu diễn đỉnh
typedef struct Node{
    int id;
    int out_degree;
    int in_degree;
    NODE_DATA data;
    Edge *head;
} Node;

// biểu diễn đồ thị
typedef struct Graph{
    int number_of_nodes;//số lượng node của graph
    int number_of_edges;//số lượng edge của graph
    Node *nodes;//dynamic array chứa các nodes
} Graph;

/**
 * @brief Tạo một cạnh
 * 
 * @param src 
 * @param des 
 * @param weight 
 * @param data 
 * @return Edge* 
 */
Edge *graph_create_edge(int src, int des, int weight, EDGE_DATA data){
    Edge *p = (Edge *)malloc(sizeof(Edge));
    if(p != NULL){
        p->src = src;
        p->des = des;
        p->weight = weight;
        p->data = data;
        p->next = NULL;
    }
    return p;
}

/**
 * @brief Khởi tạo graph
 * 
 * @param graph 
 * @param number_of_nodes 
 */
void graph_init(Graph &graph, int number_of_nodes){
    graph.number_of_nodes = number_of_nodes;
    graph.number_of_edges = 0;
    // cấp phát động bộ nhớ cho array graph.nodes
    graph.nodes = (Node *)malloc(number_of_nodes*sizeof(Node));
    // gán giá trị ban đầu cho các nodes
    Node node;
    for (int i = 0; i < number_of_nodes; i++)
    {
        node.id = i;
        node.in_degree = 0;
        node.out_degree = 0;
        node.data = 0;
        node.head = NULL;
        graph.nodes[i] = node;
    }
}

/**
 * @brief Thêm một cạnh vào graph
 * 
 * @param graph 
 * @param src 
 * @param des 
 * @param weight 
 * @param data 
 */
void graph_add_edge(Graph &graph, int src, int des, int weight, EDGE_DATA data){
    // tạo cạnh
    Edge *p = graph_create_edge(src, des, weight, data);
    // gắn cạnh vào đầu dslk
    p->next = graph.nodes[src].head;
    graph.nodes[src].head = p;
    // cập nhật thông tin
    graph.nodes[src].out_degree++;
    graph.nodes[des].in_degree++;
    graph.number_of_edges++;
}

/**
 * @brief In edge list
 * 
 * @param head 
 */
void graph_edge_list_display(Edge *head){
    Edge *p = head;
    while(p != NULL && p->next != NULL){
        printf("(%d,%d,%d,%d)->", p->src, p->des, p->weight, p->data);
        p = p->next;
    }
    // in cạnh cuối cùng trong dslk
    if(p != NULL){
        printf("(%d,%d,%d,%d)\n", p->src, p->des, p->weight, p->data);
    }
}

/**
 * @brief Hiển thị graph
 * 
 * @param graph 
 */
void graph_display(Graph &graph){
    printf("Number of nodes: %d\n", graph.number_of_nodes);
    printf("Number of edges: %d\n", graph.number_of_edges);
    printf("Node structure: (id,out_degree,in_degree,data)\n");
    printf("Edge structure: (src,des,weight,data)\n");
    for (int i = 0; i < graph.number_of_nodes; i++)
    {
        //in thông tin của nodes[i]
        Node node = graph.nodes[i];
        if(node.head == NULL){
            printf("(%d,%d,%d,%d)::\n", node.id, node.out_degree, node.in_degree, node.data);
        }else{
            printf("(%d,%d,%d,%d)::->", node.id, node.out_degree, node.in_degree, node.data);
        }      
        //in edge list tại nodes[i]  
        graph_edge_list_display(node.head);
    }
}

/**
 * @brief Tạo visgraph từ graph
 * 
 * @param graph 
 * @param visgraph 
 */
void graph_create_visgraph(Graph &graph, VisGraph &visgraph){
    // khởi tạo visgraph
    visgraph_init(visgraph, graph.number_of_nodes, graph.number_of_edges);
    
    int j = 0;
    for (int i = 0; i < graph.number_of_nodes; i++)
    {
        // tạo nodes cho visgraph
        Node node = graph.nodes[i];
        visnode_create(visgraph.nodes[i], node.id, node.in_degree, node.out_degree);

        // tạo edges cho visgraph
        Edge *p = graph.nodes[i].head;
        while(p != NULL){
            visedge_create(visgraph.edges[j++], p->src, p->des, p->weight);
            p = p->next;
        }
    }
}

/**
 * @brief Vẽ graph
 * 
 * @param graph 
 * @param template_no 
 * @param html_file_name 
 */
void graph_draw(Graph &graph, int template_no = 1, const char *html_file_name = "graph.html"){
    VisGraph visgraph;
    graph_create_visgraph(graph, visgraph);
    visgraph_draw(visgraph, template_no);
}

/**
 * @brief giải phóng bộ nhớ chứa edge list
 * 
 * @param head 
 */
void graph_edge_list_free(Edge *&head)
{
    while (head != NULL)
    {
        Edge *p = head;
        head = head->next;
        free(p);
    }
}

/**
 * @brief Giải phóng bộ nhớ chứa graph
 * 
 * @param graph 
 */
void graph_free(Graph &graph){
    for (int i = 0; i < graph.number_of_nodes; i++)
    {
        //giải phóng bộ nhớ chứa edge list tại nodes[i]  
        graph_edge_list_free(graph.nodes[i].head);
    }
    // giải phóng bộ nhớ chứa graph.nodes
    free(graph.nodes);
}

/**
 * @brief Tạo n des ids ngẫu nhiên
 * 
 * @param src : loại trừ src (tránh loop)
 * @param n : số ids được tạo
 * @param max_id : id lớn nhất được tạo (exclusive)
 * @return int* : array động chứa ids
 */
int *graph_random_des_ids(int src, int n, int max_id){
    int *ids = (int *)malloc(n * sizeof(int));
    int i = 0;
    while(i < n){
        int des = rand() % max_id;
        if(des != src){
            ids[i++] = des;
        }
    }
    return ids;
}

int min(int a, int b){
    return a < b? a: b;
}

/**
 * @brief Tạo graph ngẫu nhiên
 * 
 * @param graph 
 * @param number_of_nodes 
 */
void graph_random(Graph &graph, int number_of_nodes = 9){
    srand(time(NULL));

    //int min_out_degree = rand() % 3;
    int min_out_degree = 0;
    int max_out_degree = 3;
    int max_weight = 9;
    int max_data = 9;
    graph_init(graph, number_of_nodes);
    
    for (int src = 0; src < number_of_nodes; src++)
    {
        int n = rand() % (number_of_nodes/2 - min_out_degree) + min_out_degree;
        n = min(n, max_out_degree);
        int *des_ids = graph_random_des_ids(src, n, number_of_nodes);
        for (int i = 0; i < n; i++)
        {
            int weight = rand() % max_weight + 1;
            int data = rand() % max_data + 1;
            graph_add_edge(graph, src, des_ids[i], weight, data);
        }
        free(des_ids);
    }
}

/**
 * @brief Lưu graph vào file
 * 
 * @param graph 
 * @param graph_file_name 
 */
void graph_store(Graph &graph, const char *graph_file_name)
{
    // mở file
    FILE *file = fopen(graph_file_name, "w");

    // ghi number_of_nodes, number_of_edges
    fprintf(file, "%d,%d\n", graph.number_of_nodes, graph.number_of_edges);
    
    // ghi các cạnh vào file
    for (int i = 0; i < graph.number_of_nodes; i++)
    {
        // ghi các cạnh của nodes[i] vào file   
        Edge *p = graph.nodes[i].head;
        while(p != NULL){
            fprintf(file, "%d,%d,%d\n", p->src, p->des, p->weight);
            p = p->next;
        }
    }
    // đóng file
    fclose(file);
}

/**
 * @brief Tạo graph từ graph file
 * 
 * @param graph 
 * @param graph_file_name 
 */
void graph_load(Graph &graph, const char *graph_file_name)
{
    // mở file
    FILE *file = fopen(graph_file_name, "r");

    // đọc dòng đầu tiên của file lấy thông tin number_of_nodes, number_of_edges
    int number_of_nodes, number_of_edges;
    fscanf(file, "%d,%d\n", &number_of_nodes, &number_of_edges);

    // khởi tạo graph
    graph_init(graph, number_of_nodes);

    // khai báo biến
    int src, des, weight;

    // đọc dòng thứ hai trở đi của file lấy thông tin edges
    for (int i = 0; i < number_of_edges; i++)
    {
        fscanf(file, "%d,%d,%d\n", &src, &des, &weight);
        // thêm cạnh vào graph
        graph_add_edge(graph, src, des, weight, 0);
    }
    // đóng file
    fclose(file);
}