/*
 * Autor: Paul Herman
 * Problema: heap-uri
 * Data: 13.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/heapuri
 */
#include <fstream>
#include <set>
#include <iostream>
using namespace std;

set<int> heap;
int ordine[200001];

int main()
{
	int n = 0; //Ordinea cronologica
	int operatii; //Nr. de operatii
	short int operatia; //Tipul operatiei
	int op_1, op_3;
	ifstream fin("heapuri.in"); //Fisierul de intrare
	ofstream fout("heapuri.out"); //Fisierul de iesire
	fin >> operatii; //Citim nr. de operatii
	while (operatii > 0)
	{
		//Pana nu am epuziat operatiile
		fin >> operatia; //Citeste tipul operatiei
		switch (operatia)
		{
			case 3:
			{
				//Afiseaza minimul
				fout << *heap.begin() << "\n";
				break;
			}
			case 1:
			{
				fin >> op_1; //Citeste elementul adaugat
				n++; //Incrementeaza numarul de elemente total adaugate 
				ordine[n] = op_1; //Adauga elementul in vectorul de ordine
				heap.insert(op_1); //Adauga elementul in heap
				break;
			}
			case 2:
			{
				fin >> op_3; //Citeste elementul pt sters
				heap.erase(ordine[op_3]); //Sterge elementul
				break;
			}
		}
		operatii--; //Am terminat o operatie
	}
	fin.close();
	fout.close();
	return 0;
}
