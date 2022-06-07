#include <iostream>

using namespace std;

class Solution {
public:
    void set(uint32_t& n, int pos){
        n|= (1<<pos);
    }
       
    uint32_t reverseBits(uint32_t n) {
        uint32_t r;
        int pos = 31;
        
        while (n > 0){
            // get last of bit of n
            auto lb = n & 1;
            // if last bit is 1, set it to next bit in r
            if (lb==1)
                set(r, pos);
            // shift n
            n = n >> 1;
            pos -=1;
        }        
        return r;
    }
};

int main(int argc, char* argv[]){
    Solution solution;
    cout <<  solution.reverseBits(0b00000010100101000001111010011100) << endl;
    return 1;
}