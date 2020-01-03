#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++){
                for(j=i+1;j<nums.size();j++){
                  if(nums[i]+nums[j]==target)
                        return {i,j};
                }
        }
        return {};
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> tmp;
        vector<int> result(2,-1);
        for(int i=0;i<nums.size();i++){
            tmp.insert(pair<int,int>(nums[i],i));
        }
        for(int i=0;i<nums.size();i++){
            if((tmp.count(target-nums[i])>0)&&(tmp[target-nums[i]]!=i)){
                result[0]=i;
                result[1]=tmp[target-nums[i]];
                break;
            }
        }
        return result;
    }
};


int main()
{
    Solution test;
    int num[4]={3,7,2,15};
    vector<int> nums(num,num+4);
    int target=9;
    cout<<test.twoSum(nums,target)[0]<<" "<<test.twoSum(nums,target)[1];
    return 0;
}
