#include <iostream>
using namespace std;

template <typename T>

class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;
	
    void resize() {
        currentCapacity *= 2;
        T* newData = new T[currentCapacity];
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
public:
    SimpleVector(int capacity = 10):currentSize(0),currentCapacity(capacity) {
        data = new T[currentCapacity];
        
    }

    ~SimpleVector() {
        delete[] data;
    }
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            resize();
        }
        data[currentSize++] = value;
    }
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }
    int size() {
        return currentSize;

    }
    int capacity() {
        return currentCapacity;
    }
};


