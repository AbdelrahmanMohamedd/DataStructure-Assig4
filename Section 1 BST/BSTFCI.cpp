#include <iostream>
#include "BSTFCI.h"
using namespace std;


template <typename T>
BSTFCI<T>::BSTFCI()      /// BSTFCI constructor
{
    root = 0;
}
///====================================================
template <class T>
void BSTFCI<T>:: insert(T el)
        {                             //function to inserte node
		BSTNode<T>* p;
		BSTNode<T> prev;
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
		if (root == 0) {
			root = new BSTNode<T>(el);
		}
		else if (prev->data < el) {
			prev->right = new BSTNode<T>(el);
		}
		else {
			prev->left = new BSTNode<T>(el);
		}
	}
///====================================================
template <class T>
void BSTFCI<T>:: inOrder(BSTNode<T>* treeNode)
	{
		if (treeNode == NULL)
			return;

		inOrder(treeNode->left);
		cout << treeNode->data << " ";
		inOrder(treeNode->right);
	}
///====================================================
template <class T>
int BSTFCI<T>:: getHeight(BSTNode<T>* treeNode) {
		if (!treeNode)
			return 0;
		return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));

	}
///====================================================
template <class T>
bool BSTFCI<T>:: IsBalanced(BSTNode<T>* treeNode)
{
		if (!treeNode) {
			return false;
		}
		int leftHeight = getHeight(treeNode->left);
		int rightHeight = getHeight(treeNode->right);

		if (abs(leftHeight - rightHeight) > 1)
			return false;
		return true;
}
///====================================================
template <class T>
void BSTFCI<T>:: PrintRange(BSTNode<T>*root, T k1, T k2) {
		if ( root == nullptr)
			return;
		if (k1 < root->data)
			printRange(root->left, k1, k2);
		if (k1 <= root->data && k2 >= root->data)
			cout << root->data << " ";
		if (k2 > root->data)
			printRange(root->right, k1, k2);
}
///====================================================
template <class T>
bool BSTFCI<T>::AreIdentical(BSTNode<T>* root1, BSTNode<T>* root2)    //function to check	whether trees with roots as root1and root2 are identical or not
	{
		/* base cases */
		if (root1 == NULL && root2 == NULL)
			return true;
		if (root1 == NULL || root2 == NULL)
			return false;
		/* Check if the data of both roots is same and data of left and right subtrees are also same */
		return (root1->data == root2->data &&areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right));
	}
///====================================================
template <class T>
bool BSTFCI<T>::IsSubtree(BSTNode<T>* t1, BSTNode<T>* t2)
	{
		if (t2 == NULL) // An empty subtree can always be found in any tree
			return true;
		if (t1 == NULL) // If no more tree is left to search, return false
			return false;
		// If there is a match, check the left and right nodes to match with
		// left and right subtrees
		if (t1->data == t2->data)
			return isSubtree(t1->left, t2->left) && isSubtree(t1->right, t2->right);
		// If there is no match, check left and right subtrees for a
		// match with current tree
		return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
	}
///====================================================
template <class T>
void BSTFCI<T>::Flip(BSTNode<T>* node) {
		if (node == NULL)
			return;
		else {
			BSTNode<T>* temp;
			flip(node->left);
			flip(node->right);
			//swap the pointers in this node
			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	}
	template<class T>
	void BSTFCI<T>::Flip()
	{
	    Flip(root);
	}
///====================================================
