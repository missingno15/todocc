#ifndef UTILITY_H
#define UTILITY_H

namespace Utility {
  namespace Map {
    std::vector<std::string> to_vector(std::map<std::string, std::string>);
  }

  namespace String {
    std::vector<std::string> split(std::string, char);
    std::string trim(std::string);
    std::vector<std::string> trim_all(std::vector<std::string>);
  }

  namespace Vector {
    std::string join(std::vector<std::string>, std::string);
    std::vector<std::vector<std::string>> zip(std::vector<std::string>, std::vector<std::string>);
  }
}

#endif
