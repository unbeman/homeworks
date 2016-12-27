//
// Created by a.kukuev on 06.12.16.
//

#ifndef HOMEWORKS_ANIMAL_H
#define HOMEWORKS_ANIMAL_H

class Animal{

};

class Mammal: public virtual Animal{

};

class Winged: public virtual Animal{

};

class Bat: public Mammal, public Winged{

};

class Man: public virtual Animal{

};

class Batman: public Bat, public Man{

};
#endif //HOMEWORKS_ANIMAL_H
