#include <iostream>
#include <queue>          // std::queue
#include <algorithm>    // std::max
#include <signal.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree *sibling;
    Tree();
    Tree(int val);
    void show();
    void showln();
};


Tree::Tree()
{
    data = 0;
    left = NULL;
    right = NULL;
    sibling = NULL;
}

Tree::Tree(int d)
{
    data = d;
    left = NULL;
    right = NULL;
    sibling = NULL;
}

Tree* createTreeroot()
{
    Tree *root = new Tree();
    return root;
}
void Tree::show()
{
    std::cout << data <<" ";
}
void Tree::showln()
{
    std::cout << data <<" \n";
}
Tree* createTreeroot(int data)
{
    Tree *root = new Tree(data);
    return root;
}

void postOrder_(Tree* root)
{
    if (root == NULL) {
        return;
    }
    postOrder_(root->left);
    postOrder_(root->right);
    root->show();
}
void postOrder(Tree* root)
{
    std::cout << "-PO-" << std::endl;
    postOrder_(root);
    std::cout << "\n=PO=" << std::endl << endl;
}

void inOrder_(Tree* root)
{
    if (root == NULL) {
        return;
    }
    inOrder_(root->left);
    root->show();
    inOrder_(root->right);
}
void inOrder(Tree* root)
{
    std::cout << "-IO-" << std::endl;
    inOrder_(root);
    std::cout << "\n=IO=" << std::endl << endl;
}

void preOrder_(Tree* root)
{
    if (root == NULL) {
        return;
    }
    root->show();
    preOrder_(root->left);
    preOrder_(root->right);
}
void preOrder(Tree* root)
{
    std::cout << "-IO-" << std::endl;
    preOrder_(root);
    std::cout << "\n=IO=" << std::endl << endl;
}
void levelOrder(Tree *root)
{
    std::cout << "-LO-" << std::endl;
    queue<Tree*> Q;
    Q.push(root);
    while (!Q.empty()) {
        root = Q.front();
        Q.pop();
        root->show();
        if (root->left != NULL)
        {
            Q.push(root->left);
        }
        if (root->right != NULL)
        {
            Q.push(root->right);
        }
    }
    std::cout << "\n=LO=" << std::endl << endl;
}
void VERIFY(int Value)
{
    if (Value <= 0) {
        raise(SIGABRT);
    }
}
void printArray(int* A, int count)
{
    for (int i = 0; i < count; i++) {
        cout << A[i];
    }
    cout<<endl;
}
