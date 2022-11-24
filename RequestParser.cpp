#include "RequestParser.hpp"

#include "experimental/String.hpp" //wrapper std::string class enhanced

parser::RequestParser::RequestParser(){}

parser::RequestParser::RequestParser(const std::string &request)
{
    std::vector<std::string> request_splited;

    OST_String::String re(request);

    request_splited = re.split('\n');

    //parse request
    parse_method(request_splited);

    parse_route_path(request_splited);

    parse_protocol(request_splited);

    //parsing rest of request
    parse_rest_request(request_splited);
}

const std::string parser::RequestParser::request(const std::string &key)const
{
    for(const auto &e: restOfRequest){
     if(e.first == key)
        return e.second; 
    }

    return {};
}

// const std::string parser::RequestParser::toLowerCase(const std::string& upper)
// {
//     std::string convert_to_lower;

//     if(convert_to_lower.size() > 0){
//         for(int i = 0; i < convert_to_lower.size(); i++)
//             convert_to_lower[i] = std::tolower(static_cast<unsigned char>( upper.at(i) ));
//     }

//     return convert_to_lower;
// }

void parser::RequestParser::parse_method(const std::vector<std::string>& v)
{
    if(v.size() > 0){
        OST_String::String line_to_work = v[0];

        std::vector<std::string> line = line_to_work.split(' ');

        _method = line[0];
    }
}

void parser::RequestParser::parse_route_path(const std::vector<std::string>& v)
{
    if(v.size() > 0){
        OST_String::String line_to_work = v[0];
        //split by spaces
        std::vector<std::string> line = line_to_work.split(' ');
        //get element at 1 position
        OST_String::String path = line[1];
        //so now split by /
        std::vector<std::string> splited_path = path.split('/');

        //path directory by each
        for(const auto pE: splited_path) _byPath.push_back(pE);

        //absolute path directory
        _absolute_path = trimmeAtEnd(path.str(), '/');
    }
}

void parser::RequestParser::parse_protocol(const std::vector<std::string>& v)
{
    if(v.size() > 0){
        OST_String::String line_to_work = v[0];

        std::vector<std::string> line = line_to_work.split(' ');
        _proto = line[2];
    }
}

const std::string parser::RequestParser::trimmeAtStart(const std::string& no_trimmed, char character)
{
    std::string to_trimmed;
    //just trimme if no_trimme has content and contain last character
    if(no_trimmed.size() > 0 && no_trimmed[0] == character){
        //looping throught string size - 1, to avoid last character
        for(int i = 0; i < no_trimmed.size(); i++){
            // if element in index 0 is character then preceed
            if(no_trimmed[0] == character) to_trimmed[i] = no_trimmed[i+1];
        }
    }

    return to_trimmed.c_str();
}

const std::string parser::RequestParser::trimmeAtEnd(const std::string& no_trimmed, char character)
{
    std::string to_trimmed;
    //just trimme if no_trimme has content and contain last character
    if(no_trimmed.size() > 0 && no_trimmed[no_trimmed.size() - 1] == character){
        //looping throught string size - 1, to avoid last character
        for(int i = 0; i < no_trimmed.size() - 1; i++)
                to_trimmed[i] = no_trimmed[i];
    }

    return to_trimmed.c_str();
}

void parser::RequestParser::parse_rest_request(const std::vector<std::string> &v)
{
    //looping throug vector
    for(const auto& line: v){
        //getting line by line
        OST_String::String divided_line = line;
        //spliting by :
        std::vector<std::string> v_splited_by_line = divided_line.split(':');
        //populating map with first for key element and second for value
        if(v_splited_by_line[0] != "User-Agent")
            restOfRequest[v_splited_by_line[0]] = trimmeAtStart(v_splited_by_line[1], ' ');

        //if User-Agent then parse it apart, because it contains spaces, and 
        //dificult to read for trimmeAtStart() method
        if(v_splited_by_line[0] == "User-Agent"){
            std::for_each(v_splited_by_line.begin(), v_splited_by_line.end(), 
            [&](std::string str)
            {
                std::string new_str;
                if(str[0] == ' '){
                    for(int i = 0; i < str.size(); i++)
                        new_str[i] = str[i+1];
                }
                    restOfRequest["User-Agent"] = new_str.c_str();
            });
        }
    }
}

// const std::string parser::RequestParser::removeWhiteSpaces(const std::string& to_remove)
// {
//     std::string removed;
//     int index = 0;

//     for(const auto& e: to_remove){
//         if(e != ' '){
//             removed[index] = e;
//             index++;
//         }
//     }

//     return removed.c_str();
// }

const std::string parser::RequestParser::getMethod()const{ return _method; }

const std::string parser::RequestParser::getProto()const{ return _proto; }

const std::string parser::RequestParser::getAbsolutePath()const{ return _absolute_path; }

const std::vector<std::string> parser::RequestParser::getPathByEach(){ return _byPath; }