#include "tree.h"

void inOrder_(tree *root)
{
    if (root == NULL) return;
    inOrder_(root->left);
    printf("%d ", root->data);
    inOrder_(root->right);
}
void inOrder(tree *root) {
    inOrder_(root);
    printf("\n");
}

void inOrderNonRecursive(stack *S, tree *root)
{
    while(TRUE)
    {
        while(root != NULL)
        {
            push(S, root);
            root = root->left;
        }
        if (isEmpty(S)) break;
        root = pop(S);
        printf("%d ", root->data);
        root = root->right;
    }
}
int main() {
    stack *S = createStack(10);
    // printArray(input, argc-1);
    tree* root = makeTree(input, argc-1);
    inOrderNonRecursive(S, root);
    showTreeStack(S);
    shutDown(S, root, input);
	return 0;
}
/*
int main(int argc, char *argv[]) {
    int *input = processArguments(argc, argv);
    stack *S = createStack(10);
    // printArray(input, argc-1);
    tree* root = makeTree(input, argc-1);
    inOrderNonRecursive(S, root);
    showTreeStack(S);
    shutDown(S, root, input);
	return 0;
}*/
