# Array Solutions

## 1. Best Time To Buy And Sell Stock

### Brute Force Solution:

1. Initialize maxProfit = 0
2. Use two nested loops to compare each element with every other element after it
3. Calculate profit = prices[j] - prices[i]
4. Update maxProfit if profit > maxProfit
5. Return maxProfit

Time Complexity: O(n^2)
Space Complexity: O(1)

### Optimal Solution:

1. Initialize minPrice = INT_MAX and maxProfit = 0
2. Iterate through the vector once
3. Update minPrice if current price is lower
4. Calculate potential profit = current price - minPrice
5. Update maxProfit if potential profit > maxProfit
6. Return maxProfit

Time Complexity: O(n)
Space Complexity: O(1)

## 2. Chocolate Distribution Problem

### Optimal Solution:

1. Sort the vector of chocolate packets
2. Initialize minDiff = INT_MAX
3. Use a sliding window of size m to find the minimum difference
4. Iterate through the vector, updating minDiff if (arr[i+m-1] - arr[i]) < minDiff
5. Return minDiff

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)

## 3. Container With Most Water

### Brute Force Solution:

1. Initialize maxArea = 0
2. Use two nested loops to compare each pair of lines
3. Calculate area = min(height[i], height[j]) \* (j - i)
4. Update maxArea if area > maxArea
5. Return maxArea

Time Complexity: O(n^2)
Space Complexity: O(1)

### Optimal Solution (Two Pointer Approach):

1. Initialize left = 0, right = n-1, maxArea = 0
2. While left < right:
   a. Calculate area = min(height[left], height[right]) \* (right - left)
   b. Update maxArea if area > maxArea
   c. Move the pointer with the smaller height inward
3. Return maxArea

Time Complexity: O(n)
Space Complexity: O(1)

## 4. Find All Duplicates In An Array

### Optimal Solution:

1. Initialize an empty result vector
2. Iterate through the vector
3. For each num, mark nums[abs(num) - 1] as negative
4. If nums[abs(num) - 1] is already negative, add abs(num) to result
5. Return result

Time Complexity: O(n)
Space Complexity: O(1) (excluding the space for the output)

## 5. Find Duplicates Number

### Optimal Solution (Floyd's Cycle Detection):

1. Initialize slow = nums[0], fast = nums[0]
2. Do {
   a. slow = nums[slow]
   b. fast = nums[nums[fast]]
   } while (slow != fast)
3. Reset slow = nums[0]
4. While (slow != fast) {
   a. slow = nums[slow]
   b. fast = nums[fast]
   }
5. Return slow

Time Complexity: O(n)
Space Complexity: O(1)

## 6. Four Sums

### Optimal Solution:

1. Sort the vector
2. Use two outer loops to fix two numbers
3. Use two pointers for the remaining two numbers
4. Skip duplicates to avoid duplicate quadruplets
5. Adjust pointers based on sum comparison with target

Time Complexity: O(n^3)
Space Complexity: O(1) (excluding the space for the output)

## 7. Majority Element

### Better Solution (Unordered Map):

1. Create an unordered_map to store element frequencies
2. Iterate through the vector, updating frequencies
3. Return the element with frequency > n/2

Time Complexity: O(n)
Space Complexity: O(n)

### Optimal Solution (Moore's Voting Algorithm):

1. Initialize count = 0, candidate = 0
2. For each element in the vector:
   a. If count == 0, set candidate = current element
   b. If current element == candidate, count++
   c. Else count--
3. Return candidate

Time Complexity: O(n)
Space Complexity: O(1)

## 8. Merge Sorted Arrays

### Optimal Solution:

1. Start from the end of both vectors
2. Compare elements and place the larger one at the end of nums1
3. Move backwards in the vectors
4. If elements remain in nums2, copy them to nums1

Time Complexity: O(m + n)
Space Complexity: O(1)

## 9. Move Zeros

### Optimal Solution:

1. Initialize nonZeroIndex = 0
2. Iterate through the vector
3. If current element != 0, swap it with nums[nonZeroIndex] and increment nonZeroIndex
4. After the loop, all elements from nonZeroIndex to end will be zero

Time Complexity: O(n)
Space Complexity: O(1)

## 10. Remove Duplicates From Sorted Array

### Optimal Solution:

1. If vector is empty, return 0
2. Initialize uniqueIndex = 1
3. Iterate from second element to end
4. If current element != previous element, set nums[uniqueIndex] = current element and increment uniqueIndex
5. Return uniqueIndex

Time Complexity: O(n)
Space Complexity: O(1)

## 11. Set Matrix Zeroes

### Better Solution:

1. Use two separate vectors to mark which rows and columns should be zero
2. Iterate through the matrix to mark these vectors
3. Use these vectors to set zeros in the matrix

Time Complexity: O(m\*n)
Space Complexity: O(m + n)

### Optimal Solution:

1. Use first row and column as markers
2. Use two variables to check if first row and column should be zero
3. Iterate through the matrix to mark first row and column
4. Use these markers to set zeros in the matrix
5. Set first row and column to zero if needed

Time Complexity: O(m\*n)
Space Complexity: O(1)

## 12. Sort Colors

### Optimal Solution (Dutch National Flag Algorithm):

1. Initialize low = 0, mid = 0, high = n-1
2. While mid <= high:
   a. If nums[mid] == 0, swap with nums[low] and increment low and mid
   b. If nums[mid] == 1, increment mid
   c. If nums[mid] == 2, swap with nums[high] and decrement high

Time Complexity: O(n)
Space Complexity: O(1)

## 13. Subarray Sum Equals K

### Optimal Solution (Unordered Map):

