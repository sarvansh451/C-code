#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void insert(int item) {
    if (isFull()) {
        printf("Queue is full, cannot insert.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int deleted() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty, cannot delete.\n");
        exit(1);
    }
    item = queue[front];
    front++;
    return item;
}

void reverseQueue(int index);

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    printf("Original queue: ");
    display();

    reverseQueue(0);
    printf("Reversed queue: ");
    display();

    return 0;
}

void reverseQueue(int index) {
    if (index == rear + 1) {
        return; // Base case
    }

    int item = deleted();
    reverseQueue(index + 1);
    insert(item);
}

