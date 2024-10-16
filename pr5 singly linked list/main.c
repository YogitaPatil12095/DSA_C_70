#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        last->next = t;
        last = t;
    }
    last->next = NULL;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert(struct Node *p, int val, int index) {
    struct Node *t;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    if (index == 0) {
        t->next = first;
        first = t;
    } else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index) {
    struct Node *q = NULL;
    int x = -1, i;
    if (index == 0) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for (i = 0; i < index; i++) {
            q = p;
            p = p->next;
        }
        if (p != NULL) {
            q->next = p->next;
            x = p->data;
            free(p);
            return x;
        }
    }
    return -1;
}

int main() {
    int A[] = {8, 13, 14, 20, 25, 39, 52, 33, 60};
    int size = 9;
    int choice, val, index, s;
    create(A, size);
    printf("Which operation do you want to perform on the linked list? \n");
    printf("1. Insert \n2. Delete \n3. Display \n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Which value do you want to insert? ");
                scanf("%d", &val);
                printf("Enter the index at which you want to insert the value: ");
                scanf("%d", &index);
                insert(first, val, index);
                break;

            case 2:
                printf("Enter the index at which you want to delete the value: ");
                scanf("%d", &index);
                s = Delete(first, index);
                if (s != -1) {
                    printf("The value deleted is: %d\n", s);
                } else {
                    printf("Invalid index for deletion.\n");
                }
                break;

            case 3:
                printf("The linked list is: \n");
                Display(first);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
