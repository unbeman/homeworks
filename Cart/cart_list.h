//
// Created by unbeman on 27.12.16.
//

#ifndef HOMEWORKS_CART_LIST_H
#define HOMEWORKS_CART_LIST_H

#include <cassert>
#include <fstream>
#include "cart.h"

class CartList {
public:
    CartList() {}

    void push_back(Cart* node)
    {
        if(tail == nullptr) {
            tail = node;
            head = tail;
        } else {
            tail->next = node;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    void insert(Cart * current, Cart* node)
    {
        assert(node != nullptr && current != nullptr);
        node->next = current->next;
        node->prev = current;
        current->next = node;
        node->next->prev = node;
    }

    Cart * find(char const *const name)
    {
        if(name == nullptr) return nullptr;

        for (Cart* i = head; i != nullptr; i = i->next){
            if (strncmp(name, i->get_title(), strlen(name)) == 0){
                return i;
            }
        }
        return nullptr;
    }

    void delete_node(const char * title)
    {
        //assert(node != nullptr);
        Cart* node = find(title);
        if (node == nullptr) return;

        if (node->next == nullptr){
            tail = node->prev;
            tail->next = nullptr;
        } else if(node->prev == nullptr) {
            head = node->next;
            head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;
    }

    void print() {
        for (Cart* i = head; i != nullptr; i = i->next) {
            i->print();
        }
    }

    ~CartList() {
        if (head == nullptr) return;
        while ( head->next != nullptr){
            head = head->next;
            delete head->prev;
        }
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    void save(const char *filepath) {
        std::ofstream fout;
        fout.open(filepath, std::ofstream::out);
        for (Cart* i = head; i != nullptr; i = i->next) {
            fout << "Title: " << i->get_title() << std::endl;
            fout << "Author: " << i->get_author() << std::endl;
        }
        fout.close();
    }

    void load(const char *filepath) {
        std::ifstream fin;
        fin.open(filepath, std::ifstream::in);
        assert(!fin.fail());

        while (!fin.eof()) {
            std::string title;
            std::string author;
            std::string tmp;
            fin >> tmp >> title >> tmp >> author;
            if (title.length() == 0) return;
            //std::cout << title << author << std::endl;
            //title.erase(0, strlen("Title: "));
            //author.erase(0, strlen("Author: "));
            push_back(new Cart(title.c_str(), author.c_str()));
        }
    }

private:
    Cart* head = nullptr;
    Cart* tail = nullptr;
};

#endif //HOMEWORKS_CART_LIST_H
