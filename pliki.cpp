#include "pliki.hpp"

pliki::pliki(string nazwa){
	this->plik_nazwa = nazwa;
}

bool pliki::otworz(){
	this->plik.open(this->plik_nazwa.c_str(), ios::in | ios::out );
	if(this->plik.good()){
		return true;
	}else{
		this->plik.close();
		return false;
	}
}

bool pliki::zamknij(){
	this->plik.close();
}

void pliki::zapisz(vector<dane>&buffor){
	for(size_t i = 0;i<buffor.size();i++){
		this->plik<<buffor[i].imie<<endl<<buffor[i].nazwisko<<endl<<buffor[i].data.day<<endl<<buffor[i].data.month<<endl<<buffor[i].data.year<<endl;
	}
}

void pliki::wczytaj(vector<dane>& buffor){
	string rekord;
	string imie,nazwisko;
	int day,month,year;
	while(!this->plik.eof()){
		if(!this->plik.eof()){
			getline(this->plik,imie);
			getline(this->plik,nazwisko);
			getline(this->plik,rekord);
			day = atoi(rekord.c_str());
			getline(this->plik,rekord);
			month = atoi(rekord.c_str());
			getline(this->plik,rekord);
			year = atoi(rekord.c_str());
			
			buffor.push_back({imie,nazwisko,day,month,year});
		}
	}
	buffor.pop_back();
}

