#include <string>
#include <iostream>

using namespace std;

#define VOCAB 256

void printArray(size_t *v)
{
    for (size_t i = 0; i < VOCAB; ++i)
    {
        cout << v[i];
    }
    cout << endl;
}

bool isIncluded(size_t *&window, size_t *&vocab)
{
    for (int i = 0; i < VOCAB; i++)
    {
        if (window[i] < vocab[i])
            return false;
    }
    return true;
}

size_t *charFreq(const string &str)
{
    size_t *freq = new size_t[VOCAB]{0};
    for (int c : str)
        freq[c] += 1;
    return freq;
}

string minWindow(string sCheck, string sVocab)
{
    if (sVocab.size() > sCheck.size())
        return "";
    if (sCheck == sVocab)
        return sCheck;
    size_t minWindowSize{sVocab.size()}, slow{0}, fast{minWindowSize - 1};
    string defaultResult{sCheck + sVocab};
    string result{defaultResult}, sWindow{sCheck.substr(slow, minWindowSize)};
    auto fVocab{charFreq(sVocab)};
    auto fWindow{charFreq(sWindow)};
    // cout << "Vocab: " <<endl;
    // printArray(fVocab);

    if (isIncluded(fWindow, fVocab))
        result = sWindow;

    for (fast+=1; fast < sCheck.size(); fast++)
    {
        char cAdd = sCheck[fast];

        // Skip characters that are not in the Vocab
        // cout << "slow: " << slow << ", fast: " << fast << endl;
        // cout << "checking string: " << sCheck.substr(slow, fast - slow + 1) << endl;
        if (fVocab[cAdd] < 1)
            continue;
        // Calculate the new window
        fWindow[cAdd] += 1;

        // Check if the new window is valid
        if (isIncluded(fWindow, fVocab))
        {
            // Found a valid window
            string localMinima = sCheck.substr(slow, fast - slow + 1);
            cout << "New Valid Window: " << localMinima << endl;

            result = (localMinima.length() < result.length()) ? localMinima : result;
            // Now the new valid window is found, try minimize it
            for (slow; slow <= fast; slow++)
            {
                char cRemove = sCheck[slow];
                // Skip characters that are not in the Vocab
                if (fVocab[cRemove] < 1)
                    continue;

                // cout << "Removing: " << cRemove << "->";
                // Calculate the new window
                // cout << "\nOld Window: " << endl;
                // printArray(fWindow);
                fWindow[cRemove] -= 1;
                // cout << "New Window: " << endl;
                // printArray(fWindow);

                // The new window becomes invalid, break out of the loop
                if (!isIncluded(fWindow, fVocab))
                {
                    // cout << "Can't" << endl;
                    // We found a new local minima, let's check if it's shorter than the previous local minima
                    localMinima = sCheck.substr(slow, fast - slow + 1);
                    // cout << "Local minima: " << localMinima << endl;
                    result = (localMinima.length() < result.length()) ? localMinima : result;
                    fWindow[cRemove] += 1;
                    break;
                } 
            }
            slow += 1;
        }
    }
    // cout << "Result: " << result << endl;
    result = (result == defaultResult) ? "" : result;
    return result;
}

int main(int argc, char const *argv[])
{
    string s{"ab"}, t{"a"};

    cout << minWindow(s, t) << endl;
    return 0;
}
