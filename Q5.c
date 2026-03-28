#include <stdio.h>

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int x) {
    if (isFull()) {
        printf("Circular Queue Full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    cq[rear] = x;
    printf("Inserted %d\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Removed %d\n", cq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void peek() {
    if (isEmpty())
        printf("Circular Queue Empty!\n");
    else
        printf("Front Element: %d\n", cq[front]);
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!");
        }
    }
}