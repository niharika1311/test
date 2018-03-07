#include<iostream>
#include<cassert>
#include<initializer_list>

using namespace std;

class IntArray {
    int length;
    int *data;
    public:
    IntArray():length(0), data(nullptr) {
    }
    IntArray(int l):length(l) {
        data = new int[length];
    }
    IntArray(const initializer_list<int> &list):
        IntArray(list.size()) {
        int count = 0;
        for(auto &element: list) {
            data[count] = element;
            ++count;
        }
    }
    ~IntArray() {
        delete[] data;
    }
    int getSize() {
        return length;
    }
    int& operator[](int index) {
        assert(index >= 0 && index < length);
        return data[index];
    }
};

int main() {
    IntArray obj{1, 2, 3, 4, 5};
    cout << obj.getSize() << endl;
    for(int element = 0; element < obj.getSize(); element++)
        cout << obj[element] << endl;
    return 0;
}
