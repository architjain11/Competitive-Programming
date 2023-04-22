class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int target) {
        return !(target>jug1Capacity+jug2Capacity) && (target%__gcd(jug1Capacity, jug2Capacity)==0); 
    }
};