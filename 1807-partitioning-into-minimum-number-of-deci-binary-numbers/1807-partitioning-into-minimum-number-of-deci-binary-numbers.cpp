class Solution {
public:
    int minPartitions(string n) {
        char c = *max_element(n.begin(),n.end());
        return c-'0';
    }
};