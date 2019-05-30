
#include "reader.hpp"
#include "writer.hpp"

#include <iostream>

int main() {
  nc::binary::Writer writer;

  writer.PushDouble(3.14);
  writer.PushFloat(9.182f);
  writer.PushUInt32(1234);
  writer.PushStr8("asdafd");
  writer.PushUInt16(0xd);

  nc::binary::Reader reader(writer.Data().data(), writer.Offset());
  std::cout << reader.NextDouble() << std::endl;
  std::cout << reader.NextFloat() << std::endl;
  std::cout << reader.NextUInt32() << std::endl;
  std::cout << reader.NextStr8() << std::endl;
  std::cout << reader.NextUInt16() << std::endl;

  return 0;
}
