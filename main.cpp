
/*
Name: Pranav Santosh Chaudhari
PRN: 202501100017
Subject: Data Structures - IA 3
Scenario: Student Marks
Hash Method: Mid-Square
Collision Handling: Separate Chaining
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int M = 23;

class HashTable {
private:
    vector<int> table[M];

    int hashFunction(int key) {
        string square = to_string(key * key);

        while (square.length() < 4) {
            square = "0" + square;
        }

        int middle = stoi(square.substr(1, 2));
        return middle % M;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);

        cout << "Key: " << key
             << " | Index: " << index << endl;
    }

    void display() {
        cout << "\nFinal Hash Table\n";

        for (int i = 0; i < M; i++) {
            cout << i << " : ";

            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (int j = 0; j < table[i].size(); j++) {
                    cout << table[i][j];

                    if (j < table[i].size() - 1) {
                        cout << " -> ";
                    }
                }
            }

            cout << endl;
        }
    }
};

int main() {
    int values[20] = {
        17, 30, 43, 56, 69,
        82, 95, 8, 21, 34,
        47, 60, 73, 86, 99,
        12, 25, 38, 51, 64
    };

    HashTable h;

    cout << "Personalized Student Marks Dataset\n";

    for (int i = 0; i < 20; i++) {
        h.insert(values[i]);
    }

    h.display();

    return 0;
}
