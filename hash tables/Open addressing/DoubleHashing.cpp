/*
* Create a hash function, such that our hash table has ‘N’ number of buckets.
* To insert a node into the hash table, we need to find the hash index for the given key. And it
* could be calculated using the hash function. Use open addressing for collision.
* In quadratic probing, we probe i^2th slot for next slot.
* let hash(x) be the slot index computed using hash function.  
* If slot hash(x) % S is full, then we try (hash(x) + 1*hash2(x)) % S
* If (hash(x) + 1*hash2(x)) % S is also full, then we try (hash(x) + 2*hash2(x)) % S
* If (hash(x) + 2*hash2(x)) % S is also full, then we try (hash(x) + 3*hash2(x)) % S
*/

#include <bits/stdc++.h>
using namespace std;

class Hash
{

    int BUCKET;
    int *table;
    int PRIME;

public:
    Hash(int s);
    // Insert a item to table
    void insert_item(int x);
    // Delete a item from table
    void delete_item(int x);
    // Hash function for hashing the key
    int hash_function(int x);
    // Second hash function
    int second_hash_function(int x);
    // Search a value in table
    void search_value(int x);
    // Display the contents of the table
    void display();
};

Hash::Hash(int s)
{
    this->BUCKET = s;
    this->table = new int[BUCKET];
    for (int i = 0; i < BUCKET; i++)
    {
        table[i] = -100;
    }
    // To initialize prime number less than 2*BUCKET
}
void Hash::insert_item(int key)
{
    int b{0}, index, value, initial_index;
    value = key;
    initial_index = hash_function(key);
    index = initial_index;
    while (1)
    {
        // cout << "B: " << b << endl;
        // cout << "key: " << key << endl;
        // cout << "index: " << index << endl;
        // cout << endl;
        if (table[index] != -100 && table[index] != -1)
        {
            ++b;
        }
        else
        {
            table[index] = value;
            break;
        }
        key = initial_index + (b * b);
        index = hash_function(key);
    }
}
void Hash::delete_item(int key)
{
    int b{0}, index, value, initial_index;
    value = key;
    initial_index = hash_function(key);
    index = initial_index;
    while (1)
    {
        if (table[index] == -100)
        {
            cout << "Value not present in table" << endl;
            break;
        }
        else
        {
            if (table[index] == value)
            {
                table[index] = -1;
                break;
            }
            else
            {
                ++b;
            }
        }
        key = initial_index + (b * b);
        index = hash_function(key);
    }
}
int Hash::hash_function(int key)
{
    return (key % BUCKET);
}
int Hash::second_hash_function(int key)
{
    return (PRIME - (key % PRIME));
}
void Hash::search_value(int key)
{
    int b{0}, index, value, initial_index;
    value = key;
    initial_index = hash_function(key);
    index = initial_index;
    while (1)
    {
        if (table[index] == -100)
        {
            cout << "Value not present in table" << endl;
            break;
        }
        else
        {
            if (table[index] == value)
            {
                cout << "Value present in table" << endl;
                break;
            }
            else
            {
                ++b;
            }
        }
        key = initial_index + (b * b);
        index = hash_function(key);
    }
}
void Hash::display()
{
    cout << "NOTE: -1 indicates value is deleted and -100 indicates it is empty" << endl;
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i << ": " << table[i] << endl;
    }
}

int main()
{
    int N, v, c;
    cout << "Enter the table size: ";
    cin >> N;

    Hash h(7);

    while (1)
    {
        cout << "--------------------------------" << endl;
        cout << "1.Insert element into the table" << endl;
        cout << "2.Delete element at a key" << endl;
        cout << "3.Search element in the table" << endl;
        cout << "4.Display table" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        cout << "--------------------------------" << endl;
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
            cout << "Enter key to search: ";
            cin >> v;
            h.search_value(v);
            break;
        case 4:
            h.display();
            break;
        case 5:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }

    return 0;
}
