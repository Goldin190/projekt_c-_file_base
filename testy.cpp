#include<iostream>
#include<windows.h>
#include<vector>
#include<fstream>
#include"pliki.cpp"
#include"vector_class.cpp">

using namespace std;


int main(){
	vector_kontrola a;
	pliki kek("imiona.txt");
	
	a.add("Maciej","Nowowiejski",3,2,1999);
	a.add("Piotr","Kowalski",4,5,1997);
	a.add("Marcin","Nowak",18,8,1984);
	a.add("Marysia","Kowal",1,7,2005);
	a.add("Katarzyna","Kowalczyk",30,3,2014);

	kek.otworz();
	kek.wczytaj(a.give());
	kek.zamknij();
	a.show(0);
	system("pause");
	return 0;
}



