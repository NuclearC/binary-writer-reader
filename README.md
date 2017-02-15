# binary-writer-reader
Binary Reader/Writer for C/C++

## Usage
#### Example for char[]/unsigned char[] buffers
```C++
#include "binary.h"
...

char buf[256]; // our buffer

unsigned long long offset = 0;

// Writing
writeDouble(buf, offset, 3.14);
writeInt32(buf, offset, 20030319);
writeFloat(buf, offset, 9.8f);

offset = 0;

// Reading
double my_awesome_pi = readDouble(buf, sizeof(buf), offset);
int my_awesome_int = readInt32(buf, sizeof(buf), offset);
float my_float_awesomee = readFloat(buf, sizeof(buf), offset);

```
#### Example of std::vector's
```C++
#include <vector>

#include "binary.h"

int main() {
    std::vector<char> my_buf;

    // Writing
    my_buf.insert(my_buf.end(), 16, 0);

    unsigned long long off = 0;
    writeDouble(&my_buf[0], off, 3.0 / 2.0);
    // Or
    writeToVector<double>(my_buf, off, 3.14);

    off = 0;
    // Reading
    double my_var = readDouble(my_buf.data(), my_buf.size(), off);
    double my_var2 = readDouble(my_buf.data(), my_buf.size(), off);

    return 0;
}
```
