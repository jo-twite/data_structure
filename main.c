#include <stdio.h>
#include <stdlib.h>
#include "linkedList.c"

int main()
{
    stack* st = init_stack();
    push(st, "Eddy");
    push(st, "Djodjo");
    push(st, "Pitchou");
    push(st, "Ramy");
    push(st, "Jean-Luc");
    push(st, "Jonathan");
    push(st, "Sarah");
    push(st, "Samuel");
    printst(st);

    printf("%s has been deleted.\n", pop(st));
    printf("%s has been deleted.\n", pop(st));
    printf("%s has been deleted.\n", pop(st));
    printst(st);

    
    queue* q = init_queue();
    enqueue(q, "Eddy");
    enqueue(q, "Djodjo");
    enqueue(q, "Pitchou");
    enqueue(q, "Ramy");
    enqueue(q, "Jean-Luc");
    enqueue(q, "Jonathan");
    enqueue(q, "Sarah");
    enqueue(q, "Samuel");
    printq(q);

    printf("%s has been deleted.\n", dequeue(q));
    printf("%s has been deleted.\n", dequeue(q));
    printf("%s has been deleted.\n", dequeue(q));
    printq(q);
    return 0;
}