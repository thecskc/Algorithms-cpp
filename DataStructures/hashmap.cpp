#include <iostream>
#include<algorithm>

using namespace std;

template<class Object>
class Node {


public:

    Node() : nodeData(Object()), next(nullptr) {}

    Node(const string &key, const Object &data, Node *next = nullptr) : key(key), nodeData(data), next(next) {}

    int nodeData;
    string key;
    Node *next;
};


template<class Object>
class HashMap {
private:

    hash<string> hashFunction;
    Node<Object> **data;
    int size, numElements;


public:

    //uses the in-built hash function to generate a hash value for the data structure.
    size_t returnHash(const string &key) const {
        return hashFunction(key) % size;

    }

    //Constructor
    HashMap(int size) : size(size), data(new Node<Object> *[size]), numElements(0) {}

    //Checks that the given position is within bounds and returns the element if exists.
    Node<Object> *get(const string &key) const {

        size_t position = this->returnHash(key);


        if (!(position >= 0 && position < size)) {

            return nullptr;
        }

        if (this->data[position] == nullptr) {

            return nullptr;
        }


        Node<Object> **head = &this->data[position];

        while ((*head) != nullptr) {

            if ((*head)->key == key) {
                Node<Object> *returnValue(new Node<Object>((*head)->key, (*head)->nodeData));
                return returnValue;
            }
            head = &(*head)->next;
        }


    }

    //sets a key and a corresponding value
    bool set(const string &key, const Object &value) {

        size_t position = this->returnHash(key);


        if (!(position >= 0 && position < size)) {
            return false;
        }

        if (this->data[position] == nullptr) {

            this->data[position] = new Node<Object>(key, value);
            numElements++;
        } else {

            Node<Object> **head = &this->data[position];


            if ((*head)->key == key) {
                return false;
            }


            while ((*head)->next != nullptr) {

                if ((*head)->key == key) {

                    return false;
                }
                head = &(*head)->next;
            }


            (*head)->next = new Node<Object>(key, value);
            numElements++;


        }

        return true;
    }

    //deletes a key and it's corresponding value from the map.
    Node<Object> *deleteKey(const string &key) {

        size_t position = returnHash(key);

        if (!(position >= 0 && position < size)) {

            return nullptr;
        }


        if (this->data[position] == nullptr) {

            return nullptr;
        }


        Node<Object> **head = &this->data[position];


        if ((*head)->key == key) {

            Node<Object> *returnValue(new Node<Object>(key, (*head)->nodeData));

            Node<Object> *reassignHead = (*head)->next;
            delete *head;
            *head = reassignHead;
            numElements--;
            return returnValue;
        }

        while ((*head) != nullptr) {


            if ((*head)->next->key == key) {

                Node<Object> *returnValue(new Node<Object>(key, (*head)->next->nodeData));
                Node<Object> *temp = (*head)->next->next;
                delete (*head)->next;
                (*head)->next = temp;
                numElements--;
                return returnValue;
            }
            head = &(*head)->next;
        }


    }

    //returns the load factor
    float load() const {
        return (float) numElements / size;
    }

    //Deletes the linked list chain for each position on the array and then deletes the array itself.
    ~HashMap() {
        for (int counter = 0; counter < size; counter++) {
            Node<Object> *entry = data[counter];
            while (entry != nullptr) {
                Node<Object> *deleteNode = entry;
                entry = entry->next;
                delete deleteNode;
            }
            data[counter] = nullptr;
        }

        delete[] this->data;
        this->data = nullptr;
    }


};


int main() {


    HashMap<int> hashMap(20);

    if (hashMap.set("one", 10)) {
        cout << "Successfully entered the key one with value 10" << endl;
    }

    if (hashMap.set("one", 10)) {
        cout << "Successfully entered the key one with value 10" << endl;
    } else {
        cout << "Key one already existed in the hashmap. Duplicate keys are not allowed" << endl;
    }

    if (hashMap.set("two", 20)) {
        cout << "Successfully entered the key two with value 20" << endl;
    }

    if (hashMap.set("three", 30)) {
        cout << "Successfully entered the key three with value 30" << endl;
    }

    Node<int> *getKeyOne = hashMap.get("one");
    cout << "Obtained " << getKeyOne->key << " with value " << getKeyOne->nodeData << endl;
    delete getKeyOne;
    getKeyOne = nullptr;


    Node<int> *getKeyTwo = hashMap.get("two");
    cout << "Obtained " << getKeyTwo->key << " with value " << getKeyTwo->nodeData << endl;
    delete getKeyTwo;
    getKeyTwo = nullptr;

    Node<int> *deleteKeyTwo = hashMap.deleteKey("two");
    cout << "Deleted " << deleteKeyTwo->key << " with value " << deleteKeyTwo->nodeData << endl;
    delete deleteKeyTwo;
    deleteKeyTwo = nullptr;

    cout << "Load factor " << hashMap.load() << endl;


    return 0;
}