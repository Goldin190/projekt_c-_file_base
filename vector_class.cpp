#include "vector_class.hpp"

void vector_kontrola::add(string imie,string nazwisko,int day,int month,int year){
	this->lista.push_back({imie,nazwisko,day,month,year});
}

void vector_kontrola::del(int pozycja){
	vector<dane>::iterator it=this->lista.begin();
		it = next(it,pozycja);
	this->lista.erase(it);
}

void vector_kontrola::change(int pozycja,string imie,string nazwisko,int day,int month,int year){
	if(imie != "0"){
		this->lista[pozycja].imie = imie;
	}
	if(nazwisko != "0"){
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
	if(pozycja >= 0){
		cout<<"Imie nazwisko : "<<this->lista[pozycja].imie<<" "<<this->lista[pozycja].nazwisko<<endl;
		cout<<"data urodzenia : "<<this->lista[pozycja].data.day<<"\\"<<this->lista[pozycja].data.month<<"\\"<<this->lista[pozycja].data.year<<endl;
	}else if(pozycja < 0){
		for(size_t i = 0;i<this->lista.size();i++){
			cout<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
			cout<<"data urodzenia : "<<this->lista[i].data.day<<"\\"<<this->lista[i].data.month<<"\\"<<this->lista[i].data.year<<endl;
		}
	}
}

int vector_kontrola::find_by_string(string look,int param,int opt){
	size_t i = 0;
	bool found = false;
	switch(param){
		case 1:{
			while(i < this->lista.size()){
				if(this->lista[i].imie == look){
					cout<<"id = "<<i<<" "<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
					found = true;
				}
				i++;
			};
			if(found && opt==1){
				return 0;
			}else if(found){
				cout<<"wybierz rekord\n";
				cin>>i;
				return i;
			}else if(!found){
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
			}
		}
		case 2:{
			while(i < this->lista.size()){
				if(this->lista[i].nazwisko == look){
					cout<<"id = "<<i<<" "<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
					found = true;
				}
				i++;
			};
				if(found && opt==1){
				return 0;
			}else if(found){
				cout<<"wybierz rekord\n";
				cin>>i;
				return i;
			}else if(!found){
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
			}
		}		
	}
}

int vector_kontrola::find_by_int(int look,int param,int opt){
	size_t i = 0;
	bool found = false;
	switch(param){
		case 1:{
			while(i < this->lista.size()){
				if(this->lista[i].data.day == look){
					cout<<"id = "<<i<<" "<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
					found = true;
				}
				i++;
			};
			if(found && opt==1){
				return 0;
			}else if(found){
				cout<<"wybierz rekord\n";
				cin>>i;
				return i;
			}else if(!found){
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
			}
		}
		case 2:{
			while(i < this->lista.size()){
				if(this->lista[i].data.month == look){
					cout<<"id = "<<i<<" "<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
					found = true;
				}
				i++;
			};
			if(found && opt==1){
				return 0;
			}else if(found){
				cout<<"wybierz rekord\n";
				cin>>i;
				return i;
			}else if(!found){
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
			}
		}
		case 3:{
			while(i < this->lista.size()){
				if(this->lista[i].data.year == look){
					cout<<"id = "<<i<<" "<<"Imie nazwisko : "<<this->lista[i].imie<<" "<<this->lista[i].nazwisko<<endl;
					found = true;
				}
				i++;
			};
			if(found && opt==1){
				return 0;
			}else if(found){
				cout<<"wybierz rekord\n";
				cin>>i;
				return i;
			}else if(!found){
			cout<<"Brak Wynikow\n";
			Sleep(2000);
			break;
			}
		}		
	}
	return -1;
}

void vector_kontrola::get(vector<dane> buffor){
	this->lista.swap(buffor);
}

vector<dane> vector_kontrola::give(){
	vector<dane> returned;
	returned.swap(this->lista);
	return returned;
}


