class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 = 0;
        int change10 = 0;
        for(int i:bills){
            if(i==5){
                change5++;
            }else if(i==10){
                change5--;
                change10++;
            }else{
                if(change10==0){
                    change5-=3;
                }else{
                    change10--;
                    change5--;
                }
            }
            if(change5<0) 
                return false;
        }
        return true;
    }
};