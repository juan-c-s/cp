

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl

#define pb push_back

#define MAX 1e6 + 1
#define MIN -1e7

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct punto
{
    ll x, y;
    punto(ll x = 0, ll y = 0) : x(x), y(y) {}
    punto operator+(punto a) { return punto(x + a.x, y + a.y); }
    punto operator-(punto a) { return punto(x - a.x, y - a.y); }

    punto operator+(ll a) { return punto(x + a, y + a); } //Traslación
    punto operator*(ll a) { return punto(x * a, y * a); } //Escala

    punto operator*(punto a) { return punto(x * a.x, y * a.y); } //producto escalar
    ld operator^(punto a) { return x * a.y - y * a.x; }          //producto vectorial

    ld norm() { return hypotl(x, y); }
};

double areaTriangulo(punto x, punto y, punto z)
{

    DBG((y - x).x);
    DBG((y - x).y);
    DBG((z - y).x);
    DBG((z - y).y);
    DBG((x - z).x);
    DBG((x - z).y);
    double xy = (y - x).norm();
    double yz = (z - y).norm();
    double zx = (x - z).norm();
    DBG(xy);
    DBG(yz);
    DBG(zx);
    RAYA;
    if (xy > yz)
    {
        return 0.5 * (yz * min(xy, zx));
    }
    else
        return 0.5 * (xy * min(yz, zx));
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        double px, py, ax, ay, bx, by, cx, cy;
        // cout << areaTriangulo(punto(0, 1), punto(1, 1), punto(1, 0)) << "\n";

        cin >> px >> py >> ax >> ay >> bx >> by >> cx >> cy;
        punto a(ax, ay);
        punto b(bx, by);
        punto c(cx, cy);
        punto p(px, py);
        double triangulo = areaTriangulo(a, b, c);
        double s1 = areaTriangulo(a, p, b);
        double s2 = areaTriangulo(a, p, c);
        double s3 = areaTriangulo(c, p, b);
        DBG(s1);
        DBG(s2);
        DBG(s3);
        double t2 = s1 + s2 + s3;
        DBG(triangulo);
        DBG(t2);
        string ans = "OUT";
        if (t2 == triangulo)
            ans = "IN";
        cout << "Case #" << i + 1 << ": " << ans << "\n";
    }
}