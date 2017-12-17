#ifndef _MUDUO_SOURCEFILE_H_
#define _MUDUO_SOURCEFILE_H_
#include <string.h>
namespace muduo
{
class SourceFile
{
  public:
    template <int N>
    inline SourceFile(const char (&arr)[N])
        : data_(arr),
          size_(N - 1)
    {
        const char *slash = strrchr(data_, '/'); // builtin function
        if (slash)
        {
            data_ = slash + 1;
            size_ -= static_cast<int>(data_ - arr);
        }
    }

    explicit SourceFile(const char *filename)
        : data_(filename)
    {
        const char *slash = strrchr(filename, '/');
        if (slash)
        {
            data_ = slash + 1;
        }
        size_ = static_cast<int>(strlen(data_));
    }

    const char *data_;
    int size_;
};
};

#endif //_MUDUO_SOURCEFILE_H_