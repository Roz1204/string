#include "string.hpp"

template<typename CharT>
void testString()
{
    String str;
    String str1 = str;
    str += 'H';
    str += 'e';
    str += 'l';
    str += 'l';
    str += 'o';

    std::cout << str << std::endl;

    str1 += ' ';
    str1 += 'w';
    str1 += 'o';
    str1 += 'r';
    str1 += 'l';
    str1 += 'd';

    str += str1;

    str = str1;

    if(str == str) {
        std::cout << "operator== function works correctly" << std::endl;
    } else {
        std::cout << "operator== function is not working correctly" << std::endl;
    }

    if(str.at(0) == ' ')
    {
        std::cout << "at function works correctly" << std::endl;
    } else {
        std::cout << "at function is not working correctly" << std::endl;
    }

    if(str.size() == 6)
    {
        std::cout << "size function works correctly" << std::endl;
    } else {
        std::cout << "size function is not working correctly" << std::endl;
    }

    if(str.length() == 6)
    {
        std::cout << "length function works correctly" << std::endl;
    } else {
        std::cout << "length function is not working correctly" << std::endl;
    }

    if(str.max_size() == std::numeric_limits<size_t>::max())
    {
        std::cout << "max_size function works correctly" << std::endl;
    } else {
        std::cout << "max_size function is not working correctly" << std::endl;
    }

    str.reserve(12);

    if(str.capacity() == 32)
    {
        std::cout << "reserve and capacity functions works correctly" << std::endl;
    } else {
        std::cout << "reserve and capacity functions is not working correctly" << std::endl;
    }

    str.clear();
    if(str.size() == 0)
    {
        std::cout << "clear function works correctly" << std::endl;
    } else {
        std::cout << "clear function is not working correctly" << std::endl;
    }

    String str3;
    str3 += 'H';
    str3 += 'e';
    str3 += 'l';
    str3 += 'l';
    str3 += 'o';
    str.swap(str3);
    if(str.size() == 5) {
        std::cout << "swap function works correctly" << std::endl;
    } else {
        std::cout << "swap function is not working correctly" << std::endl;
    }

    str3.push_back(' ');
    str3.push_back('B');
    str3.push_back('o');
    str3.push_back('b');
    if(str3.length() == 9) {
        std::cout << "push_back function works correctly" << std::endl;
    } else {
        std::cout << "push_back function is not working correctly" << std::endl;
    }

    str3.pop_back();
    str3.pop_back();
    str3.pop_back();
    str3.pop_back();
    if(str3.length() == 5) {
        std::cout << "pop_back function works correctly" << std::endl;
    } else {
        std::cout << "pop_back function is not working correctly" << std::endl;
    }

    if(str.front() == 'H') {
        std::cout << "front function works correctly" << std::endl;
    } else {
        std::cout << "front function is not working correctly" << std::endl;
    }

    if(str.back() == 'o') {
        std::cout << "back function works correctly" << std::endl;
    } else {
        std::cout << "back function is not working correctly" << std::endl;
    }

    if(*(str.begin()) == 'H') {
        std::cout << "begin function works correctly" << std::endl;
    } else {
        std::cout << "begin function is not working correctly" << std::endl;
    }

    if(*(str.end()) == 'o') {
        std::cout << "end function works correctly" << std::endl;
    } else {
        std::cout << "end function is not working correctly" << std::endl;
    }

    if(!(str.empty())) {
        std::cout << "empty function works correctly" << std::endl;
    } else {
        std::cout << "empty function is not working correctly" << std::endl;
    }

    str.assign(str3);
    str.assign("barev", 4);
    if(str.size() == 4) {
        std::cout << "assign function works correctly" << std::endl;
    } else {
        std::cout << "assign function is not working correctly" << std::endl;
    }

    str3.erase(str3.begin(), str3.begin() + 1);
    if(str3.size() == 5) {
        std::cout << "erase function works correctly" << std::endl;
    } else {
        std::cout << "erase function is not working correctly" << std::endl;
    }

    String str4 = str.substr(2);
    if(str4.size() == 2) {
        std::cout << "substr function works correctly" << std::endl;
    } else {
        std::cout << "substr function is not working correctly" << std::endl;
    }

    char s[] = "hello world";
    if(str.copy(s, 2, 2) == 2) {
        std::cout << "copy function works correctly" << std::endl;
    } else {
        std::cout << "copy function is not working correctly" << std::endl;
    }

    String s1 = "Hello";
    String s2 = "World";
    s1.append(s2);
    if(s1.size() == 10) {
        std::cout << "append function works correctly" << std::endl;
    } else {
        std::cout << "append function is not working correctly" << std::endl;
    }

    s1.insert(0, "World ");
    if (s1.size() == 16) {
        std::cout << "insert function works correctly" << std::endl;
    } else {
        std::cout << "insert function is not working correctly" << std::endl;
    }
}

int main()
{
    testString<char>();
    return 0;
}
