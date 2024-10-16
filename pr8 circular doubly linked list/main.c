#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} *Head = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    Head->prev = Head;
    last = Head;

    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        Head->prev = t;
        last = t;
    }
}

void Display(struct Node *h) {
    if (Head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}
int Length(struct Node *p) {
    int len = 0;
    if (Head == NULL) return len;
    do {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void Insert(struct Node *p, int index, int x) {
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p))
        return;

    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
            Head->prev = Head;
        } else {
            while (p->next != Head) p = p->next;
            p->next = t;
            t->next = Head;
            t->prev = p;
            Head->prev = t;
            Head = t;
        }
    } else {
        for (i = 0; i < index - 1; i++) p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next != Head) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int Delete(struct Node *p, int index) {
    struct Node *q;
    int i, x;

    if (index < 0 || index >= Length(Head))
        return -1;
    if (index == 0) {
        while (p->next != Head) p = p->next;
        x = Head->data;
        if (Head == p) {
            free(Head);
            Head = NULL;
        } else {
            p->next = Head->next;
            Head->next->prev = p;
            free(Head);
            Head = p->next;
        }
    } else {
        for (i = 0; i < index - 1; i++) p = p->next;
        q = p->next;
        p->next = q->next;
        if (q->next != Head) {
            q->next->prev = p;
        }
        x = q->data;
        free(q);
    }
    return x;
}

int main() {
    int choice, data, index, n, i;
    int A[100];

    do {
        printf("\nMenu:\n");
        printf("1. Create Circular Doubly Linked List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &A[i]);
                }
                create(A, n);
                break;
            case 2:
                printf("Enter index and data to insert: ");
                scanf("%d %d", &index, &data);
                Insert(Head, index, data);
                break;
            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                data = Delete(Head, index);
                if (data != -1) {
                    printf("Deleted element: %d\n", data);
                } else {
                    printf("Invalid index\n");
                }
                break;
            case 4:
                Display(Head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
