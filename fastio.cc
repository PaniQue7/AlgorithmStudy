#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/syscall.h>
using namespace std;

namespace fastio {
    const int BSIZE = 2097152;
    char buffer[BSIZE];
    auto p = buffer + BSIZE;
    inline char readChar() {
        if (p == buffer + BSIZE) {
            syscall(0x00, 0, buffer, BSIZE);
            p = buffer;
        }
        return *p++;
    }
    int readInt() {
        char c = readChar();
        while (c < '-') {
            c = readChar();
        }
        int ret = 0;
        while (c >= '-') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return ret;
    }

    unsigned char outbuf[BSIZE];
    unsigned char *outp = outbuf;

    inline void printans(bool ans)
    {
        *outp++ = ans + '0';
        *outp++ = '\n';
    }

    void flush()
    {
        syscall(0x01, 1, outbuf, outp - outbuf);
    }
}
