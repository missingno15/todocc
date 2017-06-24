#include <numeric>
#include <iostream>
#include <regex>
#include "repo.h"
#include "utility.h"

bool identifier_is_valid(std::string identifier) {
  return std::regex_match(identifier, std::regex("^[0-9]+$"));
} 

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    std::cout << "You need to provide a name of your list" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  const std::string options = "(I)nsert (S)how (C)omplete (R)ename (D)elete (E)xit";

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
      for (std::map<std::string, std::string> row : repo.all()) {
        std::vector<std::string> values;

        for (auto const& header : repo.get_headers()) {
          values.push_back(row[header]);
        }

        std::cout << Utility::Vector::join(values, " ")  << std::endl;
      }

      std::cout << options << std::endl;
    } else if (flag == "I") {
      std::cout << "Enter the follow values\n" << std::endl;
      std::map<std::string, std::string> task;

      for (std::string header : repo.get_headers()) {
        // Do some awkward stuff
        if (header == "id" || header == "created_at" || header == "updated_at"){
          task[header] = "nil";
        } else if (header == "completed"){
          task[header] = "FALSE";
        } else {
          std::string capture;
          std::cout << header << ":" << std::endl;
          std::cin.ignore();
          std::getline(std::cin, capture);
          task["task"] = capture;
        }
      }

      repo.insert(task);

      std::cout << options << std::endl;
    } else if (flag == "C") {
      // mark as complete
      std::string identifier;
      while(true) {
        std::cout << "Enter the ID of the task you want to complete" << std::endl;
        std::cin.ignore();
        std::cin >> identifier;
        if (identifier_is_valid(identifier)) {
          break;
        }
      }

      repo.update(identifier, "completed", "TRUE");
      std::cout << "Updated " << identifier << std::endl;

      std::cout << options << std::endl;
    } else if (flag == "R"){
      // rename task
      std::string identifier;
      std::string new_task_name;

      while(true) {
        std::cout << "Enter the ID of the task you want to rename." << std::endl;
        std::cin.ignore();
        std::cin >> identifier;
        if (identifier_is_valid(identifier)) {
          break;
        }
      }

      std::cout << "Enter the new name of your task"  << std::endl;
      std::getline(std::cin, new_task_name);

      repo.update(identifier, "task", new_task_name);
      std::cout << "Updated " << identifier << " to " << new_task_name << std::endl;

      std::cout << options << std::endl;
    } else if (flag == "D") {
      // delete task
      std::string identifier;

      while(true) {
        std::cout << "Enter the ID of the task you want to delete" << std::endl;
        std::cin >> identifier;
        std::cin.ignore();
        if (identifier_is_valid(identifier)) {
          break;
        }
      }

      repo.delete_at(identifier);

      std::cout << "Deleted " << identifier  << std::endl;
      std::cout << options << std::endl;
    }
  }

  return 0;
}
