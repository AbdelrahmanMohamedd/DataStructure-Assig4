#include "Inxbuldr.h"

using namespace std;


BSTNode<indexnode>* Search(BSTNode<indexnode>* root, BSTNode<indexnode>* key)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data.word == key->data.word)
    {
        return root;
    }
    else if(root->data.word > key->data.word)
    {
        return Search(root->left, key);
    }
    else
    {
        return Search(root->right, key);
    }
}

string IndexBuilder::removePunctuation(string text)
{
    string newtext = "";
    for ( int i = 0; i < text.size() - 1; ++i)
    {
        if (text[i] == ',' || text[i] == '.')
        {
            continue;
        }
        newtext += text[i];
    }
    return newtext;
}
vector<string> IndexBuilder::split(string text, string delim)
{
    vector<string> newtext;
    char* word;
    word = strtok(&text[0], &delim[0]);
    while(word != 0)
    {
        newtext.push_back(string(word));
        word = strtok(0, &delim[0]);
    }
    return newtext;
}
IndexBuilder::IndexBuilder(string text)
{
    text = removePunctuation(text);
    vector<string> lines = split(text, "\n");
    for (int li = 0; li < lines.size(); ++li)
    {
        vector<string> words = split(lines[li], " ");
        for (int wi = 0; wi < words.size(); ++wi)
        {
            BSTNode<indexnode> temp;
            cout << temp.data.word << endl;
            /*
            BSTNode<indexnode>* inode = Search(bst->root, *BSTNode(words[wi], vector<int>temp()));
            if (!inode)
            {
                bst.insert(BSTNode(words[wi], vector<  int>()));
                inode = Search(BSTNode(words[wi], vector<  int>()));
            }
            inode->lines.push_back(li + 1);
            */
        }
    }
}
void IndexBuilder::printIndex()
{
    bst->inOrder(bst);
}

/*
int main (){


string word="i am programmer ,i am domaa .mounir programmer ,";
IndexBuilder test = IndexBuilder(word) ;
test.printIndex();


return 0;
}
*/
