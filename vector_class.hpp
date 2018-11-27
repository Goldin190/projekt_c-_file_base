#ifndef VECTOR_CLASS_HPP
#define VECTOR_CLASS_HPP

#include<iostream>
#include<vector>
#include<windows.h>
#include<iterator>
#include"struct.hpp"
using namespace std;


class vector_kontrola{
	private: vector<dane> lista;
	public:
		void add(string,string,int,int,int);
		void del(int);
		void change(int,string,string,int,int,int);
		void show(int);
		int find_by_string(string,int,int);
		int find_by_int(int,int,int);
		void get(vector<dane>);
		vector<dane>give();
};

#endif
