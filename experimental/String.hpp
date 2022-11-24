#ifndef __STRING_O__
#define __STRING_O__

#include <string>
#include <vector>
#include <iostream>

namespace OST_String
{
    class String
    {
        public:
            //parametized constructor
            String(const std::string &);
            
            //default constructor
            String() = default;

            //copy constructor
            String(const String &);

            //move constructor to implement
            String(String &&);

            //assign operator String&&
            void operator = (String &&);

            //assign operator String&
            void operator = (String &);

            //assign operator std::string &
            void operator = (const std::string &);
            
            //greater then operator
            friend bool operator >(const String &, const String &);

            //less then operator
            friend bool operator <(const String &, const String &);

            //operator << std::ostream &
            friend std::ostream& operator << (std::ostream &, const String &);

            //operator << String & << String &
            friend String& operator << (String &, const String &);

            //operator << String & << std::string &
            friend String& operator << (String &, const std::string &);

            //operator >> String &
            friend String& operator >> (String &, String &);

             //method to append std::string
            void append(const std::string &);

            //method to insert string
            void insert(const std::string &);

            //method to insert String class instance
            void insert(String &);
            
            //method to substract string content
            std::string str() const;

            //consult size or lenght of content
            std::size_t size();

            //method to split to std::vector<std::string> string content by delimiter
            std::vector<std::string> split(char c = ' ');

            //method to split to std::vector<String> string content by delimiter
            std::vector<OST_String::String> splitOwnType(char c = ' ');

            //method to verify if exist in content
            bool contains(const std::string &);

            //method to verify if content starts with specific string
            bool startsWith(const std::string &);

            //method to verify if content ends with specific string
            bool endsWith(const std::string &);

        private:
            std::string content;
    };
}
#endif