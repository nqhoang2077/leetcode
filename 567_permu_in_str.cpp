#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

#define VOCAB 26

void printArray(size_t* v){
    for(size_t i = 0; i < VOCAB; ++i){
        cout << v[i];
    }
    cout << endl;
}

bool isEqual( size_t*& v1,  size_t*& v2)
{
    for (int i = 0; i < VOCAB; i++)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

size_t* charFreq(const string &str)
{
    size_t* freq = new size_t[VOCAB]{0};
    // cout << str << endl;

    for (int c : str)
    {
        freq[c-'a'] += 1;
    }
    return freq;
}

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    auto w1 = charFreq(s1);
    // printArray(w1);

    size_t windowSize = s1.length();
    auto window = charFreq(s2.substr(0, windowSize));
    if (isEqual(window, w1))
        return true;

    size_t start{1}, end{windowSize};
    while (end < s2.length())
    {
        // Caculate New Window
        char cAdd = s2[end++];
        char cRemove = s2[start++ - 1];
        window[cAdd-'a']+=1;
        window[cRemove-'a']-=1;
        // cout << s2.substr(start, end) << ":"; 
        // printArray(window);

        // Compare
        // If Match, return True
        if (isEqual(window, w1))
            return true;
        // Else, move Start to new Location {++}
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s1{"ab"}, s2{"bfbac"};
    // cout << s2 << endl;
    // printArray(charFreq(s2));
    cout << checkInclusion(s1, s2);
    return 0;
}
