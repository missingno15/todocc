#include <numeric>
#include <iostream>
#include <functional>
#include "repo.h"
#include "utility.h"

int main(int argc, char *argv[]) {
  if (argv[1].empty()) {
    throw "No list argument was passed."
  }

  std::string filename= argv[1];
  const std::string options = "(I)nsert (S)how Update (D)elete (E)xit";

  // Initialize database
  Repo repo(filename);

  // Print current data if any
  std::cout << "Course Project\n" << std::endl;
  if(repo.all().empty()) {
    std::cout << "No tasks created yet for " << filename << ". Press I to start." << std::endl;
    std::cout << options << std::endl;
  } else {
    std::cout << options << std::endl;
  }

  // Define lambdas for each screen
  std::function<void()> display_show_view = []() { 
    for (auto const& row : repo.all()) {
      std::vector<std::string> values;
      for (auto const& pair : row) {
        values.push_back(pair.first());
      }

      std::cout << Utility::Vector::join(values, " ")  << std::endl; 
    }

    std::cout << options << std::endl;
  };

  std::function<void()> display_insert_dialog = [](){
    std::cout << "Enter the follow values\n" << std::endl;

    std::vector<std::string> insert_values;
    for (std::string header : repo.get_headers()) {
      // Do some awkward stuff
      if (header == "id" || header == "created_at" || header == "updated_at"){
        continue
      } else {
        std::string capture;
        std::cout << header << ":" std::endl;
        std::getline(std::cin, capture);
      }
    }
  };


  // Begin loop interface
  while(true) {
    std::string flag;
    std::cin >> flag;

    if (flag == "E"){
      std::cout << "\nExiting" << std::endl;
      break;
    } else if (flag == "S"){ 
      display_show_view();
    } else if (flag == "I") {


      std::cout << options << std::endl;
    } else if (flag == "U") {

      std::cout << options << std::endl;
    } else if (flag == "D") {

      std::cout << options << std::endl;
    }
  }

  return 0;
}
