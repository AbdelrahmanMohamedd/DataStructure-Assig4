#ifndef TREAP_H_
#define TREAP_H_
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;
		V value;
		int priority;

		Node(T k, V v)
		{
		    this->left = this->right = nullptr;
		    value = v;
		    key = k;
		    priority = rand()%100;
		}
		/*
		friend ostream& operator<<(ostream &o, Treap<T, V>::Node root)
		{
		    cout << root.key << " ";
		    return o;
		}
		*/
	};
private:
	Node* root;
    void printInorder(Node *currentNode){
            if(currentNode == NULL)
            return;

            printInorder(currentNode->left);
            cout << *currentNode;
            printInorder(currentNode->right);
    }
	void rotateRight(Node* &root)
	{
	    Node* L = root->left;
        Node* Y = root->left->right;

        // rotate
        L->right = root;
        root->left = Y;

        // set new root
        root = L;
	}
	void rotateLeft(Node* &root)
	{
	    Node* R = root->right;
        Node* X = root->right->left;

        // rotate
        R->left = root;
        root->right = X;

        root = R;
	}

	void balance(Node* &root)
	{
	    if (root->right != nullptr && root->right->priority > root->priority)
			rotateLeft(root);
        if (root->left != nullptr && root->left->priority > root->priority)
			rotateRight(root);
	}
	void insert(Node* &root, T k, V v)
	{
	    if (root == nullptr)
        {
		root = new Node(k , v);
		return;
        }
        if (k < root->key)
        {
            insert(root->left, k , v);
            balance(root);
        }
        else
        {
            insert(root->right, k , v);
            balance(root);
        }
	}
	V find(Node* root, T k)
	{
	    if (root == nullptr)
            return nullptr;

        // if key is found
        if (root->key == k)
            return root->value;

        // if given key is less than the root node, search in the left subtree
        if (k < root->key)
            return find(root->left, k);

        // else search in the right subtree
        return find(root->right, k);
	}
public:
	Treap(){root = nullptr;}
	Node* getRoot(){return root;}
	void insert(T k, V v)
	{
	    insert(root , k , v);
	}
	V find(T k)
	{
	    return find(root  , k);
	}
	friend ostream& operator<<(ostream &o, Treap<T, V> tree)
	{
        tree.printInorder(tree.getRoot());
	    return o;
	}
};

#endif /* TREAP_H_ */
