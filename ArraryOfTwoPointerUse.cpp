#include<iostream>
#include<vector>
#include<set>
#include<cassert>
using namespace std;

//本篇主要是数组中的问题==》删除数组中的元素、重复的等等
//解题思路：涉及到移动或者交换时我们可以考虑用两个指针来解决问题，使问题时间和空间复杂度降低。

/****************************************************************************************************************************************
problem 283:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. **
将数组中的0元素移到数组的末尾
[0,2,3,0,3]==>[2,3,3,0,0]
****************************************************************************************************************************************/
void moveZeroes(int* nums, int numsSize) {
    assert(nums!=NULL);
    if(nums==NULL)
        return ;
    int i;
    int nonnumindex=0;
    
    #define SWAP(x,y) {int tmp;tmp=x;x=y;y=tmp;}
    
    for(i=0;i<numsSize;++i){
        if(nums[i]){
            SWAP(nums[i],nums[nonnumindex]);
			nonnumindex++;//利用宏的话，不要写成SWAP(nums[i],nums[nonnumindex++]);
		}
    }
}
int main()
{
	int num[]={0,12,0,3,25,45,0};
	moveZeroes(num,sizeof(num)/sizeof(num[0]));
	for(int i=0;i<7;++i)
		printf("%d ",num[i]);
	return 0;
}

/*********************************************************************************************************************************
*problem 27:removeElement
*Given an array nums and a value val, remove all instances of that value in-place and return the new length.                    ***
*Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.  ***
*The order of elements can be changed. It doesn't matter what you leave beyond the new length.
将数组中与val值相等的数字删除，并保持原来数组的相对顺序，
返回删除后元素的长度。
[3,3,2,2,3],val=3  ==>  [2]  return newlen=1
***********************************************************************************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;//用来遍历数组
        int nonvalindex=0;//记录数组中不是val的下标,不含val的区间nums[0,nonvalindex)
        for(i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[nonvalindex++]=nums[i];
            }
        }
		int newlen=nonvalindex;
		return newlen;
    }
    void print(int num){
        cout<<num<<" ";
    }
};
int main()
{
	Solution s;
	int arr[]={3,3,2,2,3,8};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
	int len=s.removeElement(vec,3);
    for(int i=0;i<len;++i){
		s.print(vec[i]);
	}
	return 0;
}

/*********************************************************************************************************************************
problem 26:removeDuplicates
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.   ***
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.  ***
在一个有序数组中，删除重复的元素使其只保留一个，返回删除后的数组长度。
[0,0,1,1,2,2,3,3,4,4,5]==>[0,1,2,3,4,5]  return newlen=6
***********************************************************************************************************************************/
class Solution {
public:
    int removeDuplicatesToOnce(vector<int>& nums) {
		int onlynumindex=0;//有效数组：vector[0,onlynumindex]
		int i;
		for(i=0;i<nums.size();++i)
		{
			if(nums[i]!=nums[onlynumindex])
				nums[++onlynumindex]=nums[i];
		}
		return onlynumindex+1;
    }
    void print(int num){
        cout<<num<<" ";
    }
};
int main()
{
	Solution s;
	int arr[]={0,0,1,1,2,2,3,3,4,4,5};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
	int len=s.removeDuplicatesToOnce(vec);
    for(int i=0;i<len;++i){
		s.print(vec[i]);
	}
	return 0;
}

/************************************************************************************************************************************
problem 80:removeDuplicates
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.  ***
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.     ***
在一个有序数组中，将数组中的重复元素删除到最多留两个
[1,1,1,2,2,3]==>[1,1,2,2,3]   return newlen=5
*************************************************************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int n = nums.size();
        int times = 1;//记录相同元素的次数
        int cnt = 0;//记录删除的次数
        for (int i=0;i<nums.size()-1;i++){
            if (nums[i] == nums[i+1]){
                times++;
            }else{
                times = 1;
            }
            if (times >= 3){
                nums.erase(nums.begin()+i);
                i--;
                cnt++;
            }
        }
        return n-cnt;
    }
};
int main()
{
	int arr[]={1,1,1,2,2,3,3,3,3,3,3,3,3,4};
	int len=sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr,arr+len);
	Solution s;
	int n=s.removeDuplicates(vec);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	return 0;
}
