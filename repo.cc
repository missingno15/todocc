#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "repo.h"

void Repo::Repo(std::string filename) {
  fstream file(filename, ios::in | ios::out);
  std::string header_string;

  if (file) {
    std::getline(file, header_string, "\n");

    headers = Utility::String::trim_all(
      Utility::String::split(header_string, ',')
    );

    while(file) {
      std::string row_string;
      std::map<std::string, std::string> datum;

      std::getline(file, row_string, "\n");
      std::vector<std::string> row = Utility::String::split(row_string, ',');

      std::vector<std::vector<std::string>> row_value 
        = Utility::Vector::zip(headers, row);

      for (std::vector<std::string> teeth_chain : row_value) {
        std::string key = teeth_chain.front();
        std::string value = teeth_chain.back(); datum[key] = value;
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

void Repo::update(std::string identifier, std::string key, std::string new_value) {
  for (int i = 0; i < store.size(); ++i) {
    if (store[i]["id"] == identifier) {
      store[i][key] = new_value;
      break;
    }    
  }
}
