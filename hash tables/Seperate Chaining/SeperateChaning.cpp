/*
* Create a hash function, such that our hash table has ‘N’ number of buckets.
* To insert a node into the hash table, we need to find the hash index for the given key. And it
* could be calculated using the hash function. Use seperate chaining for collision.
* Example: hashIndex = key % noOfBuckets
*/

#include <bits/stdc++.h>
using namespace std;

class Hash
{

    int BUCKET;
    list<int> *table;

public:
    Hash(int s);
    // Insert a item to table
    void insert_item(int x);
    // Delete a item from table
    void delete_item(int x);
    // Hash function for hashing the key
    int hash_function(int x);
    // Display the contents of the table
    void display();
};

Hash::Hash(int s)
{
    this->BUCKET = s;
    this->table = new list<int>[BUCKET];
}
void Hash::insert_item(int key)
{
    int index = hash_function(key);
    table[index].push_back(key);
}
void Hash::delete_item(int key)
{
    int index = hash_function(key);
    auto it = find(table[index].begin(), table[index].end(), key);
    if (it == table[index].end())
    {
        cout << "Element is not present" << endl;
    }
    else
    {
        table[index].erase(it);
    }
}
int Hash::hash_function(int key)
{
    return (key % BUCKET);
}
void Hash::display()
{
    for (int i = 0; i < BUCKET - 1; i++)
    {
        cout << i << ": ";
        for (auto j = table[i].begin(); j != table[i].end(); j++)
        {
            cout << " --> " << *j;
        }
        cout << endl;
    }
}

int main()
{
    int N, v, c;
    cout << "Enter the total number of elements: ";
    cin >> N;

    Hash h(7);

    while (1)
    {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Delete element at a key" << endl;
        cout << "3.Display table" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter element to be inserted: ";
            cin >> v;
            h.insert_item(v);
            break;
        case 2:
            cout << "Enter key of the element to be deleted: ";
            cin >> v;
            h.delete_item(v);
            break;
        case 3:
            h.display();
            break;
        case 4:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }

    return 0;
}
