class Solution {
public:
    int bitwiseComplement(int n) {
        int power = 0;
        for (int i = 0; i < 32 && !power; i++){
            if (1 << i > n) power = i;
        }
        return (1 << power) - n - 1;
    }
};
