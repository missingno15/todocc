#include <iostream>
#include <string>
#include <vector>
#include <numeric>

namespace Utility {
  namespace String {
    std::vector<std::string> split(std::string str, char delimiter) {
      std::vector<std::string> fragments = {};
      
      std::string fragment_buffer;
      for (char& c : str) {
        if (c == delimiter) {
          // Add fragment to the collection
          // and reset buffer
          fragments.push_back(fragment_buffer);
          fragment_buffer.clear();
        } else if (c == str.back()){
          fragment_buffer.append(1, c);
          fragments.push_back(fragment_buffer);
        } else {
          fragment_buffer.append(1, c);
        }
      }

      return fragments;
    }

    std::string trim(std::string str) {

      size_t first_position = str.find_first_not_of(' ');
      size_t last_position  = str.find_last_not_of(' ');

      if (first_position == 0 && (last_position + 1) == str.length()) {
        return str;
      } else {
        return str.substr(first_position, (last_position - first_position + 1));
      }
    }

    std::vector<std::string> trim_all(std::vector<std::string> strs) {
      std::vector<std::string> new_vector = {};
      
      for (std::string str : strs) {
        new_vector.push_back(trim(str));
      }

      return new_vector;
    }
  }
}
