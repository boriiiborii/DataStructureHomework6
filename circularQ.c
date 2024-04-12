/**
 * circularQ.c
 *
 * School of Computer Science, 
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>
//bool함수를 적용하기 위해 include
#include <stdbool.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
bool isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{
	QueueType *cQ = createQueue();
	element data;
	char command;

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
//isEmpty의 함수 리턴값을 Bool타입으로 변경한다
bool isEmpty(QueueType *cQ)
{
    if (cQ->front == cQ->rear) {
        return true;
    }
    return false;
}

/* complete the function */
int isFull(QueueType *cQ)
{
   return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
 int rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
    if (cQ->front == rear) {
        printf("큐 꽉 참. 이후에 isFull함수 넣어줘야함\n");
    } else {
        cQ->queue[rear] = item;
        cQ->rear = rear;
    }
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
  
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;
    //isEmpty메서드를 프린트할때 사용하여 적용하였습니다.
    if (isEmpty(cQ)) {
        printf("큐가 비어있습니다.");
    }else {
    printf("Circular Queue : [");

        i = first;
        while(i != last){
            printf("%3c", cQ->queue[i]);
            i = (i+1)%MAX_QUEUE_SIZE;

        }
    printf(" ]\n");
    }
	
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);

}


