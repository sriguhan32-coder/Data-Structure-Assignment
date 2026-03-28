#include <stdio.h>

#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int doc) {
    if (rear == MAX - 1) {
        printf("Queue Full!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = doc;
    printf("Document %d added.\n", doc);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No documents to print.\n");
        return;
    }
    printf("Printing document %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("No pending documents.\n");
        return;
    }
    printf("Pending documents:\n");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, doc;

    while (1) {
        printf("\n1. Add Document\n2. Print Document\n3. Display Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter document number: ");
                scanf("%d", &doc);
                enqueue(doc);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!");
        }
    }
}