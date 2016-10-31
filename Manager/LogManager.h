#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

class LogManager 
{
 public:
  static void Initialize();
  static void Write(std::string&);
  static void Terminate();
 private:
  static std::ofstream file;
  static const std::string file_name;
};

#endif
