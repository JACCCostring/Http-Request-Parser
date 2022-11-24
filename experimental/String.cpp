#include "String.hpp"

OST_String::String::String(const std::string& new_content){
    content = new_content;
}

OST_String::String::String(const String &copyStr)
{
    content = copyStr.content;
}

void OST_String::String::operator = (String&& moveStr)
{
    content = moveStr.content;
    moveStr.content.clear();
}

void OST_String::String::operator = (String& moveStr)
{
    content = moveStr.content;
}

void OST_String::String::operator = (const std::string& assignStr){
    content = assignStr;
}

bool OST_String::operator > (const String &rhs, const String &lhs){
    return rhs.content > lhs.content;
}

bool OST_String::operator < (const String &rhs, const String &lhs){
    return rhs.content < lhs.content;
}

std::ostream& OST_String::operator << (std::ostream &out, const String &c)
{
    out << c.content;
    return out;
}

OST_String::String& OST_String::operator << (String &out, const String &c)
{
    out.content += c.content;
    return out;
}

OST_String::String& OST_String::operator << (String &out, const std::string &c)
{
    out.content += c;
    return out;
}

OST_String::String& OST_String::operator >> (String &out, String &c)
{
    c.content = out.content;
    return c;
}

OST_String::String::String(String &&moveStr)
{
    content = moveStr.content;
    moveStr.content.clear();
}

void OST_String::String::append(const std::string& appContent){
    content += appContent;
}

void OST_String::String::insert(const std::string& appContent){
    content = appContent;
}

void OST_String::String::insert(String& appInstanceContent){
    content = appInstanceContent.str();
}

std::string OST_String::String::str() const { return content; }

std::size_t OST_String::String::size(){ return content.size(); }

std::vector<std::string> OST_String::String::split(char limiter)
{
    std::vector<std::string> contentStr;
    std::string contentPlus;

    if(! content.empty()){ //if string is not empty
        content += limiter; //adding limiter at end of string

    for(const auto &c: content){
        if(c == limiter){
            contentStr.push_back(contentPlus); //pushing content to vector
            contentPlus.clear(); //clear content to start again from 0
        }

        if(c != limiter) { 
            contentPlus += c; //adding character to content
        }
    }
    }

    return contentStr;
}

std::vector<OST_String::String> OST_String::String::splitOwnType(char limiter)
{
    std::vector<String> contentStr;
    std::string contentPlus;

    if(! content.empty()){ //if string is not empty
        content += limiter; //adding limiter at end of string

    for(const auto &c: content){
        if(c == limiter){
            contentStr.push_back(contentPlus); //pushing content to vector
            contentPlus.clear(); //clear content to start again from 0
        }

        if(c != limiter) { 
            contentPlus += c; //adding character to content
        }
    }
    }

    return contentStr;
}

bool OST_String::String::contains(const std::string &string)
{
    
    std::string cont;

    if(content.find(string)!= std::string::npos)
    cont = content.substr(content.find(string), string.size());

    if(cont == string) return true;
    
    return false;
}

bool OST_String::String::startsWith(const std::string &string){

    std::string cont;

    if(content.find(string)!= std::string::npos)
    cont = content.substr(0, string.size());

    if(cont == string) return true;
    
    return false;
}

bool OST_String::String::endsWith(const std::string &string)
{

    std::string cont;

    if(content.find(string)!= std::string::npos)
    cont = content.substr(content.find(string), string.size());
    
    if(cont == string) return true;
    
    return false;
}