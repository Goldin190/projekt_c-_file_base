#include "walidacja.hpp"

walidowanie::walidowanie(){
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

