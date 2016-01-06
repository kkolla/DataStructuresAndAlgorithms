#include "tree.h"
#include <limits.h>

Tree* insertBST(Tree *root, int data)
{
    if (root == NULL) return createTreeroot(data);
    if (data > root->data)  {
        root->right = insertBST(root->right, data);
    } else if (data < root->data) {
        root->left = insertBST(root->left, data);
    }
    return root;
}

Tree* createBST(int data[], int len)
{
    Tree *root = NULL;
    for(int i = 0; i < len; ++i)
    {
        root = insertBST(root, data[i]);
    }
    return root;
}

Tree* buildBst(int A[], int low, int high)
{
    /*
     * Works only if a sorted array
     */
    int mid = (low + high) / 2;
    if (low > high) return NULL;
    if (low == high) createTreeroot(A[low]);
    Tree *newNode = createTreeroot(A[mid]);
    newNode->left = buildBst(A, low, mid-1);
    newNode->right = buildBst(A, mid+1, high);
    return newNode;
}

Tree* BSTFind(Tree* root, int data) {
    if (root == NULL) {
        cout<<"Not Found"<<endl;
        return NULL;
    }

    if (data > root->data) return BSTFind(root->right, data);
    if (data < root->data) return BSTFind(root->left, data);
    cout<<"Found"<<endl;
    return root;
}
