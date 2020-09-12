/*
* Create a hash function, such that our hash table has ‘N’ number of buckets.
* To insert a node into the hash table, we need to find the hash index for the given key. And it
* could be calculated using the hash function. Use open addressing for collision.
* In linear probing, we linearly probe for next slot.
* If slot hash(x) % S is full, then we try (hash(x) + 1) % S
* If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
* If (hash(x) + 2) % S is also full, then we try (hash(x) + 3) % S 
*/

#include <bits/stdc++.h>
using namespace std;

class Hash
{

    int BUCKET;
    int *table;

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
    this->table = new int[BUCKET];
    for (int i = 0; i < BUCKET; i++)
    {
        table[i] = NULL;
    }
}
void Hash::insert_item(int key)
{
    int b{0}, index;
    while (1)
    {
        key = key + b;
        index = hash_function(key);
        if (table[index] != NULL)
        {
            ++b;
        }
        else
        {
            table[index] = key;
            break;
        }
    }
}
void Hash::delete_item(int key)
{
    int b{0}, index;
    while (1)
    {
        key = key + b;
        index = hash_function(key);
        if (table[index] == NULL)
        {
            cout << "Value not present in table" << endl;
            break;
        }
        else
        {
            if (table[index] == key)
            {
                table[index] = -1;
            }
            else
            {
                ++b;
            }
        }
    }
}
int Hash::hash_function(int key)
{
    return (key % BUCKET);
}
void Hash::display()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i << ": " << table[i] << endl;
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
