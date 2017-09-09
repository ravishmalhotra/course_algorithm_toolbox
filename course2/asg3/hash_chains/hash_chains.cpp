#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<vector<string>> table; //The main change is to add a 2-d table.The table has <bucket_count> rows.
    //Based on the calculate hash value of an element, a particular row index is assigned. The element is then
    //added at the end of the particular row.


    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), table(bucket_count) {
    ;}

    ;
    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = (table[static_cast<int>(query.ind)].size()) - 1; i >= 0; --i) //Check goes through all the elements of the stated bucket row index
                if (hash_func(table[query.ind][i]) == query.ind)
                    std::cout << table[query.ind][i] << " ";
            std::cout << "\n";
        } else {
            int row_ind=hash_func(query.s); //First find row index using the hash function and then do the actions below
            vector<string>::iterator it = std::find(table[row_ind].begin(), table[row_ind].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != table[row_ind].end());
            else if (query.type == "add") {
                if (it == table[row_ind].end())
                    table[row_ind].push_back(query.s);
            } else if (query.type == "del") {
                if (it != table[row_ind].end())
                    table[row_ind].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
