#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;
 
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}
 
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    int i, k = 0;

    printf("Infix ifadeyi giriniz: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        // Operand ise direkt postfix'e ekle
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // Açık parantez
        else if (infix[i] == '(') {
            push(infix[i]);
        }

     
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();  
        }

        
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }

 
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix ifade: %s\n", postfix);

    return 0;
}
