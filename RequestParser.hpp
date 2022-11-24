#ifndef __REQUEST_PARSER__
#define __REQUEST_PARSER__

#include <string>
#include <vector>
#include <map>

namespace parser
{
    class RequestParser
    {
        public:
            //public members

                RequestParser(const std::string &);
                RequestParser();

                //getters
                const std::string getMethod() const;
                const std::string getProto() const;
                const std::string getAbsolutePath() const;
                const std::vector<std::string> getPathByEach();
                const std::string request(const std::string &) const;

        private:
        //private methods

            // const std::string toLowerCase(const std::string &);
            void parse_method(const std::vector<std::string> &);
            void parse_route_path(const std::vector<std::string> &);
            void parse_protocol(const std::vector<std::string> &);

            const std::string trimmeAtStart(const std::string &, char);
            const std::string trimmeAtEnd(const std::string &, char);

            // const std::string removeWhiteSpaces(const std::string &);

            void parse_rest_request(const std::vector<std::string> &);

        private:
            //private members

            std::string _request;
            std::string _method;
            std::string _proto;
            std::string _absolute_path;

            std::vector<std::string> _byPath;
            std::map<std::string, std::string> restOfRequest;
    };
}
#endif