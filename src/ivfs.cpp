#include "ivfs.h"

using namespace TestTask;

IVFS::IVFS( const char *archive ) {
  //todo
}

IVFS::~IVFS() {
  // std::lock_guard<std::recursive_mutex> locker(lock); //todo: is it needed? Close() has a lock_guard already
  for (auto &it : files) {
    Close(it.second);
  }
}

File *IVFS::Open( const char *name ) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  //todo: depends on what is stored in IVFS
}

File *IVFS::Create( const char *name ) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  //todo: depends on what is stored in IVFS
}

size_t IVFS::Read( File *f, char *buff, size_t len ) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  //todo: depends on what is stored in IVFS
}

size_t IVFS::Write( File *f, char *buff, size_t len ) {
  std::lock_guard<std::recursive_mutex> locker(lock);
  //todo: depends on what is stored in IVFS
}

void IVFS::Close( File *f ) {
  if (!f) {
    return;
  }
  std::lock_guard<std::recursive_mutex> locker(lock);
  std::string filename(f->getPath());
  auto entry = files.find(filename);
  if (entry != files.end() && entry->second == f) {
    switch (f->getMode()) {
      case Mode::ReadOnly:
        //todo
        break;
      case Mode::WriteOnly:
        //todo: update the files data in the archive
    }
    files.erase(filename);
  }
  delete f;
}

File *IVFS::OpenedReadonly( const char *filename ) const {
  auto entry = files.find(std::string(filename));
  if (entry != files.end() || !entry->second || entry->second->getMode() != Mode::ReadOnly) {
    return nullptr;
  }
  return entry->second;
}

File *IVFS::OpenedWriteonly( const char *filename ) const {
  auto entry = files.find(std::string(filename));
  if (entry != files.end() || !entry->second || entry->second->getMode() != Mode::WriteOnly) {
    return nullptr;
  }
  return entry->second;
}

bool IVFS::Valid() const {
  //todo: depends on what is stored in IVFS
}
