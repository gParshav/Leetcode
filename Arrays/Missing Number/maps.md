Map - key:value

1. std::map
 - Ordered: Elements are stored in a balanced binary tree (typically a red-black tree), which keeps them in sorted order based on the keys.
 - Time Complexity: Logarithmic time complexity for insert, delete, and find operations.
 - Use Case: When you need the elements to be in a specific order, or when you frequently need to traverse the elements in a sorted manner.
 
2. std::unordered_map
 - Unordered: Elements are stored in a hash table, and thus, they are not in any specific order.
 - Time Complexity: Average constant time complexity for insert, delete, and find operations, but it can degrade to linear time in  the worst case due to hash collisions.
 - Use Case: When you do not need any specific order for elements and want faster average time complexity for operations.
 
 
Default Values in a map:

 - For built-in numeric types like int, float, double, the default-constructed value is zero.
 - For std::string, the default-constructed value is an empty string.
 - For user-defined types, the default-constructed value is determined by the default constructor of that type.