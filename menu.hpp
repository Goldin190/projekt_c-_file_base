#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <windows.h>
#include "walidacja.hpp"

using namespace std;

class menu{
	private:
		walidowanie check;
		int wybor;
	public:
		bool show_menu();
		bool show_lower_menu();
		menu();
};

/* TODO (Maciej#1#): Menu i ew. pod menu*/
/* TODO (Maciej#1#): Pamiêtaæ o dodaniu vector-a*/

#endif
