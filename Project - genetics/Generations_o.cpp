//#include <iostream>
//#include <vector>
//#include <random>
//#include <time.h>
//#include <list>
//#include "Generations_o.h"
//#include "Functions.h"
//
//GenerationMember::GenerationMember() {
//
//}
//
//double GenerationMember::randVal(double _x_max) {
//	std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));
//	std::uniform_real_distribution<double> dist(0, _x_max);
//
//	return dist(eng);
//}
//
//GenerationMember::GenerationMember(bool newlist, std::vector<double> *_params) {
//	function_value = 0;
//	for (int i = 0; i < _params->size(); i++) {
//
//		double val = randVal(_params[1][i]);
//		x_values.push_back(val);
//
//		function_value += _params[0][i] * pow(x_values[i], _params[2][i]);
//	}
//}
//
//GenerationMember::~GenerationMember() {
//
//}
//
//template <class T>
//Node<T>::Node() {
//
//}
//
//template <class T>
//Node<T>::Node(bool newlist, std::vector<double> *_params) {
//	T element(newlist, _params);
//
//	//prev = nullptr;
//	//next = nullptr;
//}
//
//template <class T>
//Node<T>::Node(bool newlist, std::vector<double> *_params, const int &_genSize) {
//	T element(newlist, _params, _genSize);
//
//	//prev = nullptr;
//	//next = nullptr;
//}
//
//
//
//template<class T>
//Node<T>& List<T>::operator[](int n)
//{
//	Node<T> *ptr = head;
//
//	for (int i = 1; i < n; i++) {
//		ptr = ptr->next;
//	}
//
//	return ptr;
//}
//
//
//
//
//template<class T>
////List<T>::List()
//List<T>::List():head(NULL),tail(NULL)
//{
//
//}
//
//template<class T>
//List<T>::List(bool _newlist, std::vector<double>* _params, const int &_genSize)
//{
//	for (int i = 1; i < _genSize; i++) {
//		Node<GenerationMember> node(1, _params);
//		new_element(node);
//	}
//}
//
//
//template<class T>
//List<T>::~List() {
//
//}
//
//template<class T>
//void List<T>::new_element(Node<T> &_node)
//{
//	
//	Node<T> *ptr = &_node;
//
//	if (!head) {
//		head = ptr;
//	}
//	else
//	{
//		tail->next = ptr;
//	}
//	tail = ptr;
//
//	//return this;
//}
//
//GenerationMembersList::GenerationMembersList() {
//
//}
//
//GenerationMembersList::GenerationMembersList(bool _newList, std::vector<double> *_params, const int &_genSize) {
//	
//	
//	for (int i = 1; i < _genSize; i++) {
//		Node<GenerationMember> node(1, _params);
//		new_element(node);
//	}
//
//	//head = ;
//	//head = new Node<GenerationMember>(1, _params);
//	//
//	//Node<GenerationMember> *genPtr = head;
//	//for (int i = 1; i < _genSize; i++) {
//	//	genPtr->next = new Node<GenerationMember>(1, _params);
//	//	genPtr->next->prev = genPtr;
//	//	genPtr = genPtr->next;
//	//}
//	//tail = genPtr;
//
//}
//
//GenerationMembersList::~GenerationMembersList() {
//
//}
//
//
////GenerationsList::GenerationsList() {
////
////}
////
////GenerationsList::GenerationsList(std::vector<double> *_params, const int &_genSize) {
////
////	head = new Node<GenerationMembersList>(1, _params, _genSize);
////
////	tail = head;
////}
////
////GenerationsList::~GenerationsList() {
////
////}
//
