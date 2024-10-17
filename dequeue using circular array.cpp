#include <stdio.h>
#include <stdlib.h>


int CAP=5;
typedef struct DQ {
    int *arr;
    int capacity;
} dq;

int front = -1;
int rear = -1;

void insertatfront();
void insertatrear();
void deleteatfront();
void deleteatrear();
void getfront();
void getrear();
int *initdq(int CAP);

int main() {
    int val, option;

    dq.arr = initdq(CAP);

    do {
        printf("\n****MAIN MENU****\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Get front\n");
        printf("6. Get rear\n");
        printf("7. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertatfront();
                break;
            case 2:
                insertatrear();
                break;
            case 3:
                deleteatfront();
                break;
            case 4:
                deleteatrear();
                break;
            case 5:
                getfront();
                break;
            case 6:
                getrear();
                break;
        }

    } while (option != 7);

    free(dq.arr); // Free the memory allocated for the deque array
    return 0;
}

int *initdq(int CAP) {
    dq.capacity = CAP;
    dq.arr = (int *)malloc(sizeof(int) * CAP);
    return dq.arr;
}

void insertatfront() {
    int value;
    printf("Enter the value to insert at the front: ");
    scanf("%d", &value);

    if ((front == 0 && rear == dq.capacity - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = dq.capacity - 1;
    } else {
        front--;
    }

    dq.arr[front] = value;
    printf("Inserted %d at the front.\n", value);
}

void insertatrear() {
    int value;
    printf("Enter the value to insert at the rear: ");
    scanf("%d", &value);

    if ((front == 0 && rear == dq.capacity - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if (rear == dq.capacity - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq.arr[rear] = value;
    printf("Inserted %d at the rear.\n", value);
}

void deleteatfront() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    } else if (front == rear) {
        printf("Deleted %d from the front.\n", dq.arr[front]);
        front = rear = -1;
    } else if (front == dq.capacity - 1) {
        printf("Deleted %d from the front.\n", dq.arr[front]);
        front = 0;
    } else {
        printf("Deleted %d from the front.\n", dq.arr[front]);
        front++;
    }
}

void deleteatrear() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    } else if (front == rear) {
        printf("Deleted %d from the rear.\n", dq.arr[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Deleted %d from the rear.\n", dq.arr[rear]);
        rear = dq.capacity - 1;
    } else {
        printf("Deleted %d from the rear.\n", dq.arr[rear]);
        rear--;
    }
}

void getfront() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Front element: %d\n", dq.arr[front]);
}

void getrear() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Rear element: %d\n", dq.arr[rear]);
}

