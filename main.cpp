#include <iostream>
#include "menu.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	menu gui;
	
	while(gui.show_menu());
	/*
	klasy:
	-menu
	-walidacja
	-pliki
	-akcje_programu
	*/
	
	system("pause");
	return 0;
}
