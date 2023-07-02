#include <stdio.h>
#include <iostream>
#include <queue>
typedef struct _tree{
    char data;
    struct _tree *left;
    struct _tree *right;
} tree;
void preorder(tree* t);
void inorder(tree* t);
void postorder(tree* t);
tree *makingTree(char b);
tree *searchingTree(tree *t, char s);
int main() {
	int a;
    tree *main;  // memo : Always root node "A"
    std::cin >> a;
    main = makingTree('A');   //init Tree
    for(int i = 0; i < a; i++)
    {
        char b, c, d;
        std::cin >> b >> c >> d;
        getchar(); //compiler problem;;;
        tree *t = searchingTree(main, b);
        if(c != '.')
            t->left = makingTree(c);
        if(d != '.')
            t->right = makingTree(d);
    }   //input
    preorder(main);
    printf("\n");
    inorder(main);
    printf("\n");
    postorder(main);
	return 0;
}

tree *makingTree(char b)
{
    tree *t = (tree*)malloc(sizeof(tree));
    t->data = b;
    t->left = NULL;
    t->right = NULL;
    return t;
}

tree *searchingTree(tree *t, char s)
{
    if(t == NULL)
        return NULL;
    if(t->data == s)
    {
        return t;
    }
    else
    {
        tree *t1 = searchingTree(t->left, s);
        if(t1 != NULL)
        {
            return t1;
        }
        else
        {
            t1 = searchingTree(t->right, s);
            if(t1 != NULL)
            {
                return t1;
            }
        }
    }
    return NULL;
}

void preorder(tree *t)
{
    if(t == NULL)
    {
        return;
    }
    printf("%c", t->data);
    preorder(t->left);
    preorder(t->right);
}


void inorder(tree *t)
{
    if(t == NULL)
    {
        return;
    }
    inorder(t->left);
    printf("%c", t->data);
    inorder(t->right);
}


void postorder(tree *t)
{
    if(t == NULL)
    {
        return;
    }
    postorder(t->left);
    postorder(t->right);
    printf("%c", t->data);
}

