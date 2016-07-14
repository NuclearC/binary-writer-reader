# binary-writer-reader
Binary Reader/Writer for C/C++

#### Usage
```C++
#include "binary.h"
...

std::vector<uint8_t> buffer;

writeInt32(&buffer, 240);
writeFloat(&buffer, 9.801f);

int offset = 0;
int _int32 = readInt32(buffer, &offset); // now offset += size of int
float _float = readFloat(buffer, &offset); // now offset += size of float
```
