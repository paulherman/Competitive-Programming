#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int x, y;
int nivel[100001]; //Nivelul fiecarui nod al arborelui
vector<int> graf[100001]; //Vector de adiacenta
int rmq[100001][17];
int n, m;

void dfs(int k, int l)
{
    nivel[k] = l;
    for (int i = 0; i < graf[k].size(); i++)
        dfs(graf[k][i], l + 1);
}
inline void initializare_rmq()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < graf[i].size(); j++)
            rmq[graf[i][j]][0] = i; //Adaugam tatal fiecarui nod
    rmq[1][0] = 1; //Radacina nu are tata
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            rmq[i][j] = rmq[rmq[i][j-1]][j-1]; //Calculam al 2^j-lea tata al nodului i
}
inline int lca()
{
    int log;
    if (nivel[x] < nivel[y])
        swap(x, y);
    for (log = 0; (1 << log) <= nivel[x]; log++);
    log--; //2^log <= nivel[x]
    for (int i = log; i >= 0; i--)
            if ((nivel[x] - (1 << i)) >= nivel[y])
                x = rmq[x][i]; //Calculam tatal lui x de pe acelasi nivel cu y
    if (x != y) //Daca tatal lui x de pe acelasi nivel cu y nu este y
    {
    	//Cautam tatal comun
        for (int i = log; i >= 0; i--)
        {
            if (rmq[x][i] != rmq[y][i])
            {
                x = rmq[x][i];
                y = rmq[y][i];
            }
        }
        return rmq[x][0];
    }
    else
        return x;
}
int main()
{
    ifstream fin("lca.in");
    ofstream fout("lca.out");
    int tata;

    fin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        fin >> tata;
        graf[tata].push_back(i);
    }

    initializare_rmq();
    dfs(1, 1);

    for (int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        fout << lca() << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
