//chuyển biểu thức trung tố sang hậu tố
#include "stack2.h"
#include <string.h>

bool is_operand(char c){
    /*
    if(c>='0' && c<='9'){
        return true;
    }
    return false;
    */
    return (c>='0' && c<='9');
}

void append(char *postfix, char c){
    char s[3];
    sprintf(s,"%c ", c);
    strcat(postfix, s);
}

bool is_operator(char c){
    //return (c=='+' || c=='-' || c=='*' || c=='/');
    return strchr("+-*/",c)!=NULL;
}

int priority(char c){
    if(c=='+' || c=='-'){
        return 0;
    }else{//*,/
        return 1;
    }
}

void infix_to_postfix(char *infix, char *postfix){
    STACK stack;
    initialize(stack);
    strcpy(postfix,"");
    int o;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if(is_operand(c)){
            append(postfix, c);            
        }else if(c=='('){
            push(stack,c);
        }else if(is_operator(c)){
            peek(stack,o);
            if(is_operator(o)){
                if(priority(c)<=priority(o)){
                    pop(stack, o);
                    append(postfix, o);
                }                
            }
            push(stack,c);
        }else if(c==')'){
            while(pop(stack, o)){
                if(o != '('){
                    append(postfix, o);
                }else{
                    break;
                }
            };            
        }
    }
    while(pop(stack, o)){
        append(postfix, o);
    }    
}

int main(){
    char *infix = "(2+3)*5-9/(2+1)";//2 3 + 5 * 9 2 1 + / -
    char postfix[100];
    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}