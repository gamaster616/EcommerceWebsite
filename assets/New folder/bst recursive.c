#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
};


struct tree_node *insert(struct tree_node *root, int value)
{
    struct tree_node *temp = root;
    struct tree_node *newnode = (struct tree_node *)malloc(sizeof(struct tree_node));
    newnode->data = value;
    newnode->right = NULL;
    newnode->left = NULL;
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    if (newnode->data < temp->data)
    {
        temp->left = insert(temp->left, value);
    }
    else if (newnode->data > temp->data)
    {
        temp->right = insert(temp->right, value);
    }
    else
    {
        printf("Element already exists\n");
        free(newnode);
    }
    return root;
}
struct tree_node *find_minimum(struct tree_node *root)
{
    // Root stores the minimal value.
    if (root->left == NULL)
        return root;
    // The left subtreeof the root stores the minimal value.
    else
        return find_minimum(root->left);
}

struct tree_node *delete (struct tree_node *root, int x)
{
    //searching for the item to be deleted
    if (root == NULL)
        return NULL;

    if (x > root->data)
        root->right = delete (root->right, x);
    else if (x < root->data)
        root->left = delete (root->left, x);
    else
    {
        //No Children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        } //one child
        else if (root->left == NULL || root->right == NULL)
        {
            struct tree_node *temp;
            if (root->left == NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        } //Two Children
        else
        {
            struct tree_node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct tree_node *p)
{
    if (p != NULL)
    {
        printf("%4d", p->data);
        preorder(p->left);
        preorder(p->right);
        return;
    }
    return;
}

void inorder(struct tree_node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("%4d", p->data);
        inorder(p->right);
        return;
    }
    return;
}

void postorder(struct tree_node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%4d", p->data);
        return;
    }
    return;
}

static int count = 0;
int count_all(struct tree_node *root)
{
    if(root != NULL)
    {

        count_all(root->left);
        count++;
        count_all(root->right);
    }
    return count;
}

int count_leaf(struct tree_node *root)
{
    if(root != NULL)
    {
        count_leaf(root->left);
        if(root->left==NULL && root->right==NULL)
            count++;
        count_leaf(root->right);
    }
    return count;
}

int count_non_leaf(struct tree_node *root)
{
    if(root != NULL)
    {
        count_non_leaf(root->left);
        if(!(root->left==NULL && root->right==NULL))
            count++;
        count_non_leaf(root->right);
    }
    return count;
}

void main()
{
    int number = 0;
    int choice = 0;
    struct tree_node *root = NULL;
    while (choice != 9)
    {
        printf("\nEnter Your Choice!\n");
        printf("1: Insert\n");
        printf("2: Preorder Display\n");
        printf("3: Inorder Display\n");
        printf("4: Postorder Display\n");
        printf("5: Delete node\n");
        printf("6: No. of nodes\n");
        printf("7: No. of leaf nodes\n");
        printf("8: No. of non leaf nodes\n");
        printf("9: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Insert function is chosen\n");
            number = 0;
            printf("Enter data for the node ");
            scanf("%d", &number);
            root = insert(root, number);
            break;

        case 2:
            printf("Preorder Display function is chosen\n");
            if (root == NULL)
            {
                printf("Tree empty\n");
                break;
            }
            else
            {
                preorder(root);
                printf("\n");
                break;
            }

        case 3:
            printf("Inorder Display function is chosen\n");
            if (root == NULL)
            {
                printf("Tree empty\n");
                break;
            }
            else
            {
                inorder(root);
                printf("\n");
                break;
            }

        case 4:
            printf("Postorder Display function is chosen\n");
            if (root == NULL)
            {
                printf("Tree empty\n");
                break;
            }
            else
            {
                postorder(root);
                printf("\n");
                break;
            }

        case 5:
            printf("Delete Function is chosen\n");
            int x;
            printf("\nEnter a value to be deleted\n");
            scanf("%d", &x);
            if (root == NULL)
            {
                printf("\nTree is Empty\n");
                break;
            }
            else
            {
                root = delete (root, x);
                printf("%d was deleted successfully", x);
                break;
            }

        case 6:
            count=count_all(root);
            printf("%d",count);
            break;

        case 7:
             count=count_leaf(root);
            printf("%d",count);
            break;

        case 8:
            count=count_non_leaf(root);
            printf("%d",count);
            break;

        default:
            printf("Invalid option\n");
            break;
        }
        count=0;
    }
}


