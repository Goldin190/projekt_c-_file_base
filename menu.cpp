#include "menu.hpp"

menu::menu(){
	this->wybor = 0;
}

bool menu::show_menu(){
	cout<<"Wybierz opcje\n";
	cout<<"1. edytuj osoby\n";
	cout<<"2. wyswietl osoby\n";
	cout<<"3. wyjdz\n";
	cin>> this->wybor;
	system("cls");
	if(check.check_in(cin.good())){
		switch(this->wybor){
			case 1:{
				while(this->show_lower_menu());
				break;
			}
			case 2:{
				//look
				break;
			}
			case 3:{
				return false;
				break;
			}
			default:{
				cout<<"Nie odpowiednia opcja...\n";
				Sleep(2000);
				system("cls");
				break;
			}
		}
	}
	return true;
}

bool menu::show_lower_menu(){
		cout<<"1. dodaj osobe\n";
		cout<<"2. eydtuj osobe\n";
		cout<<"3. usun osobe\n";
		cout<<"4. wroc\n";
		cin>>this->wybor;
		system("cls");
		if(check.check_in(cin.good())){
		switch(this->wybor){
			case 1:{
				//add
				break;
			}
			case 2:{
				//edit
				break;
			}
			case 3:{
				//dell
				break;
			}
			case 4:{
				return false;
				break;
			}
			default:{
				cout<<"Nie odpowiednia opcja...\n";
				Sleep(2000);
				system("cls");
				break;
			}
		}
	}
		return true;
	
}




