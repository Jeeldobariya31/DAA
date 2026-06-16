//Write a program to implement stack operations (PUSH, POP, PEEP, CHANGE & DISPLAY)
#include<stdio.h>
#define MAX 100 
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow has occurred\n");
    } else {
        stack[++top] = x;
    }
}
int pop() {
    if (top ==-1) {
        printf("Stack Underflow has occurred\n");
        return -1;
    } else {
        return stack[top--];
    }
}
void peep() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void change(int x, int pos) {
    if (pos < 1 || pos > top + 1) {
        printf("Invalid position\n");
    } else {
        stack[top - pos + 1] = x;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d - ", stack[i]);
        }
        printf("\n");
    }
}
 int main(){
        int choice, value, position;
        while (1) {
                printf("1. Push\n2. Pop\n3. Peep\n4. Change\n5. Display\n6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                        printf("Enter value to push: ");
                        scanf("%d", &value);
                        push(value);
                        break;
                case 2:
                        value = pop();
                        if (value != -1) {
                        printf("Popped value is: %d\n", value);
                        }
                        
                        break;
                case 3:
                        peep();
                        break;
                case 4:
                        printf("Enter position(from top) and new value: ");
                        scanf("%d %d", &position, &value);
                        change(value, position);
                        break;
                case 5:
                        display();
                        break;
                case 6:
                        exit(0);
                default:
                        printf("Invalid choice\n");
                }
        }
        return 0;
 }

