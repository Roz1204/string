#pragma once
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <iostream>

class String
{
private:
    char* m_str;
    int m_size = 0;
    int m_capacity = 32;
    void Allocator();
    void Resize(int newCapacity);

public:
    String();
    String(const char* str);

    String(std::nullptr_t) = delete;

    String(String&& other);
    String(const String& other);

    ~String();

    String& operator+=(const String& str );
    constexpr String& operator+=(char ch );
    String& operator=( const String& str );
    constexpr char& operator[](int pos) const;
    friend std::ostream& operator<<(std::ostream& os,const String& str)  
	{
       	for(int i = 0; i < str.m_size; ++i) 
		{
           	os << str.m_str[i];
       	}
       	return os;
    }

    constexpr String& assign(const String& str );
    constexpr String& assign(const char* str, int size);

    constexpr char& at(int pos) const;
    
    constexpr const char& front() const;
    constexpr const char& back() const;

    constexpr char* begin() noexcept;
    constexpr char* end() noexcept;

    constexpr bool empty() const noexcept;

    constexpr int size() const noexcept;
    constexpr int length() const noexcept;
    constexpr int max_size() const noexcept;
    constexpr void reserve(int new_cap);
    constexpr int capacity() const noexcept;

    constexpr void clear() noexcept;

    void swap(String& other) noexcept;

    static const int npos = -1;
    
    constexpr void push_back(char ch);
    constexpr void pop_back();
    
    constexpr char* erase(char*& position );
    constexpr char* erase(char* first, char* last );

    String substr(int start = 0) const;

    int copy(char* dest, int count, int pos = 0) const;
    
    constexpr String& insert(int index, const String& str );

    constexpr String& append( const String& str );
    
};

void String::Allocator()
{
    m_str = new char[m_capacity];
}

void String::Resize(int newCapacity)
{
    char* newStr = new char[newCapacity];
    for (int i = 0; i < m_size; ++i)
    {
        newStr[i] = m_str[i];
    }
    newStr[m_size] = '\0'; 
    delete[] m_str;
    m_str = newStr;
    m_capacity = newCapacity;
}

String::String() 
{
    Allocator();
    m_str[m_size] = '\0';

}

String::String(const char* str)
{
    m_size = 0;
    while (str[m_size] != '\0')
    {
        ++m_size;
    }

    if (m_size >= m_capacity)
    {
        m_capacity = m_size + 1;
    }

    m_str = new char[m_capacity];

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str[i];
    }

    m_str[m_size] = '\0';
}

String::String(String&& other) : m_str{other.m_str}, m_size{other.m_size}, m_capacity{other.m_capacity}
{
    other.m_str = nullptr;
    other.m_size = 0;
    other.m_capacity  = 0;
}

String::String(const String& other) 
{ 
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_str = new char[m_capacity];
    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = other.m_str[i];
    }
    m_str[m_size] = '\0';

}

String::~String()
{
    delete[] m_str;
    m_str = nullptr;
}

String& String::operator+=(const String& str )
{
    int size = m_size + str.m_size + 1;
    char* newStr = new char[size];
    int i = 0;
    for( ; i < m_size; ++i)
    {
        newStr[i] = m_str[i];
    }
    for(int j = 0; j < str.m_size; ++j)
    {
        newStr[i++] = str.m_str[j];
    }
    newStr[i] = '\0';
    delete[] m_str;

    m_str = newStr;
    m_size = m_size + str.m_size;
    return *this;
}

constexpr String& String::operator+=(char ch )
{
    m_str[m_size++] = ch;
    m_str[m_size] = '\0';
    return *this;
}

String& String::operator=( const String& str )
{
    delete[] m_str;
    m_str = nullptr;

    m_size = 0;
    while (str[m_size] != '\0')
    {
        ++m_size;
    }

    if (m_size >= m_capacity)
    {
        m_capacity = m_size + 1; 
    }

    m_str = new char[m_capacity];

    for (int i = 0; i < m_size; ++i)
    {
        m_str[i] = str[i];
    }

    m_str[m_size] = '\0';

    return *this;
}

constexpr bool operator==(const String& lhs, const String& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }

    for (int i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}

constexpr char& String::operator[](int pos) const
{
    return m_str[pos];
}

constexpr String& String::assign(const char* str, int size)
{
    m_size = 0;
    for(int i = 0; i < size; ++i)
    {
        push_back(str[i]);
    }
    return *this;
}

