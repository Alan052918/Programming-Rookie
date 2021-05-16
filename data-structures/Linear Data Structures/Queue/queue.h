#ifndef QUEUE_H_
#define QUEUE_H_
typedef struct QNode {
  int data;
  struct QNode *next;
} QNode;

typedef struct Queue {
  QNode *head, *rear;
};

void Dequeue(Queue *queue)
#endif  // QUEUE_H_
