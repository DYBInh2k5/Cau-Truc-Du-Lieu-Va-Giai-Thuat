#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 100000
#define LINE_COUNT 1000
#define LINE_LENGTH 200

typedef struct VisNode
{
    int id;
    int in_degree;
    int out_degree;
} VisNode;

typedef struct VisEdge
{
    int src, des;
    int weight;
} VisEdge;

typedef struct VisGraph
{
    int number_of_nodes, number_of_edges;
    VisNode *nodes;
    VisEdge *edges;
} VisGraph;

/**
 * @brief Tạo visnode
 * 
 * @param node 
 * @param id 
 * @param in_degree 
 * @param out_degree 
 */
void visnode_create(VisNode &node, int id, int in_degree, int out_degree)
{
    node.id = id;
    node.in_degree = in_degree;
    node.out_degree = out_degree;
}

/**
 * @brief Tạo visedge
 * 
 * @param edge 
 * @param src 
 * @param des 
 * @param weight 
 */
void visedge_create(VisEdge &edge, int src, int des, int weight)
{
    edge.src = src;
    edge.des = des;
    edge.weight = weight;
}

/**
 * @brief Khởi tạo visgraph
 * 
 * @param graph 
 * @param number_of_nodes 
 * @param number_of_edges 
 */
void visgraph_init(VisGraph &graph, int number_of_nodes, int number_of_edges)
{
    graph.number_of_nodes = number_of_nodes;
    graph.number_of_edges = number_of_edges;
    graph.nodes = (VisNode *)malloc(number_of_nodes * sizeof(VisNode));
    graph.edges = (VisEdge *)malloc(number_of_edges * sizeof(VisEdge));
}

/**
 * @brief Giải phóng bộ nhớ chứa visgraph
 * 
 * @param graph 
 */
void visgraph_free(VisGraph &graph)
{
    free(graph.nodes);
    free(graph.edges);
}

/**
 * @brief Đọc graph_file_name để lấy thông tin của graph
 *
 * @param graph_file_name
 */
void visgraph_load(VisGraph &graph, const char *graph_file_name)
{
    // mở file
    FILE *file = fopen(graph_file_name, "r");

    // đọc dòng đầu tiên của file lấy thông tin min_id, max_id, number_of_edges
    int min_id, max_id, number_of_nodes, number_of_edges;
    fscanf(file, "%d,%d,%d\n", &min_id, &max_id, &number_of_edges);
    number_of_nodes = max_id - min_id + 1;

    // khởi tạo graph
    visgraph_init(graph, number_of_nodes, number_of_edges);

    // khai báo biến
    int n = number_of_edges;
    int src, des, weight;
    int out_degree[n] = {0}, in_degree[n] = {0};

    // đọc dòng thứ hai trở đi của file lấy thông tin edges
    // tạo các cạnh
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d,%d,%d\n", &src, &des, &weight);
        in_degree[des]++;
        out_degree[src]++;
        visedge_create(graph.edges[i], src, des, weight);
    }
    // đóng file
    fclose(file);

    // tạo các nodes
    for (int i = 0, id = min_id; id <= max_id; i++, id++)
    {
        visnode_create(graph.nodes[i], id, in_degree[id], out_degree[id]);
    }
}

/**
 * @brief Tạo label cho visnode
 * 
 * @param label 
 * @param id 
 */
void visnode_label_create(char *label, int id){
    strcpy(label, "");
    sprintf(label, "%d", id);
}

/**
 * @brief Tạo node list
 * 
 * @param graph 
 * @param node_list 
 */
void visgraph_create_node_list(VisGraph &graph, char *node_list)
{
    srand(time(NULL));
    int num_of_group = graph.number_of_nodes / 2;
    for (int i = 0; i < graph.number_of_nodes; i++)
    {
        VisNode node = graph.nodes[i];
        int id = node.id;        
        int value = (node.in_degree + node.out_degree)*10;
        char label[20]; visnode_label_create(label, id);
        int group = rand() % num_of_group;
        sprintf(node_list, "%s                {id:%2d, label:\"%s\", value:%d, group:%d},\n", node_list, id, label, value, group);
        // printf("%d,%d,%d\n", node.id, node.out_degree, node.in_degree);
    }
}

/**
 * @brief Tạo edge list
 * 
 * @param graph 
 * @param edge_list 
 */
void visgraph_create_edge_list(VisGraph &graph, char *edge_list)
{
    for (int i = 0; i < graph.number_of_edges; i++)
    {
        VisEdge edge = graph.edges[i];
        sprintf(edge_list, "%s                {from:%2d, to:%2d, arrows:\"to\", label:\"%d\"},\n", edge_list, edge.src, edge.des, edge.weight);
    }
}

/**
 * @brief Tạo html từ template
 * 
 * @param node_list 
 * @param edge_list 
 * @param template_file_name 
 * @param output_file_name 
 */
void visgraph_create_html_file(char *node_list, char *edge_list, const char *template_file_name, const char *output_file_name)
{
    FILE *ftemplate, *fhtml;

    ftemplate = fopen(template_file_name, "r");
    fhtml = fopen(output_file_name, "w");
    char line[LINE_LENGTH] = "";
    while (fgets(line, LINE_LENGTH, ftemplate) != NULL)
    {
        if (strstr(line, "//{{nodes}}") != NULL)
        {
            fprintf(fhtml, "            var nodes = [\n%s            ]\n", node_list);
        }
        else if (strstr(line, "//{{edges}}") != NULL)
        {
            fprintf(fhtml, "            var edges = [\n%s            ]\n", edge_list);
        }
        else
        {
            fprintf(fhtml, "%s", line);
        }
    }
    fclose(ftemplate);
    fclose(fhtml);
}

/**
 * @brief Browse html file
 * 
 * @param html_file_name 
 */
void html_browse(const char *html_file_name)
{
    char cmd_browse[50] = "";
    sprintf(cmd_browse, "start %s", html_file_name);
    system(cmd_browse);
}

/**
 * @brief Vẽ visgraph từ graph file
 * 
 * @param graph_file_name 
 * @param template_no 
 * @param html_file_name 
 */
void visgraph_draw(const char *graph_file_name, int template_no = 1, const char *html_file_name = "graph.html")
{
    VisGraph graph;
    visgraph_load(graph, graph_file_name);
    char node_list[BUFFER_SIZE] = "";
    char edge_list[BUFFER_SIZE] = "";
    visgraph_create_node_list(graph, node_list);
    visgraph_create_edge_list(graph, edge_list);
    // printf(node_list);
    // printf(edge_list);
    char template_file_name[30] = "";
    sprintf(template_file_name, "template%d.html", template_no);
    visgraph_create_html_file(node_list, edge_list, template_file_name, html_file_name);
    html_browse(html_file_name);
    visgraph_free(graph);
}

/**
 * @brief Vẽ visgraph từ graph
 * 
 * @param graph 
 * @param template_no 
 * @param html_file_name 
 */
void visgraph_draw(VisGraph &graph, int template_no = 1, const char *html_file_name = "graph.html")
{
    char node_list[BUFFER_SIZE] = "";
    char edge_list[BUFFER_SIZE] = "";
    visgraph_create_node_list(graph, node_list);
    visgraph_create_edge_list(graph, edge_list);
    char template_file_name[30] = "";
    sprintf(template_file_name, "template%d.html", template_no);
    visgraph_create_html_file(node_list, edge_list, template_file_name, html_file_name);
    html_browse(html_file_name);
    visgraph_free(graph);
}