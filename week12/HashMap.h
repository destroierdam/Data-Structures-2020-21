#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <type_traits>
#include <concepts>

// template<typename Key, typename Value>
// struct Pair
// {
//     Key key;
//     Value value;
// };

template<typename Key, typename Value>
struct Node
{
    // Pair<Key, Value> pair;
    Key key;
    Value value;
    Node *next;
};


class Hashable {
public:
    virtual size_t hash() const = 0;
};


template<typename T>
concept is_hashable = std::derived_from<T, Hashable>;


template<is_hashable Key, typename Value>
class HashMap
{
private:
    std::vector<Node<Key, Value>*> table;
    std::function<size_t(const Key&)> hashFunction;

public:
    HashMap(size_t capacity = 1024):table(capacity){}
    HashMap(std::function<size_t(const Key&)> _hashFunction, size_t capacity = 1024):table(capacity, nullptr) {
        this->hashFunction = _hashFunction;
    }


    // void add(...) {
    //     table[....hash() % table.size()] = ...
    // }
};





