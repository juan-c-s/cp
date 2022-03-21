
#define ll long long
#define ld long double
#include <iostream>
#include <cmath>
#define INF 10e12

using namespace std;

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
struct linea
{
    punto p, pq; // p = inicio de línea | pq = distancia linea

    linea(punto p, punto q) : p(p), pq(q - p) {}

    bool has(punto r) { return (pq ^ (r - p)) == 0; }

    bool operator/(linea l)
    {
        return (pq ^ l.pq) == 0;
    } // Devuelve si son paralelas o no

    punto operator^(linea l) // Punto de Intersección
    {
        if (*this / l)
            return punto(INF, INF);
        punto r = l.p + l.pq * (((p - l.p) ^ pq) / (l.pq ^ pq));
        return r;
    }
};