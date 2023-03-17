#ifndef __CPP_CONFIG_HPP_
#define __CPP_CONFIG_HPP_
#include <string>
#include <vector>
#include <map>


namespace cpp_config_tool {
    class Class {
      public:
        Class(){
        };
        ~Class(){
            this->db.clear();
        };
        std::string get (const std::string name){
            return this->db[name];
        };
        std::string get (const std::string name, std::string def){
            if(this->db[name] == "")
               return def;
            return this->db[name];
        };
        int getInt (const std::string name){
            if(this->db[name] == "")
               return 0;
            return std::stoi(this->db[name]);
        };
        int getInt (const std::string name, const int def){
            if(this->db[name] == "")
               return def;
            return std::stoi(this->db[name]);
        };
        void set (
          const std::string name,
          const std::string val
        ){
            this->db[name] = val;
        };
      private:
        std::map<std::string, std::string> db;
    };
};
namespace cpp_config_sec {
    cpp_config_tool::Class *conf = new cpp_config_tool::Class();
};

namespace cppConfig{
    void set (
      const std::string name,
      const std::string val
    ){
        cpp_config_sec::conf->set(
          name,
          val
        );
    };
    void map (
        std::map<std::string, std::string> map_
    ){
        for(auto const & [name, val] : map_){
            cpp_config_sec::conf->set(
                name,
                val
            );
        }
    };
    std::string get (const std::string name){
        return cpp_config_sec::conf->get(
          name
        );
    };
    std::string get (const std::string name, std::string def){
        return cpp_config_sec::conf->get(
          name,
          def
        );
    };
    int getInt (const std::string name){
        return cpp_config_sec::conf->getInt(
          name
        );
    };
    int getInt (const std::string name, int def){
        return cpp_config_sec::conf->getInt(
          name,
          def
        );
    };
};

#endif
