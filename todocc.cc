#include <iostream>

int main(int argc, char *argv[]) {
  if (argv[1].empty()) {
    throw "No list argument was passed."
  }

  std::string filename= argv[1];

  // Initialize database
  Repo repo(filename);

  // Print current data if any
  std::cout << "Course Project\n" << std::endl;
  if(repo.all().empty()) {
    std::cout << "No tasks created yet for " << filename << ". Press I to start." << std::endl;
  }
  

  // Begin loop interface
  // Remember that its like a controller and only directs the program flow
  while(true) {

    

    

    if

  }

  return 0;
}
