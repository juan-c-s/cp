

#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <unordered_map>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

struct Trie
{
    Trie()
    {
        this->a = NULL;
        this->b = NULL;
        this->level = 0;
        this->lett = "";
        this->used = true;
    }
    Trie(bool use, int level, string lett)
    {

        this->used = use;
        this->a = NULL;
        this->b = NULL;
        this->level = level;
        this->lett = lett;
    }
    bool used;
    string lett;
    int level;

    Trie *a, *b;
};
void fillTrie(Trie *root)
{
    cout << root->lett << " ";
    if (root->level == 4)
    {
        return;
    }
    root->a = new Trie(false, root->level + 1, "a");
    root->b = new Trie(false, root->level + 1, "b");
    fillTrie(root->a);

    fillTrie(root->b);
}
string findWord(Trie *root)
{
    cout << root->lett << endl;
    if (root->level == 4)
    {
        return root->lett;
    }
    if (root->a != NULL && !(root->a->used))
    {
        return root->lett + findWord(root->a);
    }
    else if (root->a != NULL && !(root->b->used))
    {
    }
    else
        return root->lett;
};
int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    string word;

    Trie *root = new Trie();

    fillTrie(root);
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        Trie *temp = root;
        for (int j = 0; j < 4; j++)
        {
            if (word[j] == 'a')
            {
                temp->a->used = true;
                cout << temp->a->lett;
                if (temp->a != NULL)
                    temp = temp->a;
            }
            else
            {
                temp->b->used = true;
                if (temp->b != NULL)
                    temp = temp->b;
                cout << temp->b->lett;
            }
        }
    }

    cout << findWord(root) << endl;
}