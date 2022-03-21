

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;
struct Node
{
    int value;
    map<char, Node *> m;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;

    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    Node *root = new Node();
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        Node *temp = root;

        for (int j = 0; j < s[i].length(); j++)
        {
            string word = s[i];
            if (temp->m.count(word[j]))
            {
                temp = temp->m[word[j]];
                counter += temp->value;
            }
            else
            {
                Node *newNode = new Node();
                temp->m[word[j]] = newNode;
                temp = newNode;
            }
        }
        temp->value = 1;
    }
    cout << counter << endl;
}