#include "vector_class.hpp"

void vector_kontrola::add(string imie,string nazwisko,int day,int month,int year){
	this->lista.push_back({imie,nazwisko,day,month,year});
}

void vector_kontrola::del(vector<dane>::iterator pozycja){
	this->lista.erase(pozycja);
}

void vector_kontrola::change(int pozycja,string imie,string nazwisko,int day,int month,int year){
	if(imie != ""){
		this->lista[pozycja].imie = imie;
	}
	if(nazwisko != ""){
		this->lista[pozycja].nazwisko = nazwisko;
	}
	if(day != 0){
		this->lista[pozycja].data.day = day;
	}
	if(month != 0){
		this->lista[pozycja].data.month = month;
	}
	if(year != 0){
		this->lista[pozycja].data.year = year;
	}
}

void vector_kontrola::show(int pozycja){
	pozycja--;
	if(pozycja > 0){
		cout<<"Imie nazwisko : "<<this->lista[pozycja].imie<<" "<<this->lista[pozycja].nazwisko<<endl;
		cout<<"data urodzenia : "<<this->lista[pozycja].data.day<<"\\"<<this->lista[pozycja].data.day<<"\\"<<this->lista[pozycja].data.day<<endl;
	}else if(pozycja < 0){
		for(size_t i = 0;i<this->lista.size();i++){
			cout<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
			cout<<"data urodzenia : "<<this->lista[i].data.day<<"\\"<<this->lista[i].data.day<<"\\"<<this->lista[i].data.day<<endl;
		}
	}
}

int vector_kontrola::find_by_string(string look,int param){
	size_t i = 0;
	switch(param){
		case 1:{
			while(i < this->lista.size()){
				if(this->lista[i].imie == look){
					return i;
				}
				i++;
			};
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
		}
		case 2:{
			while(i < this->lista.size()){
				if(this->lista[i].nazwisko == look){
					return i;
				}
				i++;
			};
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
		}		
	}
}

int vector_kontrola::find_by_int(int look,int param){
	size_t i = 0;
	switch(param){
		case 1:{
			while(i < this->lista.size()){
				if(this->lista[i].data.day == look){
					return i;
				}
				i++;
			};
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
		}
		case 2:{
			while(i < this->lista.size()){
				if(this->lista[i].data.month == look){
					return i;
				}
				i++;
			};
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
		}
		case 3:{
			while(i < this->lista.size()){
				if(this->lista[i].data.year == look){
					return i;
				}
				i++;
			};
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
		}		
	}
}

vector<dane> vector_kontrola::give(){
	return &(*this->lista.begin());
}


