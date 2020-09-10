#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i=0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]\n";
    return os;
}

int main() {
    vector<int> v {10, 1, 4};

    // Accessing elements
    cout << v[0] << ' ' << v.at(1) << ' ' << v[2] << ' '<< v.front() << endl;

    // Changing the values
    v[0] = 100;
    v.at(1) = 200;

    // Capacity
    cout << "Size: " << v.size() << endl;
    cout << "Max size: " << v.max_size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Check empty: " << v.empty() << endl;
    cout << "Reserve capacity of 100: " << endl;
    v.reserve(100);
    cout << "Capacity: " << v.capacity() << endl;

    // Show values
    cout << v << endl;
    // Modify
    v.pop_back();
    cout << "Popped ";
    cout << v << endl;
    v.push_back(300);
    cout << "Pushed 300 ";
    cout << v << endl;
    v.insert(v.begin()+1, 2, 5);
    cout << "Insert at second place ";
    cout << v << endl;
    v.erase(v.begin(), v.begin()+2);
    cout << "Erase first 2 elements ";

    // Show values
    cout << v << endl;

    return 0;
}
