# String Class
The String class is a basic implementation of a string container in C++. It provides functionalities for managing and manipulating strings.
# Features
- Dynamic memory allocation: The String class dynamically allocates memory to store the characters of the string.
- Construction and assignment: The class supports default construction, construction from C-style strings, copy construction, and move construction.
- Concatenation: The class supports concatenation using the += operator.
- Accessing elements: The class allows accessing individual characters of the string using the [] operator.
- Iteration: The class provides begin() and end() functions to iterate over the characters of the string.
- Capacity management: The class allows checking the size, length, and capacity of the string, as well as reserving a specific capacity.
- Modifying the string: The class provides functions for appending, inserting, erasing, and clearing the string.
- Substring extraction: The class supports extracting substrings based on start positions.
- Comparison: The class supports comparison operations between strings using the == operator.
- Input/output stream support: The class overloads the << operator to enable outputting the string to an output stream.
# Usage
To use the String class, include the "String.hpp" header file in your C++ program. You can then create instances of the String class and use its member functions and operators to manipulate strings.
# Limitations
- The String class is a basic implementation and may not provide the same level of functionality and performance as the standard library's string class (std::string).
- Error handling is limited. The class throws an exception (std::out_of_range) in some cases but does not provide comprehensive error handling mechanisms.
- The implementation may not be optimized for performance and efficiency in all scenarios.
