#include <iostream>
#include "BSTFCI.h"
using namespace std;

int main()
{

    BSTFCI <int> mytree1 ;
    BSTFCI <int> mytree2;

    mytree1.insert(10);
    mytree1.insert(20);
    mytree1.insert(14);
    mytree1.insert(7);
    mytree1.insert(31);
    mytree1.insert(5);

    mytree2.insert(9);
    mytree2.insert(2);
    mytree2.insert(4);
    mytree2.insert(3);
    mytree2.insert(21);
    mytree2.insert(33);

    ///============================= Tree height
    int test;
    test = mytree1.getHeight(mytree1.root);
    cout << endl<<"The hight if the tree: "<< test << endl;
    cout << endl;

    ///============================= Balance 1
    cout<<"Is the tree balanced?"<<endl;
    if( mytree1.IsBalanced(mytree1.root)) cout<<"Yes, its Balanced"<<endl;
        else cout<<"NO, itsNOT Balanced"<<endl;
        cout << endl;

    ///============================= Tree Comparison  2
    if (mytree1.IsSubtree(mytree1.root , mytree2.root)) cout<<"Yes,its is a Subtree "<<endl;
        else cout<<"NO, its NOT Subtree"<<endl;
    cout << endl;

    ///============================= In Range  3
    cout<<"The data set that appears in the tree between the two numbers is..."<<endl;
    mytree2.PrintRange(mytree2.root,2,4);
    cout << endl<< endl;

    ///============================= Flipping 4
    cout<<"the tree in order has the following data : ";
    mytree2.inOrder(mytree2.root);
    cout << endl;
    mytree2.Flip();
    cout<<"the tree data after Flipping/Mirorring  : ";
    mytree2.inOrder(mytree2.root);
    cout << endl<< endl;


}
