#include <numeric>
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
  } else {
    
  }
  

  // Begin loop interface
  while(true) {
    std::string flag;
    std::cin >> flag;

    if (flag == "E"){
    } else if (flag == "I") {
      menu.display_insert_dialog();
    } else if (flag == "U") {
      std::string id;
      std::cout << "Enter the id of the item you want to update:" << std::endl;
      std::cin >> id;
      menu.display_update_dialog(id);
    } else if (flag == "D") {
      menu.display_dialog("insert");
    }
  }

  return 0;
}
