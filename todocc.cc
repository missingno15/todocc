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

  // Begin loop interface
  while(true) {
    std::string flag;
    std::cin >> flag;

    if (flag == "E"){
      std::cout << "\nExiting" << std::endl;
      break;
    } else if (flag == "S"){ 
      for (auto const& row : repo.all()) {
        std::vector<std::string> values;
        for (auto const& pair : row) {
          values.push_back(pair.first());
        }

        std::cout << Utility::Vector::join(values, " ")  << std::endl; 
      }

      std::cout << options << std::endl;
    } else if (flag == "I") {
      std::cout << "Enter the follow values\n" << std::endl;

      std::vector<std::string> insert_values;
      for (std::string header : repo.get_headers()) {
        // Do some awkward stuff
        if (header == "id" || header == "created_at" || header == "updated_at"){
          continue
        } else if (header == "completed"){
          task[header] = "FALSE";
        } else {
          std::string capture;
          std::cout << header << ":" std::endl;
          std::getline(std::cin, capture);
        }
      }

      std::cout << options << std::endl;
    } else if (flag == "C") {
      // mark as complete 
      std::string identifier;
      std::cout << "Enter the ID of the task you want to complete" << std::endl;
      std::cin >> identifier;

      repo.update(identifier, "completed", "TRUE");
      std::cout << "Updated " << identifier << std::endl;

      std::cout << options << std::endl;
    } else if (flag == "R"){
      // rename task 
      std::string identifier;
      std::string new_task_name;

      std::cout << "Enter the ID of the task you want to rename." << std::endl;
      std::cin >> identifier;

      std::cout << "Enter the new name of your task"  << std::endl;
      std::getline(std::cin, new_task_name);

      repo.update(identifier, "task", new_task_name);
      std::cout << "Updated " << identifier << " to " << new_task_name << std::endl;

      std::cout << options << std::endl;
    } else if (flag == "D") {
      // delete task
      std::string identifier;
      std::cout << "Enter the ID of the task you want to delete" << std::endl;
      std::cin >> identifier;

      repo.delete_at(identifier);

      std::cout << "Deleted " << identifier  << std::endl;
      std::cout << options << std::endl;
    }
  }

  return 0;
}
