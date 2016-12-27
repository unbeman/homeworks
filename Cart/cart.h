//
// Created by unbeman on 27.12.16.
//

#ifndef HOMEWORKS_BIBL_LIST_H
#define HOMEWORKS_BIBL_LIST_H

#include <cstddef>
#include <cstring>
#include <iostream>

class Cart {
public:
    Cart(char const * const title,
         char const * const author)
    {
        strcpy(this->title, title);
        strcpy(this->author, author);
    }

    void print(){
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

    friend std::ostream &operator<<(std::ostream & stream, const Cart & cart){
        stream << "Title: " << std::string(cart.get_title(), cart.get_title() + strlen(cart.get_title())) << std::endl;
        stream << "Author: " << std::string(cart.get_author(), cart.get_author() + strlen(cart.get_author())) << std::endl;
    }

    char* get_title() const { return (char*) title; }
    char* get_author() const { return  (char*) author; }

    void set_title(char const * const str)
    {
        if (str == nullptr) return;
        memset(title, '\0', sizeof(title));
        strcpy(title, str);
    }
    void set_author(char const * const str)
    {
        if (str == nullptr) return;
        memset(author, '\0', sizeof(author));
        strcpy(author, str);
    }

    Cart* next = nullptr;
    Cart* prev = nullptr;

private:
    char title[255];
    char author[80];

};


#endif //HOMEWORKS_BIBL_LIST_H
