#ifndef IVFS_IVFS_H
#define IVFS_IVFS_H

#include <cstddef>
//#include <filesystem>

#include "file.h"

namespace TestTask {

  struct IVFS {
  public:
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
    size_t Read( File *f, char *buff, size_t len );

    /*
     * Записать данные в файл.
     * Возвращаемое значение - сколько реально байт удалось записать.
     */
    size_t Write( File *f, char *buff, size_t len );

    /*
     * Закрыть файл.
     */
    void Close( File *f );

  private:

  };

} // namespace TestTask

#endif //IVFS_IVFS_H
