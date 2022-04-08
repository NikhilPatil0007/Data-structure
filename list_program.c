#include <stdio.h>
#include <stdlib.h>

// function declaration of inserting the element
int insert_at(int position, int data, int size, int list[])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        if (list[i] == '\0' && i == position)
        {
            list[position] = data;
        }
        else if (list[i] != '\0' && i == position)
        {
            list[i + 2] = list[i + 1];
            list[i + 1] = list[i];
            list[i] = data;
        }
        printf("%d ", list[i]);
    }
}

// function declaration of deleting the element
int delete_at(int position, int size, int list[])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        if (list[i] == '\0' && i == position)
        {
            printf("\nNo data present at the given position.");
        }
        else if (list[i] != '\0' && i == position)
        {
            for (j = i; j < size - i; j++)
            {
                list[j] = list[j + 1];
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
}

// function declaration for searching in array
int search_at(int data, int size, int list[])
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == data)
        {
            printf("WE found your data at position : %d ", list[i]);
        }
        else
        {
            printf("Sorry your data in not available in this array ! ");
        }
    }
}
// function declaration for displaying the list data
int display(int size, int list[])
{
    int i;
    else{
    for (i = 0; i < size; i++)
    {
        printf("Position %d : %d\n", i, list[i]);
    }
}
//   for sorting array
int sort_list(int sort, int size, int list[])
{
    int i, j, temp;
    if (sort == 1)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (list[i] < list[j])
                {
                    temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
        for (i = 0; i < size; i++)
        {
            printf("%d ", list[i]);
        }
    }
}

int main()
{
    int list[100];
    int size, position, data, operation, sort;
    int i, j, k;
    char end;
    int flag = 0;
    int insert_element, delete_element, search_element, display_list, sorting;

    printf("Enter the size of the list : "); // inputing the size of list
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        list[i] = -1;
    }

    // while (size != 0)
    // {
    //     for (i = 0; i < size; i++)
    //     {
    //         if (list[i] == '\0') //checking the empty spaces in the list
    //         {
    //             flag = 1;
    //         }
    //         else
    //         {
    //             flag = 0;
    //         }
    //     }
    //     if (flag == 1)
    //     {
    //         printf("\nSpace is available.\n");
    //     }
    //     else
    //     {
    //         printf("\nSpace is not available.\n");
    //     }

    printf("1.Inserting\n2.Deleting\n3.Searching\n4.Display\n5.Sort\n6.Exit\n");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
        printf("\nEnter the position to insert : ");
        scanf("%d", &position);
        printf("Enter the data to input on that position : ");
        scanf("%d", &data);
        insert_element = insert_at(position, data, size, list);
        break;

    case 2:

        // delete an element
        {
            printf("\nEnter the position to delete its data : ");
            scanf("%d", &position);

            delete_element = delete_at(position, size, list); // delete_at function call
        }
        break;
    case 3:
        // search an element
        {
            printf("\nEnter the position to search the element : ");
            scanf("%d", &position);

            search_element = search_at(position, size, list); // search_at function call
        }
    case 4:
        // display the list
        {
            printf("\nThe list is : \n");

            display_list = display(size, list); // display function call
        }
        break;
    case 5:
        // sorting the list in a manner
        {
            printf("\nEnter the way you want to sort (1:Ascending, 2:Descending): ");
            scanf("%d", &sort);

            sorting = sort_list(sort, size, list); // sort_list function call
        }
        break;
    case 6:
        // exiting the loop
        exit(0);

    default:
        printf("YOU ENTERED SOMETHING INVALID !");
    }

    return 0;
}