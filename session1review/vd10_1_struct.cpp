
#include <stdio.h>
#include <stdlib.h>

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

int main(){
    Person p;
    input(p);
    output(p);
    return 0;
}
1