#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node
{
    int data;
    struct node *next;
};

// case 12:  Displaying Element of Listed List
void display(struct node *head)
{
    struct node *ptr = head;

    int i = 1;
    if (ptr == NULL)
    {
        printf("\nThe list is Empty ");
    }
    while (ptr != NULL)
    {
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
}

// case 11: for counting node
int count_node(struct node *head)
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {

        count++;
        ptr = ptr->next;
    }
    // printf("%d\n", count);
    return count;
}
// Case 1  adding at beginning
void *InsertAtBeginning(struct node **head, int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = *head;
    *head = ptr;
    // return head;
}

// Case 2   insert at index
void *InsertAtIndex(struct node **head, int index, int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int total_element = count_node(*head);
    if (*head == NULL)
    {
        printf("\nAdding data to first Position ,as Your list is Empty :\n");
        ptr->data = num;
        ptr->next = *head;
        *head = ptr;
    }
    else if (index == 1)
    {
        ptr->data = num;
        ptr->next = *head;
        *head = ptr;
    }
    else if (index <= 0)
    {
        printf("\nEnter a valid index !! :\n ");
    }
    else if (index > total_element)
    {
        printf("\nEntered index is greater than number of node ,Please Enter a valid index : \n");
    }

    else
    {
        struct node *a = *head;
        int i = 1;
        while (i != index)
        {
            a = a->next;
            i++;
        }
        ptr->data = num;
        ptr->next = a->next;
        a->next = ptr;
    }
    // return *head;
}

// Case 3    insert at end
struct node *InsertAtEnd(struct node **head, int num)
{
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));

    if (*head == NULL)
    {

        ptr2->data = num;
        ptr2->next = *head;
        *head = ptr2;
    }
    else

    {
        ptr2->data = num;
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr2;
        ptr2->next = NULL;
    }
    return *head;
}

// case 4  insert after a specified position in the list
struct node *insert_after(struct node **head, int index, int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;

    int total_element = count_node(*head);
    if (index <= 0)
    {
        printf("\nEnter a valid index !! :\n ");
    }
    else if (*head == NULL)
    {
        printf("\nAdding data to first Position ,as Your list is Empty :\n");
        ptr->data = num;
        ptr->next = *head;
        *head = ptr;
    }
    else if (index > total_element)
    {
        printf("\nEntered index is greater than number of node ,Please Enter a valid index : \n");
    }
    // else if (index == 0)
    // {
    //     ptr->data = num;
    //     ptr->next = *head;
    //     *head = ptr;
    // }
    else

    {
        int i = 0;
        while (i != index - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr->data = num;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return *head;
}

//  case 5 insert before a specified position in the list
struct node *insert_before(struct node **head, int index, int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = *head;

    int total_element = count_node(*head);

    if (*head == NULL)
    {
        printf("\nAdding data to first Position ,as Your list is Empty :\n");
        ptr->data = num;
        ptr->next = *head;
        *head = ptr;
    }
    else if (index <= 1 || index > total_element)
    {
        printf("\nEnter a valid index !! :\n ");
    }

    else
    {
        int i = 0;
        while (i != index - 3)
        {
            p = p->next;
            i++;
        }
        ptr->data = num;
        ptr->next = p->next;
        p->next = ptr;
    }
    return *head;
}

// Case 6   Deleting the first element from the linked list
void DeleteFirstNode(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nNothing to delete,as your List is Empty \n");
    }
    else
    {
        struct node *ptr = *head;
        *head = ptr->next;
        free(ptr);
    }
}

// Case 7: Deleting the element at a given index from the linked list
void DeleteAtIndex(struct node **head, int index)
{
    printf("*head =  %d\n", *head);
    printf("head =  %d\n", head);
    printf("&head =  %d\n", &head);
    printf("**head =  %d\n",**head);
    int total_element = count_node(*head);
    if (*head == NULL)
    {
        printf("\nNothing to Delete,as Your list is Empty :\n");
    }

    if (index == 1)
    {
        struct node *ptr = *head;
        *head = ptr->next;
        free(ptr);
    }
    else if (index > total_element || index <= 0)
    {

        printf("\nEnter a valid index : \n");
        printf("\nElement is present : %d \n", total_element);
    }
    else
    {
        struct node *temp = *head;
        struct node *q = temp->next;
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->next;
            q = q->next;
        }

        temp->next = q->next;
        free(q);
    }
}
// Case 8: Deleting the element before given index
void Deletebefore(struct node **head, int index)
{
    int total_element = count_node(*head);
    if (*head == NULL)
    {
        printf("\nNothing to Delete,as Your list is Empty :\n");
    }
    else if (index > total_element || index <= 1)
    {
        printf("\nEnter a valid index : \n");
    }
    else
    {

        struct node *temp = *head;
        struct node *ptr = temp->next;
        for (int i = 0; i < index - 3; i++)
        {
            temp = temp->next;
            ptr = ptr->next;
        }

        temp->next = ptr->next;
        free(ptr);
    }
}

