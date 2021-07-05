#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int size;
    int front;
    int rear;
};
void create(struct Queue *q, int s)
{
    q->front = q->rear = 0;
    q->size = s;
    q->arr = (int *)malloc(sizeof(int) * q->size);
}
void Enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Q is full");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
}
int deQ(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("q is empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i = q.front + 1;

    do
    {

        printf("%d ", q.arr[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}

int main()
{
    struct Queue w;
    printf("Enter the size \n");
    scanf("%d", &w.size);

    create(&w, w.size);
    Enqueue(&w, 10);
    Enqueue(&w, 20);
    Enqueue(&w, 30);
    Enqueue(&w, 40);
    display(w);
}

