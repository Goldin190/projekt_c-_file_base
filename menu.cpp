#include "menu.hpp"

menu::menu():plik("imiona.txt"){
	this->plik.otworz();
	this->dane.get(this->plik.wczytaj());
	this->plik.zamknij();
	this->wybor = 0;
}

bool menu::show_menu(){
	
	string imie,nazwisko;
	int d,m,y,w;
	system("cls");
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
					cout<<"Wybierz rekord/y wyszukujac po: \n1.Imieniu\n2.Nazwisku\n3.Dniu urodzenia\n4.Miesiacu urodzenia\n5.Roku urodzenia\n6.Wszystkie\n";
				cin>>w;
				if(check.check_in(cin.good())){
					switch(w){
						case 1:{
							
								system("cls");
								do{
								cout<<"Podaj Imie: ";
								cin>>imie;
							}while(!this->check.check_string(imie));
							this->dane.find_by_string(imie,1,0);
							break;
						}
						case 2:{
							do{
								system("cls");
								cout<<"Podaj Nazwisko: ";cin>>nazwisko;
							}while(!check.check_string(nazwisko));
							this->dane.find_by_string(nazwisko,2,0);
							break;
						}
						case 3:{
							do{
							cout<<"Podaj dzien: ";cin>>d;
							}while(d>31||d<=0);
							this->dane.find_by_int(d,1,0);
							break;
						}
						case 4:{
							do{
							cout<<"Podaj miesiac: ";cin>>m;
							}while(m>12||m<=0);
							this->dane.find_by_int(m,2,0);
							break;
						}
						case 5:{
							do{
							cout<<"Podaj rok: ";cin>>y;
						}while(y<1918);
							this->dane.find_by_int(y,3,0);
							break;
						}
						case 6:{
							this->dane.show(-1);
							break;
						}
					}
					system("pause");
					system("cls");
					break;
				}
			}
			case 3:{
				plik.zapisz(dane.give());
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
	string imie,nazwisko;
	int d,m,y,w,pos;
		system("cls");
		cout<<"1. dodaj osobe\n";
		cout<<"2. eydtuj osobe\n";
		cout<<"3. usun osobe\n";
		cout<<"4. wroc\n";
		cin>>this->wybor;
		system("cls");
		if(check.check_in(cin.good())){
		switch(this->wybor){
			case 1:{
				do{
					cout<<"Dodawanie osoby podaj \n Imie :";
					cin>>imie;
					cout<<"\n Nazwisko :";
					cin>>nazwisko;
				}while(!check.check_string(imie)||!check.check_string(nazwisko));
				do{
					cout<<"\n date urodzenia dd\\mm\\rrrr \n";
					cin>>d>>m>>y;
				}while(!check.check_date(d,m,y));
				
				this->dane.add(imie,nazwisko,d,m,y);
				break;
			}
			case 2:{
				do{
				system("cls");
				cout<<"Wybierz rekord do edycji wyszukujac po: \n1.Imieniu\n2.Nazwisku\n3.Dniu urodzenia\n4.Miesiacu urodzenia\n5.Roku urodzenia\n6.wroc\n";
				cin>>w;
				}while(!check.check_in(cin.good()));
				switch(w){
						case 1:{
							system("cls");
							do{
								cout<<"Podaj Imie: ";
								cin>>imie;
							}while(!this->check.check_string(imie));
							pos = this->dane.find_by_string(imie,1,0);
							break;
						}
						case 2:{
							do{
								system("cls");
								cout<<"Podaj Nazwisko: ";cin>>nazwisko;
							}while(!check.check_string(nazwisko));
							pos = this->dane.find_by_string(nazwisko,2,0);
							break;
						}
						case 3:{
							do{
							cout<<"Podaj dzien: ";cin>>d;
							}while(d>31||d<=0);
							pos = this->dane.find_by_int(d,1,0);
							break;
						}
						case 4:{
							do{
							cout<<"Podaj miesiac: ";cin>>m;
							}while(m>12||m<=0);
							pos = this->dane.find_by_int(m,2,0);
							break;
						}
						case 5:{
							do{
							cout<<"Podaj rok: ";cin>>y;
						}while(y<1918);
							pos = this->dane.find_by_int(y,3,0);
							break;
						}
						case 6:{
							return false;
							break;
						}
				}
				do{
				cout<<"Podaj nowe :\nImie : ";cin>>imie;
				cout<<"Nazwisko :";cin>>nazwisko;
				}while(!check.check_string(imie)||!check.check_string(nazwisko)&&!(imie!="0"||nazwisko!="0"));
				do{
				cout<<"date urodzenia dd\\mm\\rrrr\n";cin>>d>>m>>y;
				}while(!check.check_date(d,m,y)&&!(d!=0||m!=0||y!=0));
				dane.change(pos,imie,nazwisko,d,m,y);
				break;
			}
			case 3:{
				do{
					system("cls");
					cout<<"Wybierz rekord do usuniecia wyszukujac po: \n1.Imieniu\n2.Nazwisku\n3.Dniu urodzenia\n4.Miesiacu urodzenia\n5.Roku urodzenia\n6.wroc\n";
				cin>>w;
				}while(!check.check_in(cin.good()));
				system("cls");
				switch(w){
					case 1:{
						do{
						cout<<"Podaj Imie: ";cin>>imie;
						}while(!this->check.check_string(imie));
						dane.del( this->dane.find_by_string(imie,1,0));
						break;
					}
					case 2:{
						do{
						cout<<"Podaj Nazwisko: ";cin>>nazwisko;
						}while(!this->check.check_string(nazwisko));
						dane.del( this->dane.find_by_string(nazwisko,2,0));
						break;
					}
					case 3:{
						do{
						cout<<"Podaj dzien: ";cin>>d;
						}while(m>31||m<=0);
						dane.del( this->dane.find_by_int(d,1,0));
						break;
					}
					case 4:{
						do{
						cout<<"Podaj miesiac: ";cin>>m;
						}while(m>12||m<=0);
						dane.del( this->dane.find_by_int(m,2,0));
						break;
					}
					case 5:{
						do{
						cout<<"Podaj rok: ";cin>>y;
						}while(y<1918);
						dane.del(this->dane.find_by_int(y,1,0));
						break;
					}
					case 6:{
						return false;		
						break;
					}
				}
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
		system("cls");
		return true;
	
}
