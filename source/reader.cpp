
#include "reader.hpp"

namespace nc {
namespace binary {

Reader::Reader() : length{0}, offset{0}, data(nullptr) {}

Reader::Reader(const uint8_t* input_, std::size_t len_)
    : length{len_}, offset{0}, data(input_) {}

Reader::Reader(const uint8_t* input_, std::size_t len_, std::size_t offset_)
    : length{len_}, offset{offset_}, data(input_) {}

Reader::Reader(const std::initializer_list<uint8_t>& list_)
    : length{list_.size()}, offset{0}, data(list_.begin()) {}

Reader::Reader(const std::initializer_list<uint8_t>& list_, std::size_t offset_)
    : length{list_.size()}, offset{offset_}, data(list_.begin()) {}

Reader::~Reader() {}

const std::string Reader::NextStr8() {
  char ch;
  std::string str;
  while (offset < length && (ch = NextInt8())) str += ch;
  return str;
}

const std::u16string Reader::NextStr16() {
  char16_t ch;
  std::u16string str;
  while (offset < length && (ch = NextInt16())) str += ch;
  return str;
}

const std::u32string Reader::NextStr32() {
  char32_t ch;
  std::u32string str;
  while (offset < length && (ch = NextInt32())) str += ch;
  return str;
}

const std::wstring Reader::NextWstr() {
  wchar_t ch;
  std::wstring str;
  while (offset < length && (ch = Next<wchar_t>())) str += ch;
  return str;
}

}  // namespace binary
}  // namespace nc
