#include <stdio.h>

struct Person{
    int id;//field, attribute
    char name[50];
    int age; 
    float salary; 
};

void input(Person &p){
    printf("Id: ");
    scanf("%d", &p.id);
    printf("Name: ");
    while(getchar() != '\n');//clear keyboard buffer
    scanf("%49[^\n]", p.name);
    while(getchar() != '\n');
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Salary: ");
    scanf("%f", &p.salary);
}

void output(Person p){
    printf("Id: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Salary: %.2f\n", p.salary);
}

int linear_search(Person a[], int n, int id){
    for (int i = 0; i < n; i++)
    {
        if(a[i].id==id){
            return i;
        }
    }
    return -1;
}

int binary_search(Person a[], int low, int high, int id){
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid].id==id){//tim thay
            return mid;
        }else if(a[mid].id<id){//tim tiep o nua phai
            low = mid + 1;
        }else{//tim tiep o nua trai
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    Person a[]={
        {1,"Tran Thanh Hai", 20, 1200},
        {2,"Le Nam Thang", 21, 1300},
        {3,"Nguyen Thanh Hang", 19, 1500},
        {4,"Vo Thanh Hieu", 20, 1600},
        {5,"Tran Van Minh", 22, 1100}
    };

    int n = sizeof(a)/sizeof(struct Person);
    int id = 4;
    //int pos = linear_search(a, n, id);
    int pos = binary_search(a, 0, n-1, id);
    if(pos==-1){
        printf("Person is not found\n");
    }else{
        printf("Position of the person: %d\n", pos);
    } 

    return 0;
}