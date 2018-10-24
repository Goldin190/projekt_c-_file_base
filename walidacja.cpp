#include "walidacja.hpp"

bool czy_przystepny(int rok){
    return (rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0);
}

bool walidowanie::check_in(bool in){
	if(in){
		return true;
	}else{
		cin.clear();
		cin.sync();
		return false;
	}
}

bool walidowanie::check_date(int day,int month,int year){
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(czy_przystepny(year)){
		months[1] = 29;
	}
	if(year < 1918 || year > 2118){
		return false;
	}
	if(month > 12 || month < 1){
		return false;
	}
	if(day < 1 || day > months[month-1]){
		return false;
	}
	return true;
	
}

bool walidowanie::check_string(string to_convert){
     
     int lenght_of_string  = to_convert.length(), i,o,size = 25;
     if(lenght_of_string  <= 2){
     	if(lenght_of_string == 1 && to_convert == "0"){
     		return true;
		 }
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

