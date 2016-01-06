#include "bst.h"
Tree* findMax(Tree* root)
{
   if((root == NULL) || (root->right == NULL)) {
       return root;
   }
   return findMax(root->right);
}
Tree* LCA(Tree *root, int v1, int v2)
{
    if (root == NULL) return root;
    if ((v1 < root->data && v2 > root->data) || (v2 < root->data && v1 > root->data)) return root;
    if (v1 > root->data) return LCA(root->right, v1, v2);
    return LCA(root->left, v1, v2);
}
int isBST(Tree *root, int *prev)
{
    if (root == NULL) return 1;
    if (isBST(root->left, prev) == 0) return 0;
    if (*prev > root->data) return 0;
    *prev = root->data;
    if (isBST(root->right, prev) == 0) return 0;
    return 1;
}

int compare(Tree *r1, Tree *r2)
{
    if (r1 == NULL && r2 == NULL) return 1;
    if (r1 == NULL || r2 == NULL) return 0;
    if (r1->data != r2->data) return 0;
    return (compare(r1->left, r2->left) && compare(r1->right, r2->right));
}

void corrupt(Tree *root)
{
    while(root->right != NULL) root = root->right;
    root->right = new Tree();
}
Tree* KthSmallest_(Tree *root, int *cnt, int k)
{
    if (root == NULL) return NULL;
    Tree *temp = KthSmallest_(root->left, cnt, k);
    if (temp!= NULL) return temp;
    *cnt = (*cnt) + 1;
    if (*cnt == k) return root;
    return KthSmallest_(root->right, cnt, k);
}
Tree* KthSmallest(Tree *root, int k)
{
    int count = 0;
    return KthSmallest_(root, &count, k);
}
int main () {
    int data[] = { 42,12,61,1,23,15,7};
    int data1[] = {1,2,3,4,5,6,7};
    int min = INT_MIN;
    Tree *root = createBST(data, 7);
    Tree *root1 = buildBst(data1, 0, 6);
    Tree *temp;
    // BSTFind(root, 0);
    findMax(root)->showln();
    LCA(root,7,15)->showln();
    //corrupt(root);
    levelOrder(root);

    isBST(root, &min) ? std::cout << "BST" << std::endl : std::cout << "Not BST" << std::endl;
    compare(root, root1) ? cout<<"Same\n":cout<<"Not Same\n";
    KthSmallest(root, 4)->showln();
}
