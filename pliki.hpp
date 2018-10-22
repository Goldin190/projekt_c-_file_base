#ifndef PLIKI_HPP
#define PLIKI_HPP

#include<iostream>
#include<windows.h>
#include<fstream>
#include<vector>
#include <stdlib.h> 
#include"struct.hpp"

using namespace std;


class pliki{
	private :
		fstream plik;
		string plik_nazwa;
		int length;
	public :
		pliki(string);
		bool otworz();
		bool zamknij();
		void zapisz(vector<dane>&);
		void wczytaj(vector<dane>&);	
};



#endif