constexpr String& String::assign(const String& str)
{
    if (this != &str) 
    {
        m_size = 0;
        for (int i = 0; i < str.m_size; ++i) 
        {
            push_back(str.m_str[i]);
        }
    }
    return *this;
}

constexpr char& String::at(int pos) const
{
    if(pos < 0 || pos >= m_size)
    {
        throw std::out_of_range("invalid index");
    }
    return m_str[pos];
}

constexpr const char& String::front() const
{
    return at(0);
}

constexpr const char& String::back() const
{
    return at(m_size - 1);
}

constexpr char* String::begin() noexcept
{
    return m_str;
}

constexpr char* String::end() noexcept
{
    return m_str + m_size - 1;
}

constexpr bool String::empty() const noexcept
{
    if(m_size == 0)
    {
        return true;
    }
    return false;
}

constexpr int String::size() const noexcept
{
    return m_size;
}

constexpr int String::length() const noexcept
{
    return m_size;
}

constexpr int String::max_size() const noexcept
{
    return std::numeric_limits<size_t>::max();
}

constexpr void String::reserve(int new_cap)
{
    if(new_cap <= m_capacity)
    {
        return;
    }

    m_capacity = new_cap;
    char* buf = new char[new_cap];
    for(int i = 0; i < m_size; ++i)
    {
        buf[i] = m_str[i];
    }
    buf[size()] = '\0';
    delete[] m_str;
    m_str = buf;
    buf = nullptr;
}

constexpr int String::capacity() const noexcept
{
    return m_capacity;
}

constexpr void String::clear() noexcept
{
    m_size = 0;
}

void String::swap(String& other) noexcept
{
    String tmp;
    tmp = *this;
    *this = other;
    other = tmp;
}

constexpr void String::push_back(char ch)
{
    if (m_size + 1 >= m_capacity)
    {
        int newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        Resize(newCapacity);
    }
    m_str[m_size++] = ch;
    m_str[m_size] = '\0';
}

constexpr void String::pop_back()
{
    if(m_size != 0)
    {
        m_str[m_size - 1] = '\0';
        --m_size;
    }
}

constexpr char* String::erase(char*& position )
{
    if (position >= m_str && position < m_str + m_size)
    {
        for (char* p = position; p < m_str + m_size - 1; ++p)
        {
            *p = *(p + 1);
        }
        --m_size;
        m_str[m_size] = '\0';
    }
    return position;
}

constexpr char* String::erase(char* first, char* last ) 
{
    if (first >= m_str && first < m_str + m_size && last >= first && last < m_str + m_size)
    {
        char* dest = const_cast<char*>(first);
        char* src = const_cast<char*>(last);

        while (src < m_str + m_size)
        {
            *dest = *src;
            ++dest;
            ++src;
        }

        m_size -= (last - first);
        m_str[m_size] = '\0';
    }
    return const_cast<char*>(first);
}

String String::substr(int start) const
{
    if (start < 0 || start >= m_size)
    {
        throw std::out_of_range("Invalid start position for substr");
    }

    int length = m_size - start;
    String result;
    result.reserve(length + 1);

    for (int i = start; i < m_size; ++i)
    {
        result.push_back(m_str[i]);
    }

    return result;
}

int String::copy(char* dest, int count, int pos) const
{
    if (pos < 0 || pos >= m_size)
    {
        return -1; 
    }

    int copyCount = std::min(count, m_size - pos);

    for (int i = 0; i < copyCount; ++i)
    {
        dest[i] = m_str[pos + i];
    }

    return copyCount;
}

constexpr String& String::insert(int index, const String& str)
{
    if (index > m_size || index > m_size)
    {
        throw std::out_of_range("Invalid index for insert");
    }

    int newSize = m_size + str.m_size;
    if (newSize >= m_capacity)
    {
        int newCapacity = std::max(newSize + 1, m_capacity * 2);
        Resize(newCapacity);
    }

    for (int i = m_size; i >= index; --i)
    {
        m_str[i + str.m_size] = m_str[i];
    }

    for (int i = 0; i < str.m_size; ++i)
    {
        m_str[index + i] = str.m_str[i];
    }

    m_size = newSize;
    m_str[m_size] = '\0';

    return *this;
}

constexpr String& String::append(const String& str)
{
    int newSize = m_size + str.m_size;
    if (newSize >= m_capacity)
    {
        int newCapacity = std::max(newSize, m_capacity * 2);
        Resize(newCapacity);
    }

    for (int i = 0; i < str.m_size; ++i)
    {
        m_str[m_size + i] = str.m_str[i];
    }

    m_size = newSize;
    m_str[m_size] = '\0';

    return *this;
}