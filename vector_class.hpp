#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include<iostream>
#include<vector>
#include<windows.h>
#include"struct.hpp"
using namespace std;


class vector_kontrola{
	private: vector<dane> lista;
	public:
		void add(string,string,int,int,int);
		void del(vector<dane>::iterator);
		void change(int,string,string,int,int,int);
		void show(int);
		int find_by_string(string,int);
		int find_by_int(int,int);
		vector<dane> give();
};

#endif
