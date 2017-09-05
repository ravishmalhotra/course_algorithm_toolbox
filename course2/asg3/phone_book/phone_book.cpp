#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::string;
using std::vector;
using std::cin;
using std::pow;

struct Query {
    string type, name;
    int number;
};

struct Contact {
   string name;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Contact> contacts(pow(10,7));
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            //bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            contacts[queries[i].number].name=queries[i].name;

            // otherwise, just add it

        } else if (queries[i].type == "del") {
            contacts[queries[i].number].name="";

        } else {
            string response;

            if (contacts[queries[i].number].name.empty())
            response = "not found";

            else
            response=contacts[queries[i].number].name;

            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
