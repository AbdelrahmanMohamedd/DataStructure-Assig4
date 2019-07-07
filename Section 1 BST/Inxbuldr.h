#ifndef INDEXBUILDER_H
#define INDEXBUILDER_H
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "BSTFCI.h"

using namespace std ;
struct indexnode
{
    string word ;
    vector <int> lines;
};
class IndexBuilder
{
private:
    BSTFCI<indexnode>* bst;
    string removePunctuation(string text);
    vector<string> split(string text, string delim);

public:
    IndexBuilder(string text);
    void printIndex();
};

#endif // INDEXBUILDER_H
