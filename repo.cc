#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <locale>
#include "repo.h"
#include "utility.h"

// public

void Repo::Repo(std::string name) {
  std::fstream filestream;
  filename = name + ".csv";

  filestream.open(filename, std::ios::in);

  if (file.fail()) {
    // Create file if it doesn't exist
    filestream.open(filename, std::ios::out);
    filestream.close();
    store = {};
  } else {
    while(file) {
      std::string row_string;
      std::map<std::string, std::string> datum;

      std::getline(file, row_string, "\n");
      std::vector<std::string> row = Utility::String::split(row_string, ',');

      std::vector<std::vector<std::string>> row_value
        = Utility::Vector::zip(get_headers(), row);

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

void Repo::delete_at(std::string identifier) {
  // can't immediately find an idiomatic way to delete an element from a vector
  // so i'm just going to copy and assign while skipping element to be deleted
  std::vector<std::map<std::string, std::string>> updated_store;

  for (std::map<std::string, std::string> row : store) {
    updated_store.push_back(row);
  }

  
}

void Repo::insert(std::map<std::string, std::string> task) {
  // ids are strings even though they are represented as numbers wanted to
  // implement ids as random series of alphanumeric string but not much time
  // and don't quite get how to do it so doing it incremental index based
  if (get_store().empty()) {
    task["id"] = "1";
  } else {
    task["id"] = (std::itoa(get_store().last()["id"]) + 1);
  }

  task["created_at"] = generate_timestamp();

  store.push_back(task);

  persist();
}

std::string Repo::get_filename() const {
  return filename;
}

std::vector<std::string> Repo::get_headers() const {
  return headers;
}

void Repo::update(std::string identifier, std::string key, std::string new_value) {
  for (std::map<std::string, std::string> row : store) {
    if (store["id"] == identifier) {
      store[key] = new_value;
      store["updated_at"] = generate_timestamp();
      break;
    }
  }

  persist();
}


// private
void Repo::persist() {
  ofstream file;
  file.open(filename);

  for (auto const& row : get_headers()) {
    std::string csv_row = Utility::Vector::join(Utility::Map::to_vector(row), " ");
    file << csv_row << std::endl;
  }

  file.close();
}

std::string Repo::generate_timestamp() {
  char timestamp[50];
  end = std::chrome::system_clock::now();
  std::time_t end_time = std::chrome::system_clock::to_time_t(end);

  std::strftime(
    timestamp,
    sizeof(timestamp),
    "%Y%m%d %p%l:%M:%S",
    std::localtime(&end_time)
  );

  return timestamp;

}
