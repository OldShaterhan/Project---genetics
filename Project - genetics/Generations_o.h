//#pragma once
//#include <iostream>
//#include <list>
//#include <vector>
//
//class GenerationMember {
//protected:
//
//	std::vector <double> x_values;
//
//	long double function_value;
//
//public:
//	GenerationMember();
//	GenerationMember(bool, std::vector<double> *);
//	~GenerationMember();
//	double randVal(double);
//};
//
//template <class T>
//struct Node {
//	T elem;
//
//	Node *prev;
//	Node *next;
//
//	Node();
//	Node(bool, std::vector<double> *);
//	Node(bool, std::vector<double> *, const int &);
//};
//
//
//template <class T>
//class List {
//protected:
//	Node<T> *head;
//	Node<T> *tail;
//
//
//public:
//	List();
//	List(bool, std::vector<double> *, const int &);
//	~List();
//	Node<T> &operator[](int);
//	void new_element (Node<T> &);
//};
//
//class GenerationMembersList :public List<GenerationMember> {
//public:
//	GenerationMembersList();
//	GenerationMembersList(bool, std::vector<double> *, const int &);
//	~GenerationMembersList();
//
//};
////
////
////class GenerationsList :public List<GenerationMembersList> {
////protected:
////
////public:
////	GenerationsList();
////	GenerationsList(std::vector<double>*, const int &);
////	~GenerationsList();
////};
