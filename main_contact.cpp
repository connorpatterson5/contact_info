#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "contact.h"

int main(){
	std::vector<Contact> contacts;

	Contact a("Connor", "James", "Patterson", 6382821039, "48 Huntley Ave");
	Contact b("Buster", "Patterson", "48 Huntley Ave");
	Contact c("Chenoa", "Chavious", "Cioffi", 1239432003, "109 Michel Dr");
	Contact i("Iron", "Man");
	Contact k("Penelope", "Cioffi", "109 Michel Dr");
	Contact d;

	contacts.push_back(a);
	contacts.push_back(b);
	contacts.push_back(c);
	contacts.push_back(k);
	contacts.push_back(i);

	d.findPerson("First", "Connor", contacts);
	d.findPerson("Last", "Cioffi", contacts);
	d.findPerson("Address", "48 Huntley Ave", contacts);
	d.findPerson("Last", "Connor", contacts);

	//d.printAllContacts(contacts);
	sort(contacts.begin(), contacts.end(), ordering);

	std::cout << "\nAFTER SORT:";
	d.printAllContacts(contacts);
	d.printAllNames(contacts);
	d.printNumberOfContacts(contacts);


	a.addFriend(b);
	a.addFriend(c);
	a.addFriend(k);
	a.removeFriend(b);
	a.printFriends();
}