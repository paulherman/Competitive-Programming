#include <fstream>
using namespace std;

int main()
{
	ifstream fin("sum.in");
	ofstream fout("sum.out");
	long long int a, b, s;
	fin >> a >> b;
	s = a + b;
	fout << s;
	fin.close();
	fout.close();
}

