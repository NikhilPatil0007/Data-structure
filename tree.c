#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *creatnode(int d)
{
    struct node *q = malloc(sizeof(struct node));
    q->left = NULL;
    q->data = d;
    q->right = NULL;
    return q;
}

void Insert(struct node **root, int Data)
{
    struct node *p = *root;
    struct node *q;
    if (p == NULL)
    {
        q = creatnode(Data);
        *root = q;
    }
    else
    {
        while (1)
        {
            if (Data < (p->data))
            {
                if ((p->left) == NULL)
                {
                    q = creatnode(Data);
                    (p->left) = q;
                    break;
                }
                else
                {
                    p = (p->left);
                }
            }
            else
            {
                if ((p->right) == NULL)
                {
                    q = creatnode(Data);
                    (p->right) = q;
                    break;
                }
                else
                {
                    p = (p->right);
                }
            }
        }
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder((root->left));
        printf("%d ", (root->data));
        inorder((root->right));
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", (root->data));
        preorder((root->left));
        preorder((root->right));
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder((root->left));
        postorder((root->right));
        printf("%d ", (root->data));
    }
}

void Display(struct node *root)
{
    int n;
    if (root == NULL)
    {
        printf("Tree is Empty.\n");
    }
    else
    {
        printf("\nINORDER: ");
        inorder(root);

        printf("\nPREORDER: ");
        preorder(root);

        printf("\nPOSTORDER: ");
        postorder(root);
    }
}

int Delete(struct node **root, int Data)
{
    struct node *curr;
    curr = *root;
    struct node *parent = NULL;
    struct node *newcurr;
    struct node *ptr, *r, *temp;
    ptr = *root;
    // printf("")
    if (curr->data == Data && curr->left == NULL && curr->right == NULL)  // if root is only data in tree
    {
        *root = NULL;
        free(curr);
        return 0;
    }

    if (curr->right != NULL && curr->data == Data)    // for root delete 
    {
        parent = curr;
        curr = curr->right;

        if (curr->left == NULL)
        {
            (*root)->data = curr->data;
            parent->right = curr->right;
            free(curr);
        }
        else
        {
            while (1)
            {
                if (curr->left == NULL)
                {
                    (*root)->data = curr->data;
                    parent->left = curr->right;
                    free(curr);
                    break;
                }

                parent = curr;
                curr = curr->left;
            }
        }
        return 0;
    }
    else if ((curr->right) == NULL && curr->data == Data)  // for root delete if right subtree is empty
    {
        parent = curr;
        curr = curr->left;

        if (curr->right == NULL)
        {
            (*root)->data = curr->data;
            parent->left = curr->left;
            free(curr);
        }
        else
        {
            while (1)
            {
                if (curr->right == NULL)
                {

                    (*root)->data = curr->data;
                    parent->right = curr->left;
                    free(curr);
                    break;
                }
                parent = curr;
                curr = curr->right;
            }
        }
        return 0;
    }
    else
    {
        while (curr != NULL && (curr->data) != Data)
        {
            if (Data < (curr->data))
            {
                parent = curr;
                curr = curr->left;
            }
            else
            {
                parent = curr;
                curr = curr->right;
            }
        }
        if (curr == NULL)
        {
            printf("Given Data is not present in Tree.\n");
            return 1;
        }
        else
        {
            // for leaf node
            if ((curr->left) == NULL && (curr->right) == NULL)
            {
                if ((parent->left) == curr)
                {
                    (parent->left) = NULL;
                    free(curr);
                }
                else
                {
                    (parent->right) = NULL;
                    free(curr);
                }

                return 0;
            }
            else
            {
                if ((curr->left) == NULL || (curr->right) == NULL) // logic for one child
                {
                    if ((curr->left) == NULL)
                    {
                        newcurr = (curr->right);
                    }
                    else
                    {
                        newcurr = (curr->left);
                    }

                    if ((parent->left) == curr)
                    {
                        (parent->left) = newcurr;
                        free(curr);
                    }
                    else
                    {
                        (parent->right) = newcurr;
                        free(curr);
                    }

                    return 0;
                }
                else // for intermediate node
                {
                    // r = p = (curr->right);
                    // while ((p->left) != NULL)
                    // {
                    //     r = p;
                    //     p = (p->left);
                    // }
                    // if ((p->right) != NULL)
                    // {
                    //     (r->left) = (p->right);
                    //     (curr->data) = (p->data);
                    //     free(p);
                    // }
                    // else
                    // {
                    //     (r->left) = NULL;
                    //     (curr->data) = (p->data);
                    //     free(p);
                    // }
                    //   if (Data > ptr->data)
                    //   {
                    //    r = curr->left;
                    Delete(&curr, curr->data);

                    return 0;
                }
            }
        }
    }
}
void main()
{
    struct node *root = NULL;
    int choice, Data;
    int r, D;
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert in tree: ");
            scanf("%d", &Data);
            Insert(&root, Data);
            break;

        case 2:
            printf("Enter data which you want to delete from tree: ");
            scanf("%d", &Data);
            r = Delete(&root, Data);
            if (r == 1)
            {
                printf("Element can not be deleted.\n");
            }
            else
            {
                printf("Data deleted successfully.\n");
            }
            break;

        case 3:
            Display(root);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Entered Invalid Input.\n");
        }
    }
}
