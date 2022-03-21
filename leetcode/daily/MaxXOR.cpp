
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <bitset>

#define DBG(x) cerr < < #x < < " = " < (x) < < endl
#define RAYA cerr << "=============================" << endl

// LLenar el código de assert(booleano) Se incluye con #include <cassert>
// Usar debugger para saber línea del runtime error(operacion infinita)
using namespace std;

struct Trie
{
    Trie *children[2];
    Trie()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    };
};
Trie *rootNode;
void insert(int x)
{
    Trie *temp = rootNode;
    bitset<32> bs(x);
    for (int i = 31; i >= 0; i--)
    {
        if (!temp->children[bs[i]])
            temp->children[bs[i]] = new Trie();
        temp = temp->children[bs[i]];
    }
}

int getMax(int n)
{
    int ans = 0;
    Trie *temp = rootNode;
    bitset<32> bs(n);
    for (int i = 31; i >= 0; i--)
    {
        if (temp->children[!bs[i]])
            ans += 1 << i, temp = temp->children[!bs[i]];
        else
            temp = temp->children[bs[i]];
    }
    return ans;
};
int findMaximumXOR(vector<int> &nums)
{
    rootNode = new Trie();
    for (int i = 0; i < nums.size(); i++)
        insert(nums[i]);
    int mx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mx = max(mx, getMax(nums[i]));
    }
    return mx;
};

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = findMaximumXOR(v);
    cout << ans << "\n";
}
