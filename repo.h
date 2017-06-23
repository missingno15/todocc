#ifndef REPO_H
#define REPO_H

class Repo{
  public:
    Repo(std::string);

    // attributes
    std::vector<std::map<std::string, std::string>> store;
    std::vector<std::string> headers;

    // methods
    std::vector<std::map<std::string, std::string>> all();
    std::map<std::string, std::string> find(std::string);
    void update(std::string, std::string, std::string) {
};
#endif
