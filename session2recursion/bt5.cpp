
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
    //fflush(stdin);//xoa sach keyboard buffer
    while(getchar() != '\n');//clear keyboard buffer
    scanf("%49[^\n]", p.name);
    //fflush(stdin);//xoa sach keyboard buffer
    while(getchar() != '\n');//clear keyboard buffer
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

int menu(){
    int choice;
    printf("-------M E N U--------\n");
    printf("1. Input data\n");
    printf("2. Output data\n");
    printf("0. Exit\n");
    printf("----------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    Person p;
    
    while(1){
        int choice = menu();
        switch(choice){
            case 1:
                input(p);
                break;
            case 2:
                output(p);
                break;
            default:
                return 0;
        }
        //an phim bat ky de tiep tuc
        system("pause");
        //xoa man hinh
        system("cls");
    }
    return 0;
}
1