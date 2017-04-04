class Solution {
public:
    vector<int> vec;
    Solution(vector<int> nums) {
        vec = nums;
    }
    
    int pick(int target) {
        int cur = -1, num_ocur = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == target){
                num_ocur++;
                if(cur == -1) cur = i;
                else{
                    if(rand() % num_ocur == 0) cur = i;
                }
            }
        }
        return cur;
    }
};