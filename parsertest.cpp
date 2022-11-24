#include <iostream>
#include <string>

#include "test/test.hpp" //for testing

#include "RequestParser.hpp" //parser class

template<typename T> void testing_1(T &object)
{  
   //most important part of the request
   EQ_TEST<std::string> (object.getMethod(),                 "GET",                     "method");
   EQ_TEST<std::string> (object.getAbsolutePath(),           "/hello/index.html",       "absolute path");
   EQ_TEST<std::string> (object.getProto(),                  "HTTP/1.1",                "protocol");
   EQ_TEST<std::string> (object.getPathByEach()[1],          "hello",                   "first path");
   EQ_TEST<std::string> (object.getPathByEach()[2],          "index.html",              "second path");

   //rest of the request
   EQ_TEST<std::string> (object.request("Host"),             "www.tutorialspoint.com",   "host");
   EQ_TEST<std::string> (object.request("Accept-Language"),  "en-us",                    "language");
   EQ_TEST<std::string> (object.request("Accept-Encoding"),  "gzip, deflate",            "encoding");
   EQ_TEST<std::string> (object.request("User-Agent"),       "Mozilla/4.0 (compatible; MSIE5.01; Windows NT)", "user agent");
}   






template<typename T> void testing_2(T &object)
{  
   //most important part of the request
   EQ_TEST<std::string> (object.getMethod(),                 "POST",                    "method");
   EQ_TEST<std::string> (object.getAbsolutePath(),           "/cgi-bin/process.cgi",    "absolute path");
   EQ_TEST<std::string> (object.getProto(),                  "HTTP/1.1",                "protocol");
   EQ_TEST<std::string> (object.getPathByEach()[1],          "cgi-bin",                 "first path");
   EQ_TEST<std::string> (object.getPathByEach()[2],          "process.cgi",             "second path");

   //rest of the request
   EQ_TEST<std::string> (object.request("Host"),             "www.tutorialspoint.com",   "host");
   EQ_TEST<std::string> (object.request("Accept-Language"),  "en-us",                    "language");
   EQ_TEST<std::string> (object.request("Accept-Encoding"),  "gzip, deflate",            "encoding");
   EQ_TEST<std::string> (object.request("User-Agent"),       "Mozilla/4.0 (compatible; MSIE5.01; Windows NT)", "user agent");
   EQ_TEST<std::string> (object.request("Connection"),       "Keep-Alive", "connection");
   EQ_TEST<std::string> (object.request("Content-Type"),     "application/x-www-form-urlencoded", "content type");
   EQ_TEST<std::string> (object.request("Content-Length"),   "length",                    "content Length");
} 





int main(int argc, char **argv)
{
    std::string test_request_1("GET /hello/index.html HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive");
    std::string test_request_2("POST /cgi-bin/process.cgi HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)\nHost: www.tutorialspoint.com\nContent-Type: application/x-www-form-urlencoded\nContent-Length: length\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive");
    
    parser::RequestParser parser_test_1(test_request_1);
    parser::RequestParser parser_test_2(test_request_2);

    testing_1(parser_test_1);
    testing_2(parser_test_2);

    return 0;
}
