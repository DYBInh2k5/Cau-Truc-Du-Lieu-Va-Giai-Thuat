#ifndef DATATYPE //nếu chưa định nghĩa DATATYPE

#define DATATYPE //định nghĩa DATATYPE (DATATYPE là tên giả để làm điều kiện kiểm tra)

//khai báo dữ liệu cho cấu trúc TREE
#define DATA int

typedef struct NODE
{
    DATA info;
    NODE *left;
    NODE *right;
} NODE;

typedef struct TREE
{
    NODE *root;
} TREE;

//Khai báo dữ liệu cho cấu trúc QUEUE
#define QDATA NODE*
#define N 100

typedef struct {
    int front;
    int rear;
    QDATA a[N];
    int count;
} QUEUE;

#endif