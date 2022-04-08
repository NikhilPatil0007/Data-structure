#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
    int id;
    char name[20];
    float price;
    int quantity;
    float gst;
    struct node *next;
};

void display(struct node *head)
{
    int total_bill;
    if (head == NULL)
    {
        printf("Your Shopping list is Empty!!!!\n");
    }
    else
    {

        printf("\nYour shoping list : \n");
        printf("Id \t   Name     \t Price  \t Quantity \n");
        while (head != NULL)
        {
            printf("%d     \t   ", head->id);
            printf("%s      \t ", head->name);
            printf("%.2f      \t ", (head->price));
            printf("%d         \t", head->quantity);
            printf("\n");
            head = head->next;
        }
    }
}

int countItem(struct node **head)
{
    struct node *ptr = *head;
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    while (ptr->next != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void add_new_item(struct node **head, int ID, char NAME[], float PRICE, int QUANTITY, float GST)
{

    struct node *ptr = *head;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->id = ID;
    strcpy(temp->name, NAME);
    temp->price = PRICE;
    temp->quantity = QUANTITY;
    temp->gst = GST;
    temp->next = NULL;

    if (ptr == NULL)
    {
        (*head) = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void delete_item(struct node **head, int ID)
{
    struct node *ptr;
    struct node *temp;
    ptr = *head;
    temp = ptr;
    int count = 0;
    int flag = 0;

    // int count = countItem(head);
    if (*head == NULL)
    {
        printf("\nYour List is EMPTY!!!!!\n");
    }
    else
    {
        if (ptr->next == NULL) // only one element in cart
        {
            *head = NULL;

        }
        else
        {
            while (ptr->next != NULL) 
            {
                if (ptr->id == ID && count == 0) // if first item from the cart to remove
                {
                    *head = ptr->next;
                    free(ptr);
                    flag = 0;
                    break;
                }
                else if (ptr->id == ID && count != 0) 
                {
                    temp->next = ptr->next;
                    free(ptr);
                    flag = 0;
                    break;
                }
               
                temp = ptr;
                ptr = ptr->next;
                count++;
            }
            if (ptr->id  == ID)
            {
                temp ->next = ptr ->next;
                free(ptr);
            }
            
            if (flag == 1)
            {
                printf("\nItem not found in the cart !!\n");
            }
            else
            {
                printf("\nItem is removed from the cart!!\n");
            }
        }
    }
}

int bill(struct node *head)
{
    float sum = 0;
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf(" Your cart is empty!!\n");
        return 0;
    }
    else
    {
        while (ptr != NULL)
        {
            sum = sum + (ptr->price);
            ptr = ptr->next;
        }
        return sum;
    }
}

void main()
{
    int item, choice, r;
    struct node *head;
    head = NULL;
    int ID, QUANTITY;
    float PRICE, GST;
    char NAME[10];
    float total = 0;
    printf("1.Insert new item in list\n2.Delete item from list\n3.Display List\n4.Generate bill\n5.Exiit\n");

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter Product id : ");
            scanf("%d", &ID);
            printf("Enter Product Name : ");
            scanf("%s", &NAME);
            printf("Enter Product Price : ");
            scanf("%f", &PRICE);
            printf("Enter Product Quantity : ");
            scanf("%d", &QUANTITY);

            GST = PRICE * 0.15;

            add_new_item(&head, ID, NAME, PRICE, QUANTITY, GST);
            break;

        case 2:
            printf("Enter Product id to Delete Product  : ");
            scanf("%d", &ID);
            delete_item(&head, ID);
            break;

        case 3:
            display(head);
            break;

        case 4:
                total = bill(head);
            	printf("\nTotal Bill Amount = %.2f\n", total);
            break;

        default:
            printf("Enter a valid choice!!!1111\n");
            break;
        }
    }
}