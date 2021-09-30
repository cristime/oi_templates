#include <cstdio>
#include <cctype>
using namespace std;

namespace io
{
    FILE *input = stdin, *output = stdout;

    // 整数快读
    template <typename T>
    inline void read(T &x)
    {
        x = 0;
        T f = 1;
        char ch = getc(input);
        while (!isdigit(ch))
        {
            if (ch == '-')
                f = -1;
            ch = getc(input);
        }
        while (isdigit(ch))
        {
            x = x * 10 + ch - '0';
            ch = getc(input);
        }
        return x * f;
    }

    // 整数快写
    template <typename T>
    inline void write(T &x)
    {
        if (x < 0)
        {
            putc('-', output);
            x = -x;
        }
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + '0');
    }
}