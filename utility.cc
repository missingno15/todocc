#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include "utility.h"

std::vector<std::string> Utility::Map::to_vector(std::map<std::string, std::string> maphash) {
  std::vector<std::string> values;

  for (auto const& pair : maphash) {
    values.push_back(pair.second);
  }

  return values;
}

std::vector<std::string> Utility::String::split(std::string str, char delimiter) {
  std::vector<std::string> fragments = {};

  std::string fragment_buffer;

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == delimiter) {
      // Add fragment to the collection
      // and reset buffer
      fragments.push_back(fragment_buffer);
      fragment_buffer.clear();
    } else if (i == (str.size() - 1)){
      // check if end of string
      fragment_buffer.append(1, str[i]);
      fragments.push_back(fragment_buffer);
    } else {
      fragment_buffer.append(1, str[i]);
    }
  }

  return fragments;
}

std::string Utility::String::trim(std::string str) {
  size_t first_position = str.find_first_not_of(' ');
  size_t last_position  = str.find_last_not_of(' ');

  if (first_position == 0 && (last_position + 1) == str.length()) {
    return str;
  } else {
    return str.substr(first_position, (last_position - first_position + 1));
  }
}

std::vector<std::string> Utility::String::trim_all(std::vector<std::string> strs) {
  std::vector<std::string> new_vector = {};

  for (std::string str : strs) {
    new_vector.push_back(trim(str));
  }

  return new_vector;
}

std::string Utility::Vector::join(std::vector<std::string> string_vector, std::string delimiter) {
  std::string result;
  for (int i = 0; i < string_vector.size(); ++i) {
    if (i == 0) {
      result += string_vector[i];
    } else {
      result += delimiter;
      result += string_vector[i];
    }
  }

  return result;
}

std::vector<std::vector<std::string>> Utility::Vector::zip(std::vector<std::string> left, std::vector<std::string> right) {
  std::vector<std::vector<std::string>> zipper = {};

  if (left.size() == right.size()) {
    for (int i = 0; i < left.size(); ++i) {
      std::vector<std::string> teeth_chain {};
      teeth_chain.push_back(left[i]);
      teeth_chain.push_back(right[i]);
      zipper.push_back(teeth_chain);
    }

    return zipper;
  }
  /* } else { */
  /*   std::cout << "Size of left was " << left.size() << "and size of right was " << right.size() << std::endl; */
  /* } */
}
