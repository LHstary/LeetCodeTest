#include<iostream>
#include<vector>
#include<set>
#include<cassert>
using namespace std;

//��ƪ��Ҫ�������е�����==��ɾ�������е�Ԫ�ء��ظ��ĵȵ�
//����˼·���漰���ƶ����߽���ʱ���ǿ��Կ���������ָ����������⣬ʹ����ʱ��Ϳռ临�ӶȽ��͡�

/****************************************************************************************************************************************
problem 283:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. **
�������е�0Ԫ���Ƶ������ĩβ
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
			nonnumindex++;//���ú�Ļ�����Ҫд��SWAP(nums[i],nums[nonnumindex++]);
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
����������valֵ��ȵ�����ɾ����������ԭ����������˳��
����ɾ����Ԫ�صĳ��ȡ�
[3,3,2,2,3],val=3  ==>  [2]  return newlen=1
***********************************************************************************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;//������������
        int nonvalindex=0;//��¼�����в���val���±�,����val������nums[0,nonvalindex)
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
��һ�����������У�ɾ���ظ���Ԫ��ʹ��ֻ����һ��������ɾ��������鳤�ȡ�
[0,0,1,1,2,2,3,3,4,4,5]==>[0,1,2,3,4,5]  return newlen=6
***********************************************************************************************************************************/
class Solution {
public:
    int removeDuplicatesToOnce(vector<int>& nums) {
		int onlynumindex=0;//��Ч���飺vector[0,onlynumindex]
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
��һ�����������У��������е��ظ�Ԫ��ɾ�������������
[1,1,1,2,2,3]==>[1,1,2,2,3]   return newlen=5
*************************************************************************************************************************************/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int n = nums.size();
        int times = 1;//��¼��ͬԪ�صĴ���
        int cnt = 0;//��¼ɾ���Ĵ���
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
