// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (34.02%)
 * Likes:    16046
 * Dislikes: 1969
 * Total Accepted:    1.3M
 * Total Submissions: 4M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
// #include <vector>
// using namespace std;
// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        vector<int> num(len);
        mergeSort(nums1, nums2, num);
        if (len % 2)
        {
            return num[len / 2];
        }
        else
        {
            return (num[len / 2 - 1] + num[len / 2]) / 2.0;
        }
    }
    void mergeSort(const vector<int> &nums1, const vector<int> &nums2, vector<int> &num)
    {
        int i = 0, j = 0, k = 0;
        for (; i < nums1.size() && j < nums2.size(); ++k)
        {
            if (nums1[i] <= nums2[j])
            {
                num[k] = nums1[i++];
            }
            else
            {
                num[k] = nums2[j++];
            }
        }
        for (; i < nums1.size();)
        {
            num[k++] = nums1[i++];
        }
        for (; j < nums2.size();)
        {
            num[k++] = nums2[j++];
        }
        return;
    }
};
// @lc code=end
