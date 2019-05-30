#ifndef NC_BINARY_READER_HPP_
#define NC_BINARY_READER_HPP_

#include <cstdint>
#include <cstring>
#include <exception>
#include <initializer_list>
#include <stdexcept>
#include <string>

namespace nc {
namespace binary {
class Reader {
 private:
  const uint8_t* const data;
  const std::size_t length;
  std::size_t offset;

 public:
  Reader();
  Reader(const uint8_t* input_, std::size_t len_);
  Reader(const uint8_t* input_, std::size_t len_, std::size_t offset_);
  Reader(const std::initializer_list<uint8_t>& list_);
  Reader(const std::initializer_list<uint8_t>& list_, std::size_t offset_);
  ~Reader();

  template <typename T>
  inline const T Next() {
    const auto size = sizeof(T);
    if ((offset + size) > length)
      throw std::out_of_range("buffer reading overflow");
    const auto res = *reinterpret_cast<T*>(const_cast<uint8_t*>(data) + offset);
    offset += size;
    return res;
  }

  inline const int8_t NextInt8() {
    if (offset + 1 > length) throw std::out_of_range("buffer reading overflow");
    return data[offset++];
  }
  inline const uint8_t NextUInt8() {
    if (offset + 1 > length) throw std::out_of_range("buffer reading overflow");
    return data[offset++];
  }

  inline const int16_t NextInt16() { return Next<int16_t>(); }
  inline const uint16_t NextUInt16() { return Next<uint16_t>(); }
  inline const int32_t NextInt32() { return Next<int32_t>(); }
  inline const uint32_t NextUInt32() { return Next<uint32_t>(); }
  inline const int64_t NextInt64() { return Next<int64_t>(); }
  inline const uint64_t NextUInt64() { return Next<uint64_t>(); }

  inline const float NextFloat() { return Next<float>(); }
  inline const float NextDouble() { return Next<double>(); }

  const std::string NextStr8();
  const std::u16string NextStr16();
  const std::u32string NextStr32();
  const std::wstring NextWstr();

  inline const std::size_t Length() const { return length; }
  inline const std::size_t Offset() const { return offset; }
  inline const uint8_t* Data() const { return data; }
};
}  // namespace binary
}  // namespace nc

#endif  // NC_BINARY_READER_HPP_