// Case 9: Deleting the element after given index
void Deleteafter(struct node **head, int index)
{
    int total_element = count_node(*head);
    if (*head == NULL)
    {
        printf("\nNothing to Delete,as Your list is Empty :\n");
    }
    else if (index >= total_element || index <= 0)
    {
        printf("\nEnter a valid index : \n");
    }
    else
    {
        struct node *p = *head;
        struct node *q = p->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }

        p->next = q->next;
        free(q);
    }
}

// Case 10: Deleting the last element
void DeleteAtLast(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nNothing to Delete,as Your list is Empty :\n");
    }
    else
    {
        struct node *temp = *head;
        struct node *ptr = temp->next;
        while (ptr->next != NULL)
        {
            temp = temp->next;
            ptr = ptr->next;
        }

        temp->next = NULL;
        free(ptr);
    }
}

// // case 14 : for searching data in node
// int search_data(struct node **head, int element)
// {
//     if (*head == NULL)
//     {
//         printf("\nNothing to Delete,as Your list is Empty :\n");
//     }
//     else
//     {
//         int index = 0;
//         struct node *ptr = *head;
//         while (ptr != NULL)
//         {
//             index++;
//             if (ptr->data == element)
//             {
//                 printf("Data is found at node : %d", index);
//                 break;
//             }
//             ptr = ptr->next;
//         }
//     }
// }
// // // Case 13: Deleting the element with a given value from the linked list
// struct node *DeleteByValue(struct node **head, int value)
// {

//     if (*head == NULL)
//     {
//         printf("\nNothing to Delete,as Your list is Empty :\n");
//     }
//     else
//     {
//         struct node *p = *head;
//         struct node *q = p->next;
//         while (q->data != value && q->next != NULL)
//         {
//             p = p->next;
//             q = q->next;
//         }
//         if (q->data == value)
//         {
//             p->next = q->next;
//             free(q);
//         }
//     }
//     return *head;
// }
// *************************************************************************************************************************

int main()
{
    int count;

    struct node *head = NULL;

    int choice, data, index, position;

    printf("\nWhich Operation You want to Perform");
    printf("\n1.Insert At Beginning\n2.Insert At Index\n3.Insert At End\n4.Insert After Node\n5.Insert Before Node\n");
    printf("6.Delete First Node\n7.Delete At Index\n8.Delete before Node\n9.Delete after Nodes\n10.Delete At End\n11.Count_node\n12.Display\n13.Exit\n\n ");
    while (1)
    {

        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the data You want to add : ");
            scanf("%d", &data);

            InsertAtBeginning(&head, data);
            break;

        case 2:

            printf("Enter the index You want to add data : ");
            scanf("%d", &index);

            printf("Enter the data You want to add : ");
            scanf("%d", &data);

            // printf("\nTotal number of nodes present in your single linked list : ");
            InsertAtIndex(&head, index, data);

            break;

        case 3:

            printf("Enter the data You want to add : ");
            scanf("%d", &data);

            InsertAtEnd(&head, data);
            break;

        case 4:

            printf("Enter the position to insert after : ");
            scanf("%d", &position);

            printf("Enter the data to insert : ");
            scanf("%d", &data);

            insert_after(&head, position, data);
            break;

        case 5:

            printf("Enter the position to insert before : ");
            scanf("%d", &position);

            printf("Enter the data to insert : ");
            scanf("%d", &data);

            insert_before(&head, position, data);
            break;

        case 6:

            DeleteFirstNode(&head);
            break;

        case 7:

            printf("Enter the index delete the data : ");
            scanf("%d", &data);

            DeleteAtIndex(&head, data);
            break;

        case 8:

            printf("Enter the index to delete before : ");
            scanf("%d", &index);

            Deletebefore(&head, index);
            break;

        case 9:

            printf("\nEnter the index to delete after : ");
            scanf("%d", &index);

            Deleteafter(&head, index);
            break;

        case 10:

            DeleteAtLast(&head);
            break;

        case 11:
            printf("\nTotal number of nodes : %d \n", count_node(head));
            count_node(head);
            break;

        case 12:

            display(head);
            break;

            // case 13:

            //     printf("\nEnter the data you want to delete : ");
            //     scanf("%d", &data);
            //     DeleteByValue(&head, data);
            //     break;

            // case 14:
            //     printf("\nEnter the data you want ot search : ");
            //     scanf("%d", &data);
            //     break;

        case 13:

            exit(0);
            break;

        default:

            printf("\nPlease enter a valid choice!\n");
            break;
        }
    }

    return 0;
}
