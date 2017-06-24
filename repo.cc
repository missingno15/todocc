#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "repo.h"

void Repo::Repo(std::string name) {
  std::fstream filestream;
  std::string filename = name + ".csv";
  
  // hard code these headers for now
  headers = {
    "id",
    "completed",
    "task",
    "created_at",
    "updated_at"
  };

  filestream.open((filename + ".csv"), std::ios::in);

  if (file.fail()) {
    // Create file if it doesn't exist
    filestream.open(filename, std::ios::out);
    filestream.close();
  } else {
    while(file) {
      std::string row_string;
      std::map<std::string, std::string> datum;

      std::getline(file, row_string, "\n");
      std::vector<std::string> row = Utility::String::split(row_string, ',');

      std::vector<std::vector<std::string>> row_value 
        = Utility::Vector::zip(headers, row);

      for (std::vector<std::string> teeth_chain : row_value) {
        std::string key = teeth_chain.front();
        std::string value = teeth_chain.back();
        datum[key] = value;
      }

      store.push_back(datum);
    }
  }
}

std::vector<std::map<std::string, std::string>> Repo::all() {
  return store;
}

std::map<std::string, std::string> Repo::find(std::string identifier) {
  std::map<std::string, std::
  for (int i = 0; i < store.size(); ++i) {
    if (store[i]["id"] == identifier) {
      return store[i]["id"];
    }    
  }
}

std::vector<std::string> Repo::get_headers() {
  return headers;
}

void Repo::update(std::string identifier, std::string key, std::string new_value) {
  for (int i = 0; i < store.size(); ++i) {
    if (store[i]["id"] == identifier) {
      store[i][key] = new_value;
      break;
    }    
  }
}
