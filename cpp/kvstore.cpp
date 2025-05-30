#include <bits/stdc++.h>
using namespace std;


int main() {
    // Example usage of the unordered_map to store key-value pairs
    unordered_map<string, string> kvstore;

    // Inserting key-value pairs
    kvstore["name"] = "Alice";
    kvstore["age"] = "30";
    kvstore["city"] = "New York";

    // Accessing values using keys
    cout << "Name: " << kvstore["name"] << endl;
    cout << "Age: " << kvstore["age"] << endl;
    cout << "City: " << kvstore["city"] << endl;

    // Checking if a key exists
    if (kvstore.find("country") == kvstore.end()) {
        cout << "Key 'country' does not exist." << endl;
    }

    return 0;
}

