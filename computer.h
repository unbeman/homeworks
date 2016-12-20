//
// Created by a.kukuev on 06.12.16.
//
#include <string>
#ifndef HOMEWORKS_COMPUTER_H
#define HOMEWORKS_COMPUTER_H
class Computer{
public:
    Computer(std::string name, float ram, std::string video_card):
            name(name),
            ram(ram),
            video_card(video_card)
    {}
    //virtual ~Computer();
    virtual void print() const;

private:
    std::string name;
    float ram;
    std::string video_card;
};

class Server{
public:
    Server(int cores, int channel_number, std::string features):
            cores(cores),
            channel_number(channel_number),
            features(features)
    {}
    //virtual ~Server();
    virtual void print() const;

private:
    int cores;
    int channel_number;
    std::string features;

};

class PC: public Computer{
public:
    PC(std::string name, float ram, std::string video_card,

       bool sound, std::string sound_card, std::string mouse_type):

            Computer(name, ram, video_card),
            sound(sound),
            sound_card(sound_card),
            mouse_type(mouse_type)
    {}
//    ~PC();
    virtual void print() const;

private:
    bool sound;
    std::string sound_card;
    std::string mouse_type;
};

class Notebook: public Computer{
public:
    Notebook(std::string name, float ram, std::string video_card,

             float display, float battery_life, float weight):

            Computer(name, ram, video_card),
            display(display),
            battery_life(battery_life),
            weight(weight)
    {}
//    virtual ~Notebook();
    virtual void print() const;

private:
    float display;
    float battery_life;
    float weight;
};

class PS: public Server, public Notebook{
public:
    PS(std::string name, float ram, std::string video_card,
       float display, float battery_life, float weight,

       int cores, int channel_number, std::string features,

       bool internet_access, std::string server_name, std::string os_name):

            Notebook(name, ram, video_card, display, battery_life, weight),
            Server(cores, channel_number, features),
            internet_access(internet_access),
            server_name(server_name),
            os_name(os_name)
    {}
   // ~PS();
    virtual void print() const;

private:
    bool internet_access;
    std::string server_name;
    std::string os_name;
};

#endif //HOMEWORKS_COMPUTER_H
