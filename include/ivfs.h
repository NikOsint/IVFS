#ifndef IVFS_IVFS_H
#define IVFS_IVFS_H

#include <cstddef>
#include <mutex>
#include <unordered_map>

#include <Poco/Zip/ZipArchive.h>
//#include <filesystem>

#include "file.h"

namespace TestTask {

  struct IVFS {
  public:

    IVFS( const char *archive );
    ~IVFS();

    /*
     * Открыть файл в readonly режиме.
     * Если нет такого файла или же он открыт во writeonly режиме - вернуть nullptr.
     */
    File *Open( const char *name );

    /*
     * Открыть или создать файл в writeonly режиме.
     * Если нужно, то создать все нужные поддиректории, упомянутые в пути.
     * Вернуть nullptr, если этот файл уже открыт в readonly режиме.
     */
    File *Create( const char *name );

    /*
     * Прочитать данные из файла.
     * Возвращаемое значение - сколько реально байт удалось прочитать.
     */
    size_t Read( File *f, char *buff, size_t len = 0 );

    /*
     * Записать данные в файл.
     * Возвращаемое значение - сколько реально байт удалось записать.
     */
    size_t Write( File *f, char *buff, size_t len = 0 );

    /*
     * Закрыть файл.
     */
    void Close( File *f );

    File *OpenedReadonly( const char *filename ) const;
    File *OpenedWriteonly( const char *filename ) const;

    bool Valid() const;

  private:
    //todo: filename / file stream / ?
    mutable std::recursive_mutex lock;
    std::unordered_map<std::string, File*> files;
  };

} // namespace TestTask

#endif //IVFS_IVFS_H
