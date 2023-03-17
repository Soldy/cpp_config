# cpp_config


This is a simple config manager class for small projects.


## def  
define config variable and check env value.
```cpp
   void cppConfig::def(std::map<std::string, std::string>);
```


## set
Set a variable value.
```cpp
   void cppConfig::set(std::string, std::string);
```


## get
Get a string value
```cpp
   std::string cppConfig::get(std::string);
   std::string cppConfig::get(std::string, std::string);
```


## getInt
Get an integer value.
```cpp
   int cppConfig::getInt(std::string);
   int cppConfig::getInt(std::string, int);
```



