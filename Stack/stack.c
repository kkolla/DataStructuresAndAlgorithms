#include "stack.h"
int main(int argc, char *argv[]) {
    int option, value;
    stack *S;
    while (TRUE) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. View\n");
        printf("4. Create\n");
        printf("5. Destroy\n");
        printf("6. Clear\n");
        scanf("%d",&option);
        switch (option) {
            case 1: if (stackInit == 0)
                    {
                        printf("Please Create Stack First\n");
                        break;
                    }
                    printf("Enter value to Push: ");
                    scanf("%d",&value);
                    push(S, value);
                    break;
            case 2: if (stackInit == 0)
                    {
                        printf("Please Create Stack First\n");
                        break;
                    }
                    printf("Value %d Popped from stack\n", pop(S));
                    break;
            case 3: if (stackInit == 0)
                    {
                        printf("Please Create Stack First\n");
                        break;
                    }
                    printf("Display\n");
                    for (int i = S->top; i >=0; i--)
                    {
                        printf("%d ",S->a[i]);
                    }
                    printf("\n\n");
                    break;
            case 4: if (stackInit == 1)
                    {
                        printf("Stack already created\n");
                        break;
                    }
                    printf("Enter capacity of stack: ");
                    scanf("%d",&value);
                    S = createStack(value);
                    break;
            case 5: removeStack(S);
                    break;
            case 6: system("clear");
                    break;
            default: break;
        }
    }
    return 0;
}
