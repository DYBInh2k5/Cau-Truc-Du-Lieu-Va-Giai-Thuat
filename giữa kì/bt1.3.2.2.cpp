//tính biểu thức hậu tố
#include "stack2.h"
#include <string.h>
#include <float.h>

bool is_operand(char c){
    /*
    //C1
    if(c>='0' || c<='9'){
        return true;
    }
    return false;
    */
    //C2
    //return c>='0' || c<='9';
    //C3
    return strchr("0123456789", c) != NULL;
}

bool is_operator(char c){
    //return c=='+' || c=='-' || c=='*' || c=='/';
    return strchr("+-*/", c) != NULL;
}

double calculate(double n1, double n2, char op){//n1 op n2
    switch(op){
        case '+':
            return n1 + n2;
            break;
        case '-':
            return n1 - n2;
            break;
        case '*':
            return n1 * n2;
            break;
        case '/':
            return n1 / n2;
            break;        
    }
    return DBL_MAX;
}

double evaluate(const char *postfix){
    STACK stack;
    initialize(stack);    
    char c;

    for (int i = 0; (c=postfix[i])!='\0'; i++)
    {
        if(is_operand(c)){
            push(stack, c-'0'); //đổi từ char sang int. VD: '2' --> 2
        }else if(is_operator(c)){
            double n1, n2;
            pop(stack, n1);
            pop(stack, n2);
            push(stack, calculate(n2, n1, c)); //tính: n2 c n1
        }
    }
    double result;
    pop(stack, result);
    return result;
}

int main(){
    const char *postfix="2 3 + 5 * 9 3 1 + / -";
    //const char *postfix="9 2 /";
    double result = evaluate(postfix);
    printf("Result: %.2lf\n", result);
    return 0;
}