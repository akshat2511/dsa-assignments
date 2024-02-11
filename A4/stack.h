

struct Node
{
    char name[100];
    int age;
    int id;
    int salary;
    struct Node *next;
};

void push(struct Node **head_ref, int id, char name[], int age, int salary)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->id = id;
    new_node->salary = salary;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pop(struct Node **p)
{

    struct Node *temp = *p;
    printf("\n");

    free(temp);
    printf("\n");

    *p = (*p)->next;
}

void peek(struct Node *a)
{
    printf("NAME\tAGE\tID\tSALARY\n");
    printf("%s\t", a->name);
    printf("%d\t", a->age);
    printf("%d\t", a->id);
    printf("%d\n", a->salary);
}

void display(struct Node *p)
{
    printf("NAME\tAGE\tID\tSALARY\n");
    while (p!= NULL )
    {
        printf("%s\t", p->name);
        printf("%d\t", p->age);
        printf("%d\t", p->id);
        printf("%d\n", p->salary);
        p = p->next;
    }
}
void isempty(struct Node *p)
{
    if (p == NULL)
        printf("empty");
    else
        printf("not empty");
}