#include <string>
#include <iostream>

using namespace std;

#define VOCAB 128
#define BEGIN 'A'

void printArray(size_t *v)
{
    for (size_t i = BEGIN; i < VOCAB; ++i)
    {
        cout << v[i];
    }
    cout << endl;
}

bool isIncluded(size_t *&window, size_t *&vocab)
{
    for (int i = BEGIN; i < VOCAB; i++)
    {
        if (window[i] < vocab[i])
            return false;
    }
    return true;
}

bool isValidChar(size_t *&window, size_t *&vocab, char c)
{
    return window[c] >= vocab[c];
}

size_t *charFreq(const string &str)
{
    size_t *freq = new size_t[VOCAB]{0};
    for (int c : str)
        freq[c] += 1;
    return freq;
}

bool updateSolution(size_t &bestSlow, size_t &bestFast, const size_t &slow, const size_t &fast)
{
    if (bestFast - bestSlow > fast - slow)
    {
        bestFast = fast;
        bestSlow = slow;

        return true;
    }
    return false;
}

string minWindow(string sCheck, string sVocab)
{
    if (sVocab.size() > sCheck.size())
        return "";
    if (sCheck == sVocab)
        return sCheck;
    size_t minWindowSize{sVocab.size()}, slow{0}, fast{minWindowSize - 1}, bestSlow{0}, bestFast{sCheck.size() + sVocab.size()};
    string sWindow{sCheck.substr(slow, minWindowSize)};
    auto fVocab{charFreq(sVocab)};
    auto fWindow{charFreq(sWindow)};
    bool solutionUpdated = false;
    bool wasIncluded = isIncluded(fWindow, fVocab);

    if (wasIncluded)
        solutionUpdated = updateSolution(bestSlow, bestFast, slow, fast) || solutionUpdated;

    for (fast += 1; fast < sCheck.size(); fast++)
    {
        char cAdd = sCheck[fast];

        // Skip characters that are not in the Vocab
        // cout << "slow: " << slow << ", fast: " << fast << endl;

        if (fVocab[cAdd] < 1)
        {
            continue;
        }
        // Calculate the new window
        fWindow[cAdd] += 1;
        // cout << "checking string: " << sCheck.substr(slow, fast - slow + 1) << endl;
        // printArray(fWindow);

        // Check if the new window is valid
        if (isIncluded(fWindow, fVocab))
        {
            // Found a valid window
            // string localMinima = sCheck.substr(slow, fast - slow + 1);
            // cout << "New Valid Window: " << localMinima << endl;

            solutionUpdated = updateSolution(bestSlow, bestFast, slow, fast) || solutionUpdated;
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
                if (!isValidChar(fWindow, fVocab, cRemove))
                {
                    // We found a new local minima, let's check if it's shorter than the previous local minima
                    solutionUpdated = updateSolution(bestSlow, bestFast, slow, fast) || solutionUpdated;
                    break;
                }
            }
            slow += 1;
        }
    }
    delete[] fVocab;
    delete[] fWindow;
    return (solutionUpdated) ? sCheck.substr(bestSlow, bestFast - bestSlow + 1) : "";
}
int main(int argc, char const *argv[])
{
    string s{"ADOBECODEBANC"}, t{"ABC"};

    cout << minWindow(s, t) << endl;
    return 0;
}
