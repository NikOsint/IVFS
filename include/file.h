#ifndef IVFS_FILE_H
#define IVFS_FILE_H

namespace TestTask {

  enum Mode {
    ReadOnly,
    WriteOnly
  };

  struct File {
  public:

  private:
    Mode mode;
  };

} // namespace TestTask

#endif //IVFS_FILE_H
