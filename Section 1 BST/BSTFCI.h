#ifndef BSTFCI_H
#define BSTFCI_H
#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode()
    {
        data=0;
        left=nullptr;
        right=nullptr;
    }
    BSTNode(T value)
    {
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

template <class T>
class BSTFCI
{
public:
    BSTNode<T>*root;
    BSTFCI()
    {
        root = 0;
    }
    virtual ~BSTFCI() {}

    void insert(T el)
    {
        //function to inserte node
        BSTNode<T>* p;
        BSTNode<T>* prev;
        p = root;
        prev = NULL;
        while (p != 0)
        {
            prev = p;
            if (p->data < el)
                p = p->right;
            else
                p = p->left;
        }
        if (root == 0)
        {
            root = new BSTNode<T>(el);
        }
        else if (prev->data < el)
        {
            prev->right = new BSTNode<T>(el);
        }
        else
        {
            prev->left = new BSTNode<T>(el);
        }
    }
    void inOrder(BSTNode<T>* treeNode)
    {
        if (treeNode == NULL)
            return;

        inOrder(treeNode->left);
        cout << treeNode->data << " ";
        inOrder(treeNode->right);
    }
    int  getHeight(BSTNode<T>* treeNode)
    {
        if (!treeNode)
            return 0;
        return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));

    }
    bool IsBalanced(BSTNode <T>*treeNode)
    {
        if (!treeNode)
        {
            return false;
        }
        int leftHeight = getHeight(treeNode->left);
        int rightHeight = getHeight(treeNode->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;
        return true;
    }
    bool AreIdentical(BSTNode<T>* root1, BSTNode<T>* root2)
    {
        /* base cases */
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        /* Check if the data of both roots is same and data of left and right subtrees are also same */
        return (root1->data == root2->data &&areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
    }
    bool IsSubtree(BSTNode<T>* t1, BSTNode<T>* t2)
    {
        if (t2 == NULL) // An empty subtree can always be found in any tree
            return true;
        if (t1 == NULL) // If no more tree is left to search, return false
            return false;
        // If there is a match, check the left and right nodes to match with
        // left and right subtrees
        if (t1->data == t2->data)
            return IsSubtree (t1->left, t2->left) && IsSubtree (t1->right, t2->right);
        // If there is no match, check left and right subtrees for a
        // match with current tree
        return IsSubtree (t1->left, t2) || IsSubtree (t1->right, t2);
    }
    void PrintRange(BSTNode<T>*root, T k1, T k2)
    {
        /*
        if ( root == nullptr)
            return;
        if (k1 < root->data)
            PrintRange(root->left, k1, k2);
        if (k1 <= root->data && k2 >= root->data)
            cout << root->data << " ";
        if (k2 > root->data)
            PrintRange(root->right, k1, k2);
        */
        if(root == NULL)
        {
            return;
        }
        if(root->data >= k1 && root->data <= k2)
        {
            cout << root->data << " ";
        }
        if(root->left != NULL)
        {
            if(root->left->data >= k1 && root->left->data <=k2)
            {
                PrintRange(root->left, k1, k2);
            }
        }
        if(root->right != NULL)
        {
            if(root->right->data <= k2 && root->right->data >=k1)
            {
                PrintRange(root->right, k1, k2);
            }
        }
    }
    void Flip(BSTNode<T>* node)
    {
        if (node == NULL)
            return;
        else
        {
            BSTNode<T>* temp;
            Flip(node->left);
            Flip(node->right);
            //swap the pointers in this node
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }
    void Flip()
    {
        Flip(root);
    }
};

#endif // BSTFCI_H
