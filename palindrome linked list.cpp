#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    int size = 0;
    struct Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    int arr[size];
    current = head;
    for (int i = 0; i < size; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        if (arr[i] != arr[j]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // It's a palindrome
}

int main() {
    struct Node* head = NULL;

    // Push elements onto the linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        printf("Linked list is a palindrome.\n");
    } else {
        printf("Linked list is not a palindrome.\n");
    }

    return 0;
}
