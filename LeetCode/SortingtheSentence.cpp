#include <iostream>
#include <sstream>
#include "vector"
#include "algorithm"

class Solution {
public:
    static std::string sortSentence(std::string s) {

        std::vector<std::string> words;
        std::stringstream stringstream(s);
        std::string tmp;
        std::string res;

        while (getline(stringstream, tmp, ' ')) {
            words.push_back(tmp);
        }
        std::sort(words.begin(),words.end(), [] (std::string a, std::string b)
        {
            return a[a.size()-1] < b[b.size()-1];
        });

        for(int i = 0; i < words.size(); ++i)
        {
            res += words[i].substr(0, words[i].size() -1);
            if(i != words.size()-1)
                res += " ";
        }
        return res;
    }
};

int main() {
    std::cout << Solution::sortSentence("Myself2 Me1 I4 and3") << std::endl;
    return 0;
}
