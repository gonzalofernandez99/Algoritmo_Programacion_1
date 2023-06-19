#include <iostream>

struct Stack {
    int data;
    Stack* next;
};

bool isStackEmpty(Stack* top) {
    return !top;
}

void push(Stack** top, int new_data) {
    Stack* new_node = new Stack;
    if (!new_node) {
        std::cout << "Error de heap overflow" << std::endl;
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*top);
    (*top) = new_node;
}

int pop(Stack** top) {
    Stack* temp;
    int popped;
    if (isStackEmpty(*top)) {
        std::cout << "Underflow de pila" << std::endl;
        exit(0);
    } else {
        temp = *top;
        popped = temp->data;
        *top = temp->next;
        delete temp;
        return popped;
    }
}

int peek(Stack* top) {
    if (!isStackEmpty(top))
        return top->data;
    else
        exit(0);
}

void enqueue(Stack** top1, int x) {
    push(top1, x);
}

int dequeue(Stack** top1, Stack** top2) {
    int x;

    if (isStackEmpty(*top1) && isStackEmpty(*top2)) {
        std::cout << "La cola está vacía" << std::endl;
        exit(0);
    }

    if (isStackEmpty(*top2)) {
        while (!isStackEmpty(*top1)) {
            x = pop(top1);
            push(top2, x);
        }
    }

    x = pop(top2);
    return x;
}



int main() {
    Stack *top1 = nullptr, *top2 = nullptr;
    enqueue(&top1, 1);
    enqueue(&top1, 2);
    enqueue(&top1, 3);

    std::cout << "Desencolado: " << dequeue(&top1, &top2) << std::endl;
    std::cout << "Desencolado: " << dequeue(&top1, &top2) << std::endl;

    return 0;
}
