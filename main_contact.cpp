#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "contact.h"

int main(){
	std::vector<Contact> contacts;

	Contact a("Dexter", "Geraldo", "Johnson", 6382821039, "8245 Cherry Lane");
	Contact b("Buster", "Patterson", "123 Motor Ave");
	Contact c("Maeve", "Anne", "Peterson", 1239432003, "9000 Burdett Ave");
	Contact i("Iron", "Man");
	Contact k("Penelope", "Cioffi", "345 Oak Lane);
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
