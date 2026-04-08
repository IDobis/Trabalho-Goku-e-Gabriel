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

void reverseString(char* str) {
    Stack s;
    initStack(&s);
    
    int i = 0;
    while (str[i] != '\0') {
        push(&s, str[i]);
        i++;
    }
    
    i = 0;
    while (!isEmpty(&s)) {
        str[i] = pop(&s);
        i++;
    }
}

int main() {
    char str[256];

    printf("Digite a string para inverter: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = 0;

        reverseString(str);

        printf("String invertida: %s\n", str);
    }

    return 0;
}
