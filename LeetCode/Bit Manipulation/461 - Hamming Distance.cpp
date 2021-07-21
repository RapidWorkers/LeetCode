class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming = x ^ y;
        int dist = 0;
        for(int i = 0; i < 32; i++){
            dist = dist +  hamming % 2;
            hamming = hamming >> 1;
        }
        
        return dist;
    }
};
