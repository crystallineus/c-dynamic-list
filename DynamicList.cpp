// DynamicList.cpp
#include <iostream>

class DynamicList {
private:
    int* data;        // Pointer to the array
    int size;         // Current number of elements
    int capacity;     // Total capacity

public:
    DynamicList(int initialCapacity = 4) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];  // Allocate memory
    }

    ~DynamicList() {
        delete[] data;  // Free memory
    }

    void add(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void print() const {
        std::cout << "[ ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

private:
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        // Copy old data to new array
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;  // Free old memory
        data = newData;
        capacity = newCapacity;
    }
};

int main() {
    DynamicList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);  // This should trigger a resize

    list.print();  // Output: [ 10 20 30 40 50 ]

    return 0;
}
