//
// Created by devernua on 27.12.16.
//

#ifndef HOMEWORKS_STD_LIST_H
#define HOMEWORKS_STD_LIST_H
#include <list>
#include "cart.h"

inline void printList(std::list<Cart>& library) {
	for (auto it = library.begin(); it != library.end(); it++) {
		it->print();
	}
}

std::list<Cart>::iterator findCardByName(std::list<Cart>& library, const char* title) {
	for (auto it = library.begin(); it != library.end(); it++) {
		if (strcmp(it->get_title(), title) == 0) {
			return it;
		}
	}
	return library.end();
}
#endif //HOMEWORKS_STD_LIST_H
