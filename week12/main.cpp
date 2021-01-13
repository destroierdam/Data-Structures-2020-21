#include <iostream>
#include "HashMap.h"


class Person
{
    std::string name;
public:
    Person(){}
    Person(const std::string& _name):name(_name){}

    size_t hash() const {
        size_t sum = 0;
        for(size_t i = 0; i < name.size(); i++)
        {
            sum += name[i];
        }
        return sum;
    }
};

class Building: public Hashable {
    std::string name;
public:
    Building(){}
    Building(const std::string& _name):name(_name){}

    size_t hash() const override {
        size_t sum = 0;
        for(size_t i = 0; i < name.size(); i++)
        {
            sum += name[i];
        }
        return sum;
    }
};

int main()
{
    // HashMap<std::string, char> hashMap([](const std::string& s)->size_t{
    //                                                                 size_t sum = 0;
    //                                                                 for(int i = 0; i < s.size(); i++)
    //                                                                 {
    //                                                                     sum += s[i];
    //                                                                 }
    //                                                                 return sum;
    //                                                             });

    HashMap<Person, char> hm;
    return 0;
}