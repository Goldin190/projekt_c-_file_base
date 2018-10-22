#include<iostream>
#include<windows.h>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;

bool check_string(string to_convert);
bool menu();
bool inCorrect(bool inState);
void dodaj_imie_nazwisko();
bool zapisz_do_pliku(string imie, string nazwisko);
bool wczytaj_z_pliku();

int main(){
	
	while(menu());
		
	system("pause");
	return 0;
}

bool inCorrect(bool inState){
	if(inState){
		return true;
	}else{
		cin.clear();
		cin.sync();
		return false;
	}
}
	
bool menu(){
	int wybor;
	do{
		system("cls");
		cout<<"  wybierz opcje  \n";
		cout<<"1.dodaj imie i nazwisko\n";
		cout<<"2.wczytaj imiona i nazwiska z pliku\n";
		cout<<"3.wyjdz\n";
		cin>>wybor;
		if(inCorrect(cin.good())){
			system("cls");
			switch(wybor){
				case 1:{
					dodaj_imie_nazwisko();
					break;
				}
				case 2:{
					if(!wczytaj_z_pliku()){
						cout<<"nie udalo sie wczytac pliku :C \n";
					}else{
						system("pause");
					}
					break;
				}
				case 3:{
					return false;
					break;
				}
				default:{
					cout<<"Bledna opcja...!\n";
					Sleep(2000);
					break;
				}
			}
		}else{
			cout<<"Bledna opcja...!\n";
			Sleep(2000);
		}
	}while(wybor!=3);
}

bool zapisz_do_pliku(string imie, string nazwisko){
	fstream plik;
	string nazwa_pliku = "imiona.txt";
	plik.open(nazwa_pliku.c_str(),ios::out | ios::app);
	if(plik.good()){
	plik<<imie<<" "<<nazwisko<<endl;
	}else{
		return false;
	}
	plik.close();
	return true;
}

bool wczytaj_z_pliku(){
	fstream plik;
	string nazwa_pliku = "imiona.txt",wypisz;
	
	int i=0;
	
	plik.open(nazwa_pliku.c_str(),ios::in);
	
	if(plik.good()){
		while(!plik.eof()){
			getline(plik,wypisz);
			if(!plik.eof()){
				i++;
				cout<<i<<". "<<wypisz<<endl;
			}
		};
	}else{
		return false;
	}
	
	plik.close();
	return true;
}

void dodaj_imie_nazwisko(){
	string imie,nazwisko;
	cin.ignore();
	
	do{
	cout<<"Podaj imie: \n";
	getline(cin,imie);
	system("cls");
	}while(!check_string(imie));
	
	do{
	cout<<"Podaj nazwisko: \n";
	getline(cin,nazwisko);
	system("cls");
	}while(!check_string(nazwisko));
	
	if(zapisz_do_pliku(imie,nazwisko)){
		cout<<"dodano do pliku\n";	
	}else{
		cout<<"nie uda³o siê dodaæ do pliku\n";
	}
}
bool check_string(string to_convert){
	 
	 int lenght_of_string  = to_convert.length(), i,o,size = 25;
	 if(lenght_of_string == 0){
	 	return false;
	 }
	 char *tab;
	 tab = new char [lenght_of_string];
	 char unallowed[25] = {'/','\\','\'','[',']','{','}','|',';',':','\"',',','.','!','@','#','$','%','^','&','*','(',')',' '};
	 strncpy(tab,to_convert.c_str(),lenght_of_string);
	 
	 for(i = 0;i<=lenght_of_string-1;i++){
	 	for(o = 0;o<size;o++){
	 		if(tab[i] == unallowed[o])
			 return false;
		 }
		 for(o=0;o<10;o++){
		 	char number = o +'0';
		 	if(tab[i] == number)
		 	return false;
		 }
	 }
	 
	 delete [] tab;
	 
	 return true;
}
