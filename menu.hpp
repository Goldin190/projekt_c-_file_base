#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <windows.h>
#include "walidacja.hpp"
#include "pliki.hpp"
#include "vector_class.hpp"

using namespace std;

class menu{
	private:
		pliki plik;
		vector_kontrola dane;
		walidowanie check;
		int wybor;
	public:
		bool show_menu();
		bool show_lower_menu();
		menu();
};

/* TODO (Maciej#1#): Menu i ew. pod menu*/
/* TODO (Maciej#1#): Pamietaa o dodaniu vector-a*/

#endif
