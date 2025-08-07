#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::string frequencySort(const std::string& s) {
    std::unordered_map<char, int> freq;

    // Count the frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Create a vector of pairs (char, freq) for sorting
    std::vector<std::pair<char, int>> chars(freq.begin(), freq.end());

    // Sort by frequency in descending order
    std::sort(chars.begin(), chars.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Build the result string
    std::string result;
    for (const auto& [ch, count] : chars) {
        result.append(count, ch);
    }

    return result;
}

    string frequencySort2(string s) {
        unordered_map<char, int > mapp ;

        for(char a :s ){
            mapp[a]++;
        }

        vector<pair<char,int>>v(mapp.begin(),mapp.end());
        sort(v.begin(),v.end(), [](const auto& a, const auto& b){
            return a.second > b.second ;
        });

        s = "";
        for(const auto& [ch, count] : v){
            s.append(count, ch);
        }
        return s;
    }


int main (){

    
}