#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 8

typedef struct
{
    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t full;
}RingBuffer;

void init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->full = 0;
}

int isEmpty(RingBuffer *rb)
{
    return (!rb->full && (rb->head == rb->tail));
}

int isFull(RingBuffer *rb)
{
    return rb->full;
}

uint8_t getCount(RingBuffer *rb)
{
    if(rb->full)
        return BUFFER_SIZE;

    if(rb->head >= rb->tail)
        return rb->head - rb->tail;

    return BUFFER_SIZE - rb->tail + rb->head;
}

int writeData(RingBuffer *rb, uint8_t data)
{
    if(isFull(rb))
        return -1;

    rb->buffer[rb->head] = data;

    rb->head = (rb->head + 1) & (BUFFER_SIZE - 1);

    if(rb->head == rb->tail)
        rb->full = 1;

    return 0;
}

int readData(RingBuffer *rb, uint8_t *data)
{
    if(isEmpty(rb))
        return -1;

    *data = rb->buffer[rb->tail];

    rb->tail = (rb->tail + 1) & (BUFFER_SIZE - 1);

    rb->full = 0;

    return 0;
}

int main()
{
    RingBuffer rb;
    uint8_t data;
    unsigned int value;
    int choice;

    init(&rb);

    while(1)
    {
        printf("\n===== RING BUFFER MENU =====\n");
        printf("1. Write Data\n");
        printf("2. Read Data\n");
        printf("3. Display Count\n");
        printf("4. Check Full\n");
        printf("5. Check Empty\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                printf("Enter Hex Value (Example: 41): ");
                scanf("%x",&value);

                if(writeData(&rb,(uint8_t)value)==0)
                {
                    printf("[WRITE] 0x%02X -> OK (count=%u)",
                           value,
                           getCount(&rb));

                    if(isFull(&rb))
                        printf(" FULL");

                    printf("\n");
                }
                else
                {
                    printf("[WRITE] 0x%02X -> FAIL (buffer full)\n",
                           value);
                }

                break;

            case 2:

                if(readData(&rb,&data)==0)
                {
                    printf("[READ] -> 0x%02X (count=%u)\n",
                           data,
                           getCount(&rb));
                }
                else
                {
                    printf("[READ] (empty) -> FAIL (buffer empty)\n");
                }

                break;

            case 3:

                printf("Current Count = %u\n",
                       getCount(&rb));

                break;

            case 4:

                if(isFull(&rb))
                    printf("Buffer is FULL\n");
                else
                    printf("Buffer is NOT FULL\n");

                break;

            case 5:

                if(isEmpty(&rb))
                    printf("Buffer is EMPTY\n");
                else
                    printf("Buffer is NOT EMPTY\n");

                break;

            case 6:

                printf("Exiting...\n");
                return 0;

            default:

                printf("Invalid Choice\n");
        }
    }

    return 0;
}