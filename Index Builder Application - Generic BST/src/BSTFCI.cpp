#include "../include/BSTFCI.h"

template < class T >
BSTFCI<T>::BSTFCI()
{
    root = nullptr;
    sizz = 0;
}


template < class T >
void BSTFCI<T>::flip(BSTNode* node)///inorder depth flip will cause no change so use postorder or preorder
{
    if(node != nullptr)
    {
        flip(node->left);
        flip(node->right);
        swap(node->left,node->right);
    }
}
template < class T >
void BSTFCI<T>::flip()
{
    flip(root);
}
template < class T >
void BSTFCI<T>::search(T low,T high,BSTNode** &ptrTOnode_ptr)///*ptrTOnode_ptr same as pointer to node
{
    ptrTOnode_ptr = &root;
    while(*ptrTOnode_ptr != nullptr)
    {
        if((*ptrTOnode_ptr)->value >= low && (*ptrTOnode_ptr)->value <= high)
            return;
        else if((*ptrTOnode_ptr)->value > high)
            ptrTOnode_ptr = &(*ptrTOnode_ptr)->left;
        else
            ptrTOnode_ptr = &(*ptrTOnode_ptr)->right;
    }
}
template < class T >
T* BSTFCI<T>::search(T value)
{
    BSTNode** ptrTOnode_ptr;
    search(value,value,ptrTOnode_ptr);
    if(*ptrTOnode_ptr != nullptr)
        return &((*ptrTOnode_ptr)->value);
    return (T*)(*ptrTOnode_ptr);
}


template < class T >
void BSTFCI<T>::add(T value)
{
    BSTNode *node = root, *prev_node = root;
    while(node != nullptr)
    {
        if(node->value == value)
        {
            /*prev_node = node->left;
            node->left = new BSTNode(value,prev_node);*/
            node->value = value;
            return;
        }
        else if(node->value > value)
        {
            prev_node = node;
            node = node->left;
        }
        else
        {
            prev_node = node;
            node = node->right;
        }
    }
    if(prev_node == nullptr)///node == root,prev_node == node,sizz == 0
        root = new BSTNode(value);
    else if(prev_node->value > value)
        prev_node->left = new BSTNode(value);
    else
        prev_node->right = new BSTNode(value);
    sizz++;
}
template < class T >
void BSTFCI<T>::delete_BSTNode(BSTNode*& node)
{
    BSTNode* nodeTodelete = node;
    if(node->left == nullptr)
        node = node->right;
    else if(node->right == nullptr)
        node = node->left;
    else
    {
        BSTNode* prev_node = nodeTodelete;
        nodeTodelete = nodeTodelete->left;
        while(nodeTodelete->right!= nullptr)
        {
            prev_node = nodeTodelete;
            nodeTodelete = nodeTodelete->right;
        }
        node->value = nodeTodelete->value;
        if(node != prev_node)
            prev_node->right = nodeTodelete->left;
        else
            prev_node->left = nodeTodelete->left;
    }
    delete nodeTodelete;
    sizz--;
}
template < class T >
void BSTFCI<T>::cut(T value)
{
    BSTNode** ptrTOnode_ptr;
    search(value,value,ptrTOnode_ptr);
    if((*ptrTOnode_ptr) == nullptr)
        cout << "Node of value (" << value << ") Not found!!!" << endl;
    else
        delete_BSTNode(*ptrTOnode_ptr);
}
template < class T >
void BSTFCI<T>::clear()
{
    BSTNode* node = root;
    if(node != nullptr)
    {
        vector<BSTNode*> nodes;
        nodes.push_back(node);
        for(unsigned int i = 0; i < nodes.size();i++)
        {
            node = nodes[i];
            if(node->left != nullptr)
                nodes.push_back(node->left);
            if(node->right != nullptr)
                nodes.push_back(node->right);
        }
        for(unsigned int i = 0;i < nodes.size();i++)
            delete nodes[i];
        root = nullptr;
        sizz = 0;
    }
    else
        cout << "Tree is empty!!!" << endl;
}


template < class T >
int BSTFCI<T>::get_height(BSTNode* node,int height)
{
    if(node != nullptr)
    {
        height++;
        return max(get_height(node->left,height),get_height(node->right,height));
    }
    return height;
}
template < class T >
int BSTFCI<T>::get_height(BSTNode* node)
{
    int height = 0;
    return get_height(node,height);
}
template < class T >
int BSTFCI<T>::get_height()
{
    return get_height(root);
}
template < class T >
int BSTFCI<T>::size()
{
    return sizz;
}


