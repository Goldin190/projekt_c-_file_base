#ifndef WALIDACJA_HPP
#define WALIDACJA_HPP	

#include <iostream>
#include <string>
#include <time.h>
#include <cstring>

using namespace std;

class walidowanie{
	private:
	time_t czas;
    struct tm * data;
	public:
		bool check_in(bool);
		bool check_date(int,int,int);
		bool check_string(string);
		bool czy_przestepny(int);
};

/* TODO (Maciej#2#): walidacja cin */
#endif
