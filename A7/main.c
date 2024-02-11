#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q1.h"
int main()
{
char n[100];
    int choice;
    menu();
    while (1)
    {
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            root = createfunc(root);
            break;
        }
        case 2:
        {
            preorder(root);
            break;
        }
        case 3:
        {
            inorder(root);
            break;
        }
        case 4:
        {
            postorder(root);
            break;
        }
        case 5:
        {int k = 0;
            char a[100];
            printf("enter elements to be searched\n");
            scanf("%s", a);
            search(root, a, &k);
            if (k == 0)
                printf("not found\n");
            break;

        }
         case 6:{
            printf("%d\n", depth(root));
            break;


        }
        case 7:{ menu();
        break;
        }
        }
        if(choice==0){printf("PROGRAM WAS TERMINATED SUCCESSFULLY............................................");break;
    }}
}