#include "tree.h"
void insertIntoTree(Tree *root, int data)
{
    queue<Tree*> Q;
    Tree* node = root;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (node->left != NULL)
        {
            Q.push(node->left);
        } else {
            node->left = createTreeroot(data);
            return;
        }

        if (node->right != NULL)
        {
            Q.push(node->right);
        } else {
            node->right = createTreeroot(data);
            return;
        }
    }
}

Tree* createTree(int data[], int len)
{
    Tree *root = createTreeroot(data[0]);
    for(int i = 1; i < len; ++i)
    {
        insertIntoTree(root, data[i]);
    }
    return root;
}
int search(int array[], int start, int end, int data) {
    for (int i = start; i <= end; i++) {
        if (array[i] == data) return i;
    }
    return -1;
}
