/*
* Array data structure by both c implementation and
* array container class in c++ and methods of array
* container class
*/

#include <iostream>
#include <array>

using namespace std;

void default_array_implementaion() {
    // Initialize array with size and elements
    int arr1[5] {4, 6, 7, 8, 19};
    // Initialize array without size and with elements
    char arr2[] {'a', 's', 'd', 'f', 'g', 'h', 'j'};
    // Initialize array with size and without elements
    float arr3[3];
    // Initialize char array from string
    char arr4[] {"hello"};
    // Initialize array from heap memory
    int *arr5 = new int[2];

    // Set values for empty arrays
    arr3[0] = 1.1; arr3[1] = 2.2; arr3[2] = 3.3;
    arr5[0] = 3;
    arr5[1] = 7;

    // Change the value of arrays
    arr1[3] = 200;

    // Accessing the values of array
    cout << arr1[3] << " " << arr2[2] << " " << arr3[1] << " " << arr4[0] << " " << arr5[0] << endl;

    // Delete the memory used in heap
    delete [] arr5;
}

void container_array_implementaion() {
    // Initialize array with size and elements
    array<int, 5> arr1 {4, 6, 7, 8, 19};
    // Initialize array with size and without elements
    array<float, 3> arr2;
    // Initialize char array from string
    array<char, 6> arr3 {"hello"};

    // Set values for empty arrays
    arr2[0] = 1.1; arr2[1] = 2.2; arr2[2] = 3.3;

    // Change the value of arrays
    arr1[3] = 200;

    // Accessing the values of array
    cout << arr1[2] << " " << arr2[2] << " " << arr3[3] << endl;

    // Iterators methods
    auto be = arr1.begin();
    auto en = arr2.end(); // Takes a garbage value

    auto rbe = arr1.rbegin();
    auto ren = arr2.end(); // Takes a garbage value

    //cout << "Without * begin, end, rbegin, rend : " << be << en << rbe << ren << endl;
    cout << "begin and end: " << *be << ' ' << *en << endl;
    cout << "rbegin and rend: " << *rbe << ' ' << *ren << endl;
    cout << "begin: " << be << endl;
    cout << "end: " << en << endl;

}

int main() {
    /*
    // Default array implementation
    cout << "Default array implementation" << endl;
    cout << endl;
    default_array_implementaion();
    cout << endl;
    */
    // Container class array implementation
    cout << "Container class array implementation" << endl;
    cout << endl;
    container_array_implementaion();

    return 0;
}
