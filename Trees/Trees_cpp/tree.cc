#include "BinaryTree.h"
typedef int Bool;
/*const Bool TRUE = 1;
const Bool FALSE = 0;*/

void fillSiblings(Tree *root) {
    queue<Tree*> Q;
    Tree *prev = NULL;
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }

    Q.push(root);
    while (!Q.empty()) {
        root = Q.front();
        Q.pop();
        if (prev != NULL) prev->sibling = root;
        if (root->left != NULL) Q.push(root->left);
        if (root->right != NULL) Q.push(root->right);
        prev = root;
    }
}
void siblingTraverse(Tree* root) {
    while (root != NULL) {
        root->show();
        root = root->sibling;
    }
    std::cout << std::endl;
}
int treeSize(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    return (treeSize(root->left) + treeSize(root->right) + 1);
}
int treeHeight(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    return (max(treeHeight(root->left), treeHeight(root->right)) + 1);
}
int treeHeightNonRecursive(Tree *root) {
    int size = 0;
    queue<Tree*> Q;
    if (root == NULL) {
        return 0;
    }
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty()) {
        root = Q.front();
        Q.pop();
        if (root == NULL) {
            size++;
            if (Q.empty()) {
                return size;
            } else {
                Q.push(NULL);
            }
        } else {
            if (root->left != NULL) Q.push(root->left);
            if (root->right != NULL) Q.push(root->right);
        }

    }
    return size;
}
void printPaths(Tree *root, int *path, int len) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        path[len++] = root->data;
        printArray(path, len);
        return;
    }
    path[len++] = root->data;
    printPaths(root->left, path, len);
    printPaths(root->right, path, len);
}
int hasPathSum_(Tree *root, int sum) {
    if (root == NULL) {
        return (sum == 0);
    }

    sum -= root->data;

    return ((sum == 0) || hasPathSum_(root->left, sum) || hasPathSum_(root->right, sum));
}
void hasPathSum(Tree *root, int data) {
    hasPathSum_(root, data) ? cout << "Path sum " << data << " Present."<< endl : cout << "Path sum " << data << " Absent."<< endl;
}
void Mirrorize(Tree *root){
    Tree* temp;
    if (root == NULL) return;
    Mirrorize(root->left);
    Mirrorize(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int isMirror(Tree *p, Tree *q){
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;
    if (p->data != q-> data) return 0;
    return (isMirror(p->left, q->right) && isMirror(p->right, q->left));

}
int diameter(Tree *root){
    if (root == NULL) return 0;
    return max((treeHeight(root->left)+treeHeight(root->right)+1), max(diameter(root->left), diameter(root->right)));
}

Tree* buildTree(int inOrder[], int inStart, int inEnd, int preOrder[], int *preIndex, int preLen){
    if ((*preIndex >= preLen) || (inStart > inEnd)) return NULL;
    if (inStart == inEnd) return createTreeroot(inOrder[inStart]);
    int data = preOrder[*preIndex];
    Tree *root = createTreeroot(data);
    int inIndex = search(inOrder, inStart, inEnd, data);
    if (inIndex == -1) {
        std::cout << "data:" <<data<<" start:"<<inStart<<" end:"<<inEnd<< std::endl;
        return NULL;
    }
    *preIndex = (*preIndex) + 1;
    root->left = buildTree(inOrder, inStart, inIndex-1, preOrder, preIndex, preLen);
    *preIndex = (*preIndex) + 1;
    root->right = buildTree(inOrder, inIndex+1, inEnd, preOrder, preIndex, preLen);
    return root;
}
void TreeBuildTest() {
    int *preIndex = new int(0);
    int inOrder[] = {4,2,5,1,6,3,7};
    int preOrder[] = {1,2,4,5,3,6,7};
    levelOrder(buildTree(inOrder, 0, 6, preOrder, preIndex, 7));
}
int printAncestors(int data, Tree* root)
{
    if (root == NULL) return 0;
    if (root->data == data || printAncestors(data, root->left) || printAncestors(data, root->right)) { printf("%d\n", root->data);return 1; }
    return 0;
}
int main () {
    TreeBuildTest();
    int data[] = { 1,2,3,4,5,6,7};
    Tree *root = createTree(data, 7);
    levelOrder(root);
    printAncestors(7,root);
    /*int *array = new int[5];
    Tree *root1 = createTree(data, 7);
    levelOrder(root);
    fillSiblings(root);
    std::cout << "TreeSize is " << treeSize(root)<<endl;
    std::cout << "TreeHeight is " << treeHeight(root)<<endl;
    std::cout << "TreeHeight is " << treeHeightNonRecursive(root)<<endl;
    fillSiblings(root);
    siblingTraverse(root);
    printPaths(root, array, 0);
    hasPathSum(root, 3);
    VERIFY(treeHeight(root) == treeHeightNonRecursive(root1));
    levelOrder(root);
    Mirrorize(root);
    levelOrder(root);
    isMirror(root, root1) ? std::cout << "Trees are Mirrors\n" : std::cout << "Trees are not MIrrors" << std::endl;
    std::cout << "Diameter of Tree is " << diameter(root)<<endl;*/

    //delete(array);
}
