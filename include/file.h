#ifndef IVFS_FILE_H
#define IVFS_FILE_H

namespace TestTask {

  enum Mode {
    ReadOnly,
    WriteOnly
  };

  struct File {
  public:
    File(const char *path, Mode mode);
    ~File();

    const char* getData() const;
    void setData();

    const char* getPath() const;

    Mode getMode() const;

  private:
    char *data;
    char *path;
    Mode mode;
  };

} // namespace TestTask

#endif //IVFS_FILE_H
