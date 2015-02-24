#include <stdio.h>
#include <stdlib.h>
#define MAX 50 
#define MAX_TREE_HT 100
 
struct QueueNode
{
    char data;
    unsigned freq;
    struct QueueNode *left, *right;
};
 
// Structure for Queue: collection of Huffman Tree nodes (or QueueNodes)
struct Queue
{
    int front, rear;
    int capacity;
    struct QueueNode **array;
};
 
// A utility function to create a new Queuenode
struct QueueNode* newNode(char data, unsigned freq)
{
    struct QueueNode* temp =
       (struct QueueNode*) malloc(sizeof(struct QueueNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 
// A utility function to create a Queue of given capacity
struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array =
      (struct QueueNode**) malloc(queue->capacity * sizeof(struct QueueNode*));
    return queue;
}
 
// A utility function to check if size of given queue is 1
int isSizeOne(struct Queue* queue)
{
    return queue->front == queue->rear && queue->front != -1;
}
 
// A utility function to check if given queue is empty
int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}
 
// A utility function to check if given queue is full
int isFull(struct Queue* queue)
{
    return queue->rear == queue->capacity - 1;
}
 
// A utility function to add an item to queue
void enQueue(struct Queue* queue, struct QueueNode* item)
{
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = item;
    if (queue->front == -1)
        ++queue->front;
}
 
// A utility function to remove an item from queue
struct QueueNode* deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
    struct QueueNode* temp = queue->array[queue->front];
    if (queue->front == queue->rear)  // If there is only one item in queue
        queue->front = queue->rear = -1;
    else
        ++queue->front;
    return temp;
}
 
// A utility function to get from of queue
struct QueueNode* getFront(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
    return queue->array[queue->front];
}
 
/* A function to get minimum item from two queues */
struct QueueNode* findMin(struct Queue* firstQueue, struct Queue* secondQueue)
{
    // Step 3.a: If second queue is empty, dequeue from first queue
    if (isEmpty(firstQueue))
        return deQueue(secondQueue);
 
    // Step 3.b: If first queue is empty, dequeue from second queue
    if (isEmpty(secondQueue))
        return deQueue(firstQueue);
 
    // Step 3.c:  Else, compare the front of two queues and dequeue minimum
    if (getFront(firstQueue)->freq < getFront(secondQueue)->freq)
        return deQueue(firstQueue);
 
    return deQueue(secondQueue);
}
 
// Utility function to check if this node is leaf
int isLeaf(struct QueueNode* root)
{
    return !(root->left) && !(root->right) ;
}
 
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
 
struct QueueNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct QueueNode *left, *right, *top;
 
    // Step 1: Create two empty queues
    struct Queue* firstQueue  = createQueue(size);
    struct Queue* secondQueue = createQueue(size);
 
    int i;
    for (i = 0; i < size; ++i)
        enQueue(firstQueue, newNode(data[i], freq[i]));

    while (!(isEmpty(firstQueue) && isSizeOne(secondQueue)))
    {
        left = findMin(firstQueue, secondQueue);
        right = findMin(firstQueue, secondQueue);
 
        top = newNode('$' , left->freq + right->freq);
        top->left = left;
        top->right = right;
        enQueue(secondQueue, top);
    }
 
    return deQueue(secondQueue);
}
 
void printCodes(struct QueueNode* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
 
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
 
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
 
void HuffmanCodes(char data[], int freq[], int size)
{
   struct QueueNode* root = buildHuffmanTree(data, freq, size);
 
   int arr[MAX_TREE_HT], top = 0;
   printCodes(root, arr, top);
}


main()
{
	int size;
	char newstring[]={'w','g','y','j'};
	int countval[]={1,5,3,4};
	size = sizeof(newstring)/sizeof(newstring[0]);
	HuffmanCodes(newstring, countval, size);

}
