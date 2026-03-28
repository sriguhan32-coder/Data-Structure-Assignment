#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        push(str[i]);

    for (int i = 0; str[i] != '\0'; i++)
        str[i] = pop();

    printf("Reversed String: %s", str);
    return 0;
}