//
// Created by a.kukuev on 06.12.16.
//
#include <iostream>
#include "computer.h"
using namespace std;

void Computer::print() const {
    cout << "name: " << name << endl;
    cout << "ram: " << ram << "GB" << endl;
    cout << "video_card: " << video_card << endl;
}

void Server::print() const {
    cout << "cores: " << cores << endl;
    cout << "channel number: " << channel_number << endl;
    cout << "features: " << features << endl;
}

void PC::print() const {
    Computer::print();
    cout << "sound: " << ((sound)? "yes":"no") << endl;
    cout << "sound card: " << sound_card << endl;
    cout << "mouse type: " << mouse_type << endl;
}

void Notebook::print() const {
    Computer::print();
    cout << "display: " << display << "\"" << endl;
    cout << "battery life: " << battery_life << "mAh"<< endl;
    cout << "weight: " << weight << "kg" <<endl;
}

void PS::print() const {
    Notebook::print();
    Server::print();
    cout << "internet acess: " << ((internet_access)? "yes":"no") << endl;
    cout << "server name: " << server_name << endl;
    cout << "os name: " << os_name << endl;
}