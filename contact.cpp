#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "contact.h"

Contact::Contact(){
	first = "";
	middle = "";
	last = "";
	number = 9999999999;
	address = "";
}

Contact::Contact(const std::string &f, const std::string &l){
	first = f;
	middle = "";
	last = l;
	number = 9999999999;
	address = "";
}

Contact::Contact(const std::string &f, const std::string &l, const std::string &a){
	first = f;
	middle = "";
	last = l;
	number = 9999999999;
	address = a;
}

Contact::Contact(const std::string &f, const std::string &l, const long int &n, const std::string &a){
	first = f;
	middle = "";
	last = l;
	number = n;
	address = a;
}

Contact::Contact(const std::string &f, const std::string &m, const std::string &l, const long int &n, const std::string &a){
	first = f;
	middle = m;
	last = l;
	number = n;
	address = a;
}


std::string Contact::getName() const {
	if(middle == ""){
		return last + ", " + first;
	}
	return last + ", " + first + " " + middle;
}

std::string Contact::getFull() const {
	if(number == 9999999999){
		return last + ", " + first + " " + middle + "\n" + address;
	}

	std::string num = std::to_string(number);
	std::string new_num = "";

	for(std::string::size_type i = 0; i < num.size(); i++){
		if(i == 0){
			new_num += "(";
			new_num += num[i];
		} else if((i % 3 == 0) && ((i != 6) && (i != 9))){
			new_num += ") ";
			new_num += num[i];
		} else if(i % 6 == 0){
			new_num += "-";
			new_num += num[i];
		} else{
			new_num += num[i];
		}
	}


	if(middle == ""){
		return last + ", " + first + "\n" + new_num + "\n" + address;
	}
	return last + ", " + first + " " + middle + "\n" + new_num + "\n" + address;
}


void Contact::findPerson(const std::string &which, const std::string &n, const std::vector<Contact> &c){
	if(which != "First"){
		if(which != "Last"){
			if(which != "Address"){
				std::cerr << "Wrong intended search category" << std::endl;
				exit(1);
			}

		}
	}

	bool flag = false;
	if(which == "First"){
		for(uint i = 0; i < c.size(); i++){
			if(n == c[i].getFirst()){
				std::cout << "PERSON FOUND:\n" << c[i].getFull() << std::endl;
				std::cout << "\n";
				flag = true;
			}
		}
	}

	if(which == "Last"){
		for(uint i = 0; i < c.size(); i++){
			if(n == c[i].getLast()){
				std::cout << "PERSON FOUND:\n" << c[i].getFull() << std::endl;
				std::cout << "\n";
				flag = true;
			}
		}
	}


	if(which == "Address"){
		for(uint i = 0; i < c.size(); i++){
			if(n == c[i].getAddy()){
				std::cout << "PERSON FOUND:\n" << c[i].getFull() << std::endl;
				std::cout << "\n";
				flag = true;
			}
		}
	}

	if(!(flag)){
		if(which == "First" || which == "Last"){
			std::cout << which << " name '" << n << "' NOT FOUND\n" << std::endl;
		}else {
			std::cout << "Address: '" << n << "' NOT FOUND\n" << std::endl;
		}
	}
}

void Contact::printAllContacts(const std::vector<Contact> &c){
	std::cout << "\n";
	int temp = 0;

	for(uint i = 0; i < c.size(); i++){
		temp = i + 1;
		std::cout << "Contact #" << temp << ":" << std::endl;
		if(i + 1 == c.size()){
			std::cout << c[i].getFull() << std::endl;
		} else {
			if(c[i].getAddy() == ""){
				std::cout << c[i].getFull() << std::endl;
			} else {
				std::cout << c[i].getFull() << "\n" << std::endl;
			}
		}
	}
}

void Contact::printAllNames(const std::vector<Contact> &c){
	std::cout << "\nContact List Names:\n";

	for(uint i = 0; i < c.size(); i++){
		if(i + 1 == c.size()){
			if(c[i].getMiddle() == ""){
				std::cout << c[i].getLast() << ", " << c[i].getFirst() << std::endl;
			} else {
				std::cout << c[i].getLast() << ", " << c[i].getFirst() << " " << c[i].getMiddle() << std::endl;
			}
		} else{
			if(c[i].getMiddle() == ""){
				std::cout << c[i].getLast() << ", " << c[i].getFirst() << std::endl;
			} else {
				std::cout << c[i].getLast() << ", " << c[i].getFirst() << " " << c[i].getMiddle() << std::endl;
			}
		}
	}
	std::cout << std::endl;
}

void Contact::printNumberOfContacts(const std::vector<Contact> &c){
	std::cout << "Number of Contacts: " << c.size() << std::endl;
	std::cout << std::endl;
}

void Contact::addFriend(const Contact c1){
	friends.push_back(c1);
}

void Contact::removeFriend(const Contact c1){
	bool flag = false;
	for(uint i = 0; i < friends.size(); i++){
		if(friends[i].getFull() == c1.getFull()){
			flag = true;
			friends.erase(friends.begin() + i);
		}
	}

	if(!(flag)){
		std::cerr << "Error: Cannot remove friend " << c1.getFirst() << " " << c1.getLast()
			<< ", this person is not in the friends list" << std::endl;
	}
}

void Contact::printFriends(){
	sort(friends.begin(), friends.end(), friends_ordering);
	std::cout << first << " " << last << " is friends with:\n";
	for(uint i = 0; i < friends.size(); i++){
		std::cout << friends[i].getFirst() << " " << friends[i].getLast() << std::endl;
	}
}

bool ordering(const Contact &c1, const Contact &c2){
	if(c1.getLast() < c2.getLast()){
		return true;
	} else if(c1.getLast() == c2.getLast()){
		if(c1.getFirst() < c2.getFirst()){
			return true;
		}
	}
	return false;
}

bool friends_ordering(const Contact &c1, const Contact &c2){
	if(c1.getFirst() < c2.getFirst()){
		return true;
	} else if(c1.getFirst() == c2.getFirst()){
		if(c1.getLast() < c2.getLast()){
			return true;
		}
	}
	return false;
}
