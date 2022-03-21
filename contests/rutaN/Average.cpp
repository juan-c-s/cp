#include <vector>
#include <iostream>

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "=============================" << endl
using namespace std;

int main()
{
    //Usar las siguientes líneas de código para mejorar flujos I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int evaluaciones, B, total = 0;
        ; //B=estudiantes
        cin >> evaluaciones >> B;
        vector<double> eva(evaluaciones);

        for (int i = 0; i < evaluaciones; i++)
        {
            cin >> eva[i];
            // DBG(eva[i]);
            // RAYA;
            total += eva[i];
        }
        for (int i = 0; i < B; i++)
        {
            double cont = 0.0;
            for (int j = 0; j < evaluaciones; j++)
            {
                int num;

                cin >> num;

                cont += num * (eva[j] / total);
                // DBG(cont);
            }

            double first = ((int)(cont * 10)) % 10, second = ((int)(cont * 100)) % 10;
            double up = cont - (int)(cont / 5) * 5, down = ((int)(cont / 5) + 1) * 5 - cont;

            // DBG(up);
            // DBG(down);
            // RAYA;
            if (first == 0 && ((int)cont % 5 == 0))
                cout << cont << " SAME" << endl;
            else if (up < down)
            {

                cout << (int)(cont / 5) * 5 << " DOWN\n";
            }
            else
            { //down<up

                cout << (int)((cont / 5) + 1) * 5 << " UP\n";
            }
        }
    }
    return 0;
}