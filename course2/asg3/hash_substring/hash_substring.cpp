#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::pow;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

//Function for calculating base hash value of the pattern and the first text substring extending from t[0] to t[pattern_length]

long long calculate_hash (const string &s) {

   long long multiplier=52;
   long long hash_value=0;
    for (size_t i=0; i<s.size(); i++) {
    hash_value=hash_value+static_cast<long long>(s[i])*pow(multiplier,i);
    }
    return hash_value;



}
std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    std::vector<int> possible_match;
    long long multiplier=52;

    //Checking base case match
    long long hash_sub=calculate_hash(s);
    long long hash_text_next=calculate_hash(t.substr(0,s.size()));

     if ( hash_text_next == hash_sub)
     possible_match.push_back(0);


    for (size_t i = 0; i + s.size() <= t.size(); ++i) {

        //New hash value=(Old hash value-hash(first character of old substring))/128+new character*128^(size of pattern-1)
        hash_text_next=(hash_text_next-static_cast<long long>(t[i]))/multiplier + static_cast<long long>(t[i+s.size()])*pow(multiplier,s.size()-1);

        if ( hash_text_next == hash_sub)
            possible_match.push_back(i+1);
    }

    for (size_t i = 0; i<possible_match.size(); ++i) {
        //if ((t.substr(possible_match[i], s.size())) == s)
        if(t.compare(possible_match[i], s.size(),s )==0){
        ans.push_back(possible_match[i]);
        }

    }


    return ans;


}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
