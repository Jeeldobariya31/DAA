//Write a program to implement singly linked list operations (INSERT, DELETE, DISPLAY) 
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insert(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}




int deleteByValue(int val){
     if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }   
    else if (head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return val;
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data != val) {
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Value %d not found in the list\n", val);
            return -1;
        } else {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return val;
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        printf("List elements are: ");
        while (temp != NULL) {
            printf("%d - ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
        int value, choice;
        while(1){
                printf("1. Insert\n2. Delete by Value\n3. Display\n4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                        case 1:
                                printf("Enter value to insert: ");
                                scanf("%d", &value);
                                insert(value);
                                break;
                        
                        
                        case 2:
                                printf("Enter value to delete: ");
                                scanf("%d", &value);
                                value = deleteByValue(value);
                                if (value != -1) {
                                        printf("Deleted value: %d\n", value);
                                }
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("Invalid choice\n");
                }
        }
        return 0;
}
