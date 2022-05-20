#include <string>

using namespace std;

#define VOCAB 26
#define A 'a'

bool isIncluded( size_t*& ref,  size_t*& window)
{
    for (int i = 0; i < VOCAB; i++)
    {
        if (window[i] > 0 && ref[i] == 0)
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
        freq[c-A] += 1;
    }
    return freq;
}

string minWindow(string s, string t)
{
    if (t.size() > s.size())
        return "";
    auto w1 = charFreq(t);
    // printArray(w1);

    size_t windowSize = t.length();
    auto window = charFreq(s.substr(0, windowSize));
    if (isEqual(window, w1))
        return true;

    size_t start{1}, end{windowSize};
    while (end < s.length())
    {
        // Caculate New Window
        char cAdd = s[end++];
        char cRemove = s[start++ - 1];
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
    /* code */
    return 0;
}
