//Write a program to implement queue operations (INSERT, DELETE, DISPLAY) 
#include<stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue overflow has occurred\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = x;
    }
}     

int delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow has occurred\n");
        return -1;
    } else {
        return queue[front++];
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d - ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}