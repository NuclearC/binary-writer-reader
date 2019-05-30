
#include "writer.hpp"

namespace nc {
namespace binary {
Writer::Writer() : offset{0} {}
Writer::Writer(std::size_t length_) : data(length_), offset{0} {}
Writer::~Writer() {}

void Writer::PushStr8(std::string str) {
  while (offset + str.size() > data.size())
    data.insert(data.end(), ENLARGE_CAP, 0x00);
  for (auto ch : str) data[offset++] = ch;
  data[offset++] = 0;
}
void Writer::PushStr16(std::u16string str) {
  while (offset + (str.size() * 2ULL) > data.size())
    data.insert(data.end(), ENLARGE_CAP, 0x00);
  for (auto ch : str) Push<char16_t>(ch);
  Push<char16_t>(0);
}

void Writer::PushStr32(std::u32string str) {
  while (offset + (str.size() * 4ULL) > data.size())
    data.insert(data.end(), ENLARGE_CAP, 0x00);
  for (auto ch : str) Push<char32_t>(ch);
  Push<char32_t>(0);
}

void Writer::PushWstr(std::wstring str) {
  while (offset + (str.size() * sizeof(wchar_t)) > data.size())
    data.insert(data.end(), ENLARGE_CAP, 0x00);
  for (auto ch : str) Push<wchar_t>(ch);
  Push<wchar_t>(0);
}

}  // namespace binary
}  // namespace nc
