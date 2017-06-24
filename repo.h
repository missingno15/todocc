#ifndef REPO_H
#define REPO_H

#include <vector>
#include <map>

class Repo {
  public:
    Repo(std::string);

    // attributes
    std::string filename;
    std::vector<std::string> headers {
      "id",
      "completed",
      "task",
      "created_at",
      "updated_at"
    };
    std::vector<std::map<std::string, std::string>> store;

    // methods
    std::vector<std::map<std::string, std::string>> all();
    void delete_at(std::string);
    void insert(std::map<std::string, std::string>);
    std::map<std::string, std::string> find(std::string);
    std::vector<std::string> get_headers() const;
    void update(std::string, std::string, std::string);
  private:
    void persist();
    std::string generate_timestamp();
};
#endif