template < class T >
bool BSTFCI<T>::isBalanced()
{
    BSTNode* node = root;
    if(node != nullptr)
    {
        queue<BSTNode*> nodes;
        nodes.push(node);
        int height_diff;
        while(!nodes.empty())
        {
            node = nodes.front();
            height_diff = get_height(node->right) - get_height(node->left);
            nodes.pop();
            if(height_diff > 1 || height_diff < -1)
                return false;
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
        }
    }
    return true;
}
template < class T >
bool BSTFCI<T>::isIdentical(BSTNode* t1N,BSTNode* t2N)
{
    if(t1N != nullptr && t2N != nullptr)
    {
        if(t1N->value != t2N-> value)
            return false;
        return isIdentical(t1N->left,t2N->left) && isIdentical(t1N->right,t2N->right);
    }
    else
    {
        if(t1N == nullptr && t2N == nullptr)
            return true;
        return false;
    }
}
template < class T >
bool BSTFCI<T>::isSubTree(BSTFCI<T>* t1,BSTFCI<T>* t2)
{
    BSTNode* node = t1->root;
    int t2_height = get_height(t2->root);
    queue<BSTNode*> nodes;
    nodes.push(node);
    while(!nodes.empty())
    {
        node = nodes.front();
        nodes.pop();
        if(t2_height > get_height(node))
            continue;
        if(isIdentical(node,t2->root))
            return true;
        if(node->left != nullptr)
            nodes.push(node->left);
        if(node->right != nullptr)
            nodes.push(node->right);
    }
    return false;
}


template < class T >
void BSTFCI<T>::breadth_print()
{
    BSTNode* node = root;
    if(node != nullptr)
    {
        queue<BSTNode*> nodes;
        nodes.push(node);
        while(!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            cout << node->value << " ";
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
        }
        cout << endl;
    }
    else
        cout << "Tree is empty!!!" << endl;
}
template < class T >
void BSTFCI<T>::inorder_printRange(T low,T high,BSTNode* node)
{
    if(node == nullptr || node ->value < low || node->value > high)
        return;
    else
    {
        inorder_printRange(low,high,node->left);
        cout << node->value << " ";
        inorder_printRange(low,high,node->right);
    }
}
template < class T >
void BSTFCI<T>::inorder_print(BSTNode* node)
{
    if(node != nullptr)
    {
        inorder_print(node->left);
        cout << node->value << " ";
        inorder_print(node->right);
    }
}
template < class T >
void BSTFCI<T>::inorder_print()
{
    inorder_print(root);
    cout << endl;
}
template < class T >
void BSTFCI<T>::preorder_print(BSTNode* node)
{
    if(node != nullptr)
    {
        cout << node->value << " ";
        preorder_print(node->left);
        preorder_print(node->right);
    }
}
template < class T >
void BSTFCI<T>::preorder_print()
{
    preorder_print(root);
    cout << endl;
}
template < class T >
void BSTFCI<T>::postorder_print(BSTNode* node)
{
    if(node != nullptr)
    {
        postorder_print(node->left);
        postorder_print(node->right);
        cout << node->value << " ";
    }
}
template < class T >
void BSTFCI<T>::postorder_print()
{
    postorder_print(root);
    cout << endl;
}
template < class T >
void BSTFCI<T>::printRange(T low,T high)
{
    if(low > high)
        swap(low,high);
    BSTNode** ptrTOnode_ptr;
    search(low,high,ptrTOnode_ptr);
    BSTNode* node = *ptrTOnode_ptr;
    cout << '[';
    inorder_printRange(low,high,node);
    cout << "]\n";
}


template < class T >
BSTFCI<T>::~BSTFCI()
{
    clear();
}


template < class T >
BSTFCI<T>::BSTNode::BSTNode()
{
    left = nullptr;right = nullptr;
}
template < class T >
BSTFCI<T>::BSTNode::BSTNode(T v,BSTNode* l,BSTNode* r)
{
    value = v;left = l;right = r;
}


template class BSTFCI < int                     >;
template class BSTFCI < long int                >;
template class BSTFCI < short int               >;
template class BSTFCI < unsigned int            >;
template class BSTFCI < long long int           >;
template class BSTFCI < unsigned long int       >;
template class BSTFCI < unsigned short int      >;
template class BSTFCI < unsigned long long int  >;

template class BSTFCI < char        >;
template class BSTFCI < Word        >;
template class BSTFCI < float       >;
template class BSTFCI < double      >;
template class BSTFCI < string      >;
template class BSTFCI < long double >;
