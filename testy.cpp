#include<iostream>
#include<windows.h>
#include<vector>
#include<fstream>
#include"pliki.cpp"
#include"vector_class.cpp"

using namespace std;


int main(){
	vector_kontrola a;
	pliki kek("imiona.txt");
	kek.otworz();
	a.get(kek.wczytaj());
	kek.zamknij();
	a.show(a.find_by_int(3,1));
	system("pause");
	return 0;
}







