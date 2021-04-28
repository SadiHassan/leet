/*
Amazon Online Assessment (OA) - Two Sum - Unique Pairs
Write a function that takes a list of numbers and a target number, and then returns the number of unique pairs that add up to the target number.

[X, Y] and [Y, X] are considered the same pair, and not unique.

Examples
Example 1:
Input: [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47

2 + 45 = 47

Example 2:
Input: [1, 1], target = 2
Output: 1
Explanation:
1 + 1 = 2

Example 3:
Input: [1, 5, 1, 5], target = 6
Output: 1
Explanation:
[1, 5] and [5, 1] are considered the same, therefore there is only one unique pair that adds up to 6.

Explanation
Implement a regular solution for the two sum problem, but use a set to check for and discard duplicates.
*/
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;
class Solution {
    public static int twoSumUniquePairs(List<Integer> nums, int target) {
        Set<Integer> seen = new HashSet<>();
        Set<Integer> complement = new HashSet<>();
        int ans = 0;
        for (Integer num : nums) {
          if (complement.contains(target - num) && !seen.contains(num)) {
            // (num, target - num) is a pair that sums to the target
            ans++;
            // mark num and target - num as seen so that when we see (target - num, num) it won't be counted again
            seen.add(num);
            seen.add(target - num);
          }
          complement.add(num);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = Arrays.stream(scanner.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        int target = Integer.parseInt(scanner.nextLine());
        scanner.close();
        int res = twoSumUniquePairs(nums, target);
        System.out.println(res);
    }
}