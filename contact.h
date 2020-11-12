#ifndef __contact_h_
#define __contact_h_

#include <string>
#include <iostream>
#include <vector>

class Contact{ //Players class
public:
	Contact();
	Contact(const std::string &f, const std::string &l);
	Contact(const std::string &f, const std::string &l, const std::string &a);
	Contact(const std::string &f, const std::string &l, const long int &n, const std::string &a);
	Contact(const std::string &f, const std::string &m, const std::string &l, const long int &n, const std::string &a);


	//accessors
	std::string getName() const;
	std::string getFull() const;

	std::string getFirst() const { return first; }
	std::string getLast() const { return last; }
	std::string getMiddle() const { return middle; }
	long int getNum() const { return number; }
	std::string getAddy() const { return address; }

	void addFriend(const Contact c1);
	void removeFriend(const Contact c1);
	void printFriends();

	void findPerson(const std::string &which, const std::string &n, const std::vector<Contact> &c);
	void printAllContacts(const std::vector<Contact> &c);
	void printAllNames(const std::vector<Contact> &c);
	void printNumberOfContacts(const std::vector<Contact> &c);

private: 
	std::string first;
	std::string middle;
	std::string last;
	long int number;
	std::string address;
	std::vector<Contact> friends;
};


bool ordering(const Contact &c1, const Contact &c2);
bool friends_ordering(const Contact &c1, const Contact &c2);

#endif