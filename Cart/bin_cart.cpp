#include <iostream>
#include "../Computer/computer.h"
#include "../Figures/figures.h"
#include "cart_list.h"
using namespace std;

int main() {
    Cart * A = new Cart("00", "Andrey");
    Cart * B = new Cart("01", "01Andrey");
    Cart * C = new Cart("02", "02Andrey");

    CartList cart;
    cart.push_back(A);
    cart.push_back(B);
    cart.push_back(C);
    cart.push_back(new Cart("03", "hum"));
    cart.delete_node("00");
    cart.delete_node("04");
    cart.delete_node("01");


    //cart.print();

    //cart.save("test.txt");

    CartList file;
    file.load("test.txt");
    file.print();

    return 0;
}