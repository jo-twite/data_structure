#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* data;
    struct node* next;
} node;

void* newNode(char* str)
{
    node* myNode = (node*) malloc(sizeof(node));
    if (myNode == NULL)
    {
        free(myNode);
        return NULL;
    }
    myNode->data = str;
    myNode->next = NULL;
    return myNode;
}

typedef struct list_q {
    node* head;
    node* tail;
    int size;
} queue;

queue* init_queue()
{
    queue* myQueue = (queue*) malloc(sizeof(queue));
    myQueue-> head = NULL;
    myQueue->tail = NULL;
    myQueue->size = 0;
    return myQueue;
}


void enqueue(queue* myQueue, char* data)
{
    if(myQueue->size == 0)
    {
        myQueue->head = newNode(data);
        myQueue->tail = myQueue->head;
    }
    else
    {
        myQueue->tail->next = newNode(data);
        myQueue->tail = myQueue->tail->next;
    }
    myQueue->size ++;
}

char* dequeue(queue* myQueue)
{
    if(myQueue->size == 0)
    {
        perror("Empty queue.\n");
        return NULL;
    }
    node* deleted = myQueue->head;
    myQueue->head = myQueue->head->next;
    deleted->next = NULL;
    char* ret = deleted->data;
    free(deleted);
    myQueue->size --;
    return ret;
}

void printq(queue* q)
{
    node* iter = q->head;
    while(iter != q->tail)
    {
        printf("%s->", iter->data);
        iter = iter->next;
    }
    printf("%s-> < >\n", q->tail->data);
}

typedef struct list_s {
    node* head;
    int size;
} stack;

stack* init_stack()
{
    
    stack *st = (stack*) malloc(sizeof(stack));
    st-> head = NULL;
    st->size = 0;
    return st;
}

void push(stack* st, char* newData)
{
    if(st->size == 0)
    {
        st->head = newNode(newData);
    }
    else
    {
        node* newHead = newNode(newData);
        newHead->next = st->head;
        st->head = newHead;
    }
    st->size ++;

}

char* pop(stack* st)
{
    if(st->size == 0)
        perror("Empty stack.");
    node* deleted = st->head;
    char* del = deleted->data;
    st->head = st->head->next;
    free(deleted);
    st-> size --;
    return del;
}

void printst(stack* st)
{
    node* iter = st->head;
    while(iter != NULL)
    {
        printf("%s->", iter->data);
        iter = iter->next;
    }
    printf("</>\n");
}