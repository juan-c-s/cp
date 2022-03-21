

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string.h>
#include <math.h>
#include <set>

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
typedef pair<ll, ll> ii;
typedef pair<pair<ll, ll>, ll> iii;
typedef pair<double, double> dd;

typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int inf = 1e9;
const int nax = 1e5 + 200;
// const ld pi = acos(-1);
const ld eps = 1e-9;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
#define MAX

#define MIN 1900
const int MOD = 1e9 + 7;
const ll INF = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin, str))
    {
        if (str.empty())
            break;
        stringstream ss(str);
        string ls,
            ns, ws;
        ss >> ns >> ls >> ws;
        int l = stoi(ls), n = stoi(ns), w = stoi(ws);

        vector<dd> v(n);
        map<double, set<double> > um;
        forn(i, n)
        {
            double pos, rad;
            cin >> pos >> rad;
            double resta = pow(rad, 2.0) - pow(w / 2.0, 2.0);
            if (resta < 0)
                continue;
            // DBG(pow(rad, 2.0) - pow(w / 2.0, 2.0));
            double dx = sqrt(resta);

            // DBG(dx);
            if ((pos - dx < 0) && (pos + dx > l))
            {
                v[i] = make_pair(0, l);
                um[0].insert(-1 * (l));
            }
            else if (pos - dx < 0)
            {
                v[i] = make_pair(0, pos + dx);
                um[0].insert(-1 * (pos + dx));
            }
            else if (pos + dx > l)
            {
                v[i] = make_pair(pos - dx, l);
                um[pos - dx].insert(-1 * l);
            }
            else
            {
                v[i] = make_pair(pos - dx, pos + dx);
                um[pos - dx].insert(-1 * (pos + dx));
            }
        }
        // forn(i, n)
        // {
        //     cout << i << ": " << v[i].fi << " " << v[i].se << "\n";
        // }
        map<double, set<double> >::iterator it = um.begin();
        // MAP para que ordene por coordenadas
        // set para que siempre tenga el mayor en la posición 1(la verdad literalmente simulé un priority queue noc pq)
        double corte = -1 * *it->second.begin();
        double maxExtension = corte;
        int count = 1;
        it++;
        for (; it != um.end(); it++)
        {
            //-1 * m->second.begin() = mayorNumero
            double curr = it->first;
            if (curr <= corte)
                maxExtension = max(-1 * *it->second.begin(), maxExtension);
            if (curr >= corte)
            {
                if (corte == maxExtension)
                {
                    break;
                    count = -1;
                }
                corte = maxExtension;
                count++;
                maxExtension = max(-1 * *it->second.begin(), maxExtension);
            }
        }
        if (maxExtension == l)
            count++;
        else
            count = -1;
        cout << count << "\n";
        str = "";
        cin.ignore();
    }
}