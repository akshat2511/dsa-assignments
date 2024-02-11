
struct node
{
    char name[100];
    struct node *a[3];
} *root;
struct node *createfunc(struct node *p)
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be stored:");
    scanf("%s", p->name);
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            printf("------------------------------LEFT NODE OF %s--------------------\n", p->name);
        if (i == 1)
            printf("-------------------------------MID NODE OF %s----------------------\n", p->name);
        if (i == 2)
            printf("------------------------------RIGHT NODE OF %s----------------------\n", p->name);

        struct node *t;
        int check;
        printf("DO YOU WANT TO ENTER NODE ? Y=1 :");
        scanf("%d", &check);
        if (check == 1)
            p->a[i] = createfunc(t);
        else
            p->a[i] = NULL;
        continue;
    }
    return p;
}
struct node *preorder(struct node *p)
{
    if (p != NULL)
    {
        puts(p->name);
        for (int i = 0; i < 3; i++)
        {
            preorder(p->a[i]);
        }
    }
}
void search(struct node *root, char a[], int *c)
{
    if (root == 0)
        return;
    if (strcmp(root->name, a) == 0)
    {
        *c = *c + 1;
        printf("found\n");
    }
    search(root->a[0], a, c);
    search(root->a[1], a, c);
    search(root->a[2], a, c);
}


struct node *inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->a[0]);
        puts(p->name);
        inorder(p->a[1]);
        inorder(p->a[2]);
    }
}
struct node *postorder(struct node *p)
{
    if (p != NULL)
    {

        for (int i = 0; i < 3; i++)
        {
            postorder(p->a[i]);
        }
        puts(p->name);
    }
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int depth(struct node *root)
{
    if (root == NULL)
        return 0;
    int left = depth(root->a[0]);
    int center = depth(root->a[1]);
    int right = depth(root->a[2]);
    int a = max(left, center);
    int b = max(a, right);
    return b + 1;
}
void menu(){
    printf("ENTER 0 TO EXIT THE PROGRAM\nENTER 1 FOR CREATION OF A TREE\nENTER 2 FOR PREORDER\nENTER 3 FOR INORDER\nENTER 4 FOR POSTORDER\nENTER 5 FOR SEARCHING IN A TREE\nENTER 6 FOR DEPTH\nENTER 7 FOR MENU\n ");
}


