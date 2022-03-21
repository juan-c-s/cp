
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int a = 0, b = 0, cont = 0, residuo = 0;
    ListNode *temp2 = l2, *finalAns = new ListNode(), *ans = finalAns, *temp = l1;
    bool fin1 = false, fin2 = false;
    while (temp != nullptr || temp2 != nullptr)
    {
        int value = 0;
        if (temp != nullptr)
        {
            value += temp->val;
            temp = temp->next;
        }
        else
            fin1 = true;
        if (temp2 != nullptr)
        {
            value += temp2->val;
            temp2 = temp2->next;
        }
        else
            fin2 = true;
        if (value + residuo > 9)
        {
            ans->val = (value + residuo) % 10;
            residuo = 1;
        }
        else
        {
            ans->val = value + residuo;
            residuo = 0;
        }
        if (!((fin1 && temp2 == nullptr) || (fin2 && temp == nullptr) || (!fin1 && !fin2 && temp2 == nullptr && temp == nullptr)))
        {
            ans->next = new ListNode();
            ans = ans->next;
        }
    }
    if (residuo == 1)
        ans->next = new ListNode(1);
    return finalAns;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(9);
    ListNode *ans = addTwoNumbers(l1, l2);
    for (ListNode *temp = ans; temp != nullptr; temp = temp->next)
    {
        cout << temp->val;
    }
    cout << "\n";
}