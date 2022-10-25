#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node node;
struct node
{
    float data;
    node *next;
};
int floor_n(float x)
{
    return ((10 * x) - x);
}
node *insert(node *head, float val)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        node *parent = NULL;
        while (temp->data < val && temp == NULL)
        {
            parent = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            parent->next = p;
        }
        else
        {
            parent->next = p;
            p->next = temp;
        }
    }
    return head;
}
int main()
{
    int size;
    printf("Enter the siz eof the array : ");
    scanf("%d", &size);
    float arr[size];
    int range;
    printf("\nenter the range of the elements : ");
    scanf("%d", &range);
    printf("\nEnter the array elements : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &arr[i]);
    }
    node *head[10];
    for (int i = 0; i < 10; i++)
    {
        head[i] = NULL;
    }
    for (int i = 0; i < size; i++)
    {
        head[floor_n(arr[i])] = insert(head[floor_n(arr[i])], arr[i]);
    }
    printf("\nSorted array is : \n");
    for (int i = 0; i < 10; i++)
    {
        node *temp = head[i];
        while (temp != NULL)
        {
            printf("%0.3f  ", temp->data);
            temp = temp->next;
        }
    }
    return 0;
}