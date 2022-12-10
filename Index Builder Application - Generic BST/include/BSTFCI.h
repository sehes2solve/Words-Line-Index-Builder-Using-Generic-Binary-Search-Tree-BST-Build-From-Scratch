#ifndef BSTFCI_H
#define BSTFCI_H
#include <queue>
#include "Word.h"

template < class T >
class BSTFCI
{
    public:
        BSTFCI();
        void add(T);
        void cut(T);
        void flip();

        void breadth_print();
        void inorder_print();
        void preorder_print();
        void postorder_print();
        void printRange(T,T);

        bool isBalanced();
        bool isSubTree(BSTFCI<T>*,BSTFCI<T>*);

        T* search(T);
        int get_height();
        int size();


        void clear();
        virtual ~BSTFCI();

    protected:

    private:
        class BSTNode
        {
            public:
                BSTNode();
                BSTNode(T,BSTNode* = nullptr,BSTNode* = nullptr);
                T value;
                BSTNode *left,*right;
        };
        BSTNode *root;
        int sizz;

        void search(T,T,BSTNode**&);
        void delete_BSTNode(BSTNode*&);
        void flip(BSTNode*);
        bool isIdentical(BSTNode*,BSTNode*);
        int get_height(BSTNode*,int);
        int get_height(BSTNode*);

        void inorder_print(BSTNode*);
        void inorder_printRange(T,T,BSTNode*);
        void preorder_print(BSTNode*);
        void postorder_print(BSTNode*);
};

#endif // BSTFCI_H
