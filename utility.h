#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#ifndef UTILITY_H
#define UTILITY_H value

namespace Utility {
  namespace Map {
    std::vector<std::string> to_vector(std::map<std::string, std::string> m) {
      std::vector<std::string> values;

      for (auto const& pair : maphash) {
        values.push_back(pair.second());
      }

      return values;
    }
  }

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

  namespace Vector {
    std::string join(std::vector<std::string> string_vector, std::string delimiter) {
      std::string result;
      for (int i = 0; i < string_vector.size(); ++i) {
        if (i == 0) {
          result += string_vector[i];
        } else {
          result += " ";
          result += delimiter;
          result += string_vector[i];
        }
      }

      return result;
    }

    std::vector<std::vector<std::string>> zip(std::vector left, std::vector right) {
      std::vector zipper {};

      if (left.size() == right.size()) {
        for (int i = 0; i < left.size(); ++i) {
          std::vector<std::string> teeth_chain {};
          teeth_chain.push_back(left[i]);
          teeth_chain.push_back(right[i]);
          zipper.push_back(teeth_chain)
        }
      } else {
        throw "Size of left and right vectors are not the same";
      }
    }
  }
}

#endif