1. Initialize sum = 0, count = 0, and an unordered_map
2. Insert (0, 1) into the map
3. Iterate through the vector:
   a. Add current element to sum
   b. If (sum - k) exists in map, add its count to result
   c. Increment count of sum in map
4. Return count

Time Complexity: O(n)
Space Complexity: O(n)

## 14. Subarray Sums Divisible By K

### Optimal Solution (Unordered Map):

1. Initialize sum = 0, count = 0, and an unordered_map
2. Insert (0, 1) into the map
3. Iterate through the vector:
   a. Add current element to sum
   b. Calculate remainder = (sum % k + k) % k
   c. If remainder exists in map, add its count to result
   d. Increment count of remainder in map
4. Return count

Time Complexity: O(n)
Space Complexity: O(min(n, k))

## 15. Three Sums

### Optimal Solution:

1. Sort the vector
2. Iterate through the vector
3. For each element, use two pointers to find pairs that sum to its negation
4. Skip duplicates to avoid duplicate triplets
5. Adjust pointers based on sum comparison

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding the space for the output)

## 16. Two Sums

### Brute Force Solution:

1. Use two nested loops to check all pairs of numbers
2. If a pair sums to the target, return their indices

Time Complexity: O(n^2)
Space Complexity: O(1)

### Optimal Solution (Unordered Map):

1. Create an unordered_map
2. Iterate through the vector
3. If (target - current number) is in the map, return its index and current index
4. Otherwise, add current number and its index to the map

Time Complexity: O(n)
Space Complexity: O(n)

## 17. Best Time To Buy And Sell Stock II

### Optimal Solution:

1. Initialize profit = 0
2. Iterate through the vector from index 1 to end
3. If current price > previous price, add the difference to profit
4. Return profit

Time Complexity: O(n)
Space Complexity: O(1)

## 18. Maximum Points You can Obtain from Cards

### Optimal Solution (Sliding Window):

1. Calculate initial sum of last k cards
2. Initialize maxPoints with this sum
3. Use a sliding window to consider taking cards from the beginning
4. Update maxPoints in each iteration
5. Return maxPoints

Time Complexity: O(k)
Space Complexity: O(1)

## 19. Word Search

### Optimal Solution (DFS):

1. Iterate through the board to find the first character
2. For each matching first character, perform DFS
3. In DFS, mark visited cells and explore in four directions
4. If all characters are found, return true
5. Backtrack by unmarking cells if word is not found

Time Complexity: O(m*n*4^L), where L is the length of the word
Space Complexity: O(L) for recursion stack

## 20. Jump Game

### Optimal Solution (Greedy):

1. Initialize maxReach = 0
2. Iterate through the vector
3. If current index > maxReach, return false
4. Update maxReach = max(maxReach, i + nums[i])
5. If maxReach >= last index, return true

Time Complexity: O(n)
Space Complexity: O(1)

## 21. All Unique Permutations of an Array

### Optimal Solution (Backtracking):

1. Sort the vector to handle duplicates
2. Use a recursive function for backtracking
3. In each recursion, try all unused numbers
4. Skip consecutive duplicates to avoid duplicate permutations
5. Add the permutation to result when it's complete

Time Complexity: O(n!)
Space Complexity: O(n) for recursion stack

## 22. Game of Life

### Optimal Solution (In-place):

1. Define bit representations for state changes
2. Iterate through the board
3. Count live neighbors for each cell
4. Update cell states using bit manipulation
5. Make a second pass to update final states

Time Complexity: O(m\*n)
Space Complexity: O(1)

## 23. Longest Repeating Character Replacement

### Optimal Solution (Sliding Window):

1. Initialize left = 0, maxCount = 0, result = 0
2. Use a vector<int> to count characters
3. Expand the window to the right
4. Update maxCount if needed
5. If window size - maxCount > k, shrink the window
6. Update result with the current window size

Time Complexity: O(n)
Space Complexity: O(1)

## 24. Reverse Pairs

### Optimal Solution (Merge Sort):

1. Implement merge sort
2. During merge, count reverse pairs
3. Use two pointers to efficiently count pairs
4. Merge the subvectors

Time Complexity: O(n log n)
Space Complexity: O(n)

## 25. Max value of Equation

### Optimal Solution (Deque):

1. Initialize a deque and result = INT_MIN
2. Iterate through the points
3. Remove outdated points from the front of deque
4. Calculate current max value and update result
5. Remove smaller values from the back of deque
6. Add current point to deque

Time Complexity: O(n)
Space Complexity: O(n)

## 26. Insert Delete GetRandom O(1) - Duplicates allowed

### Optimal Solution (Vector + Unordered Map):

1. Use a vector to store values
2. Use an unordered_map to store value-to-indices mapping
3. For insert, add to vector and update unordered_map
4. For remove, swap with last element, update unordered_map, and remove last
5. For getRandom, generate random index and return value

Time Complexity: O(1) average for all operations
Space Complexity: O(n)

## 27. Largest Rectangle in Histogram

### Optimal Solution (Stack):

1. Initialize vectors for previous and next smaller elements
2. Initialize result = 0
3. Calculate previous smaller elements:
   - Use a stack to keep track of indices
   - Iterate through heights from left to right
   - Update previous smaller for current element
   - Push current index to stack
4. Calculate next smaller elements:
   - Use a stack to keep track of indices
   - Iterate through heights from right to left
   - Update next smaller for current element
   - Push current index to stack
5. Calculate maximum area:
   - Iterate through heights
   - Calculate width between previous and next smaller
   - Calculate area and update result if necessary
6. Return result

Time Complexity: O(n)
Space Complexity: O(n)
