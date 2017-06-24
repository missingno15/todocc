#ifndef REPO_H
#define REPO_H

class Repo{
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
    std::map<std::string, std::string> find(std::string);
    std::string get_filename() const;
    std::vector<std::string> get_headers() const;
    void update(std::string, std::string, std::string);
  private:
    void persist();
    std::string generate_timestamp();
#endif