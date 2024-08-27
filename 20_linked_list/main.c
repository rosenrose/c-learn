#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node_t;

struct node
{
    int val;
    node_t *next;
};

void print_list(const node_t *head);
void destroy(node_t *head);
void insert_front(node_t **const phead, const int val);
void insert_sorted(node_t **phead, const int val);
void remove_val(node_t **phead, const int val);

int main(void)
{
    node_t *head = NULL;

    insert_front(&head, 3);
    insert_front(&head, 5);
    insert_front(&head, 2);
    insert_front(&head, 0);
    print_list(head);

    remove_val(&head, 3);
    remove_val(&head, 0);
    print_list(head);

    destroy(head);
    head = NULL;

    insert_sorted(&head, 5);
    insert_sorted(&head, 0);
    insert_sorted(&head, 2);
    insert_sorted(&head, 3);
    print_list(head);

    remove_val(&head, 2);
    remove_val(&head, 5);
    print_list(head);

    destroy(head);
    head = NULL;

    return 0;
}

void print_list(const node_t *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }

    putchar('\n');
}

void destroy(node_t *head)
{
    while (head != NULL)
    {
        node_t *next = head->next;

        free(head);
        head = next;
    }
}

void insert_front(node_t **const phead, const int val)
{
    node_t *const new_node = malloc(sizeof(node_t));
    new_node->val = val;

    new_node->next = *phead;
    *phead = new_node;
}

void insert_sorted(node_t **phead, const int val)
{
    node_t *const new_node = malloc(sizeof(node_t));
    new_node->val = val;

    while (*phead != NULL)
    {
        if ((*phead)->val >= val)
        {
            break;
        }

        phead = &((*phead)->next);
    }

    new_node->next = *phead;
    *phead = new_node;
}

void remove_val(node_t **phead, const int val)
{
    while (*phead != NULL)
    {
        if ((*phead)->val == val)
        {
            node_t *remove_node = *phead;

            *phead = remove_node->next;
            free(remove_node);

            return;
        }

        phead = &((*phead)->next);
    }
}
