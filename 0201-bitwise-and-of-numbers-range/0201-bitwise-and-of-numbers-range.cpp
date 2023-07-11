class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right)
            return left;
        int temp{0};
        for(int i=0; i<31; i++, left>>=1, right>>=1, temp<<=1) {
            if ((left&1) == (right&1))
                temp |= (left&1);
            else
                temp = 0;
        }
        int res{0};
        for(int i=0; i<31; i++) {
            res |= (temp&1);
            temp >>= 1;
            res <<= 1;
        }

        return res;
    }
};