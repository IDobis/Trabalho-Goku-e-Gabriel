#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    Node* temp = s->top;
    char poppedData = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedData;
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int isBalanced(char* exp) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&stack, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (isEmpty(&stack)) {
                return 0; 
            }
            
            char topChar = pop(&stack);
            if (!isMatchingPair(topChar, exp[i])) {
                while(!isEmpty(&stack)) pop(&stack);
                return 0;
            }
        }
    }

    int result = isEmpty(&stack);
    
    while(!isEmpty(&stack)) {
        pop(&stack);
    }
    
    return result;
}

int main() {
    char exp[256];

    printf("Digite a expressao: ");
    if (fgets(exp, sizeof(exp), stdin) != NULL) {
        exp[strcspn(exp, "\n")] = 0;

        if (isBalanced(exp)) {
            printf("A expressao e VALIDA (balanceada).\n");
        } else {
            printf("A expressao e INVALIDA (nao balanceada).\n");
        }
    }

    return 0;
}
