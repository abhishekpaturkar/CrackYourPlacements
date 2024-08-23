# String Solutions

## 1. Integer To Roman

### Brute Force Solution:

1. Create a map of integer values to Roman numerals
2. Iterate from largest to smallest integer value
3. While the input number is greater than or equal to the current value, append the corresponding Roman numeral and subtract the value from the input

Time Complexity: O(1)
Space Complexity: O(1)

### Optimal Solution:

1. Create two arrays: one for integer values and one for corresponding Roman numerals
2. Iterate through the arrays
3. While the input number is greater than or equal to the current value, append the corresponding Roman numeral and subtract the value from the input

Time Complexity: O(1)
Space Complexity: O(1)

## 2. Longest Common Prefix

### Brute Force Solution:

1. Consider the first string as the prefix
2. Iterate through remaining strings
3. While the current string doesn't start with the prefix, remove the last character from the prefix

Time Complexity: O(S), where S is the sum of all characters in all strings
Space Complexity: O(1)

### Optimal Solution:

1. Sort the array of strings
2. Compare the first and last string
3. Find the common prefix between them

Time Complexity: O(NlogN + S), where N is the number of strings and S is the length of the longest string
Space Complexity: O(1)

## 3. Valid Parentheses

### Optimal Solution:

1. Initialize an empty stack
2. Iterate through the string
3. If opening bracket, push to stack
4. If closing bracket, check if stack is empty or top doesn't match; if so, return false
5. Pop the top of the stack
6. After iteration, return true if stack is empty

Time Complexity: O(n)
Space Complexity: O(n)

## 4. Print all the Duplicate Characters in a String

### Brute Force Solution:

1. Use two nested loops to compare each character with every other character
2. Print duplicates

Time Complexity: O(n^2)
Space Complexity: O(1)

### Better Solution:

1. Sort the string
2. Iterate through the sorted string and compare adjacent characters

Time Complexity: O(nlogn)
Space Complexity: O(1)

### Optimal Solution:

1. Use a hash map to store character counts
2. Iterate through the map and print characters with count > 1

Time Complexity: O(n)
Space Complexity: O(k), where k is the size of the character set

## 5. Find the Index of the First Occurrence of a Character in a String

### Brute Force Solution:

1. Iterate through the string
2. Return index when character is found

Time Complexity: O(n)
Space Complexity: O(1)

### Optimal Solution:

1. Use the built-in string.indexOf() method

Time Complexity: O(n)
Space Complexity: O(1)

## 6. Valid Palindrome II

### Optimal Solution:

1. Use two pointers, left and right
2. While left < right, compare characters
3. If different, check if string is palindrome after removing either left or right character
4. If both substrings are not palindromes, return false

Time Complexity: O(n)
Space Complexity: O(1)

## 7. Basic Calculator II

### Optimal Solution:

1. Use a stack to store numbers
2. Iterate through the string
3. If digit, update current number
4. If operator or end of string, process the previous operator
5. Push result to stack
6. Sum up all numbers in stack

Time Complexity: O(n)
Space Complexity: O(n)

## 8. Generate Parentheses

### Optimal Solution (Backtracking):

1. Use recursion with parameters: current string, open count, close count, and max pairs
2. If open < max, add opening parenthesis and recurse
3. If close < open, add closing parenthesis and recurse
4. If length of current string equals 2 \* max, add to result

Time Complexity: O(4^n / sqrt(n))
Space Complexity: O(n)

## 9. Simplify Path

### Optimal Solution:

1. Split the path by '/'
2. Use a stack to store directories
3. Ignore '.' and empty strings
4. Pop from stack for '..'
5. Push valid directory names
6. Join stack elements with '/' and add leading '/'

Time Complexity: O(n)
Space Complexity: O(n)

## 10. Reverse Words In A String

### Brute Force Solution:

1. Split string into words
2. Reverse the array of words
3. Join the words back into a string

Time Complexity: O(n)
Space Complexity: O(n)

### Optimal Solution (in-place):

1. Reverse the entire string
2. Reverse each word individually

Time Complexity: O(n)
Space Complexity: O(1)

## 11. Group Anagrams

### Optimal Solution:

1. Create a hash map with sorted string as key and list of anagrams as value
2. Iterate through strings, sort each string and add to map
3. Return values of the map

Time Complexity: O(NKlogK), where N is the number of strings and K is the maximum length of a string
Space Complexity: O(NK)

## 12. Print Anagrams Together

### Optimal Solution:

1. Create a hash map with sorted string as key and list of original strings as value
2. Iterate through strings, sort each string and add to map
3. Print values of the map

Time Complexity: O(NKlogK), where N is the number of strings and K is the maximum length of a string
Space Complexity: O(NK)

## 13. Rabin-Karp Algorithm for Pattern Searching

### Optimal Solution:

1. Calculate hash of pattern and first window of text
2. Slide the window one by one
3. Calculate hash of current window
4. If hashes match, check characters one by one
5. If all characters match, print the index

Time Complexity: O(n+m)
Space Complexity: O(1)

## 14. Smallest window in a string containing all the characters of another string

### Optimal Solution:

1. Create a frequency map for characters in string p
2. Initialize two pointers, left and right, at the start of string s
3. Move the right pointer to include characters in the window
4. When all characters of p are included, move the left pointer to minimize the window
5. Keep track of the minimum window size and starting index
6. Return the smallest window or "-1" if no valid window exists

Time Complexity: O(n), where n is the length of string s
Space Complexity: O(1), as we use a fixed-size array for character frequency

## 15. Valid Number

### Optimal Solution:

1. Initialize variables to track decimal point usage and number presence
2. Handle leading sign (+ or -)
3. Iterate through the string:
   a. Check for invalid characters (non-digit, non-decimal point, non-exponent)
   b. Handle decimal point (ensure only one is used)
   c. Handle exponent 'e' or 'E':
   - Ensure a number has been seen before the exponent
   - Validate the integer after the exponent
     d. Track number presence
4. Return true if a valid number was found, false otherwise

Time Complexity: O(n), where n is the length of the input string
Space Complexity: O(1), as we use only a constant amount of extra space

## 16. Word Wrap

### Optimal Solution:

Steps for Word Wrap problem:

1. Initialize variables and memoization array
2. Define recursive function with memoization:
   a. Handle base case (end of array)
   b. Check memoized result
   c. Iterate through words, calculating line length
   d. Handle last line case
   e. Calculate cost for non-last lines
   f. Update minimum cost
   g. Memoize and return result
3. Call recursive function with initial parameters

Time Complexity: O(n^2), where n is the number of words
Space Complexity: O(n) for memoization array and recursion stack
