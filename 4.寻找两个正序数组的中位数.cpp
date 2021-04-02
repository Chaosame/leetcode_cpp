/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:

    int findK(vector<int>& nums1,vector<int>& nums2,int target){
        int n1= nums1.size();
        int n2= nums2.size();
        int k=target;
        int i=0,j=0;//双指针
        while(true){
            if(i==n1){
                return nums2[j+k-1];
            }
            if(j==n2){
                return nums1[i+k-1];
            }
            if(k==1){
                return min(nums1[i],nums2[j]);
            }
            int newi = min(i+k/2-1,n1-1);
            int newj = min(j+k/2-1,n2-1);
            int p1 = nums1[newi];
            int p2 = nums2[newj];
            if(p1<=p2){
                k-=newi-i+1;
                i=newi+1;
            }
            else{
                k-=newj-j+1;
                j=newj+1;
            }
        }
        return 0;

    }



    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //长度分别为n1 n2 中位数其实是 (n1+n2)/2 n1+n2为奇数 或者 (n1+n2)/2和(n1+n2)/2+1 的平均数
        //那么我们分别去两个数组中找 第k/2大的数  即nums1[k/2-1] a1 和 nums[k/2-1] a2
        //如果a1<a2 说明 对于a1 最多只有 k/2-1+k/2-1个数比它小 因此它最多是k-1大的数 同理 nums1[0]-nums1[k/2-2]也全部排除
        //反之同理 这样每次最多可以排除k/2个数 k可以缩小
        //当一个数组用完时 直接在另一个数组中找出第k大的数 
        //当k=1时 直接比较两个数，较大的就是目标
        int n1= nums1.size();
        int n2= nums2.size();
        int total = n1+n2;
        if ((n1+n2)%2==0) return (findK(nums1,nums2,total/2)+findK(nums1,nums2,total/2+1))/2.0;
        else return findK(nums1,nums2,(total+1)/2);

    }
};
// @lc code=end

