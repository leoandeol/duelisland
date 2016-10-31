#include "LogManager.h"

std::ofstream LogManager::file;
const std::string LogManager::file_name = "events.log";

void LogManager::Initialize(){
  file.open(file_name);
}

void LogManager::Write(std::string& s){
  file << s << std::endl;
}

void LogManager::Terminate(){
  file.close();
}
