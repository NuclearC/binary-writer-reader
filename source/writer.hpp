#ifndef NC_BINARY_WRITER_HPP_
#define NC_BINARY_WRITER_HPP_

#include <cstdint>
#include <cstring>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>

namespace nc {
namespace binary {

static constexpr std::size_t ENLARGE_CAP = 256ULL;

class Writer {
 private:
  std::vector<uint8_t> data;
  std::size_t offset;

 public:
  Writer();
  Writer(std::size_t length_);
  ~Writer();

  inline void SetOff(std::size_t pos) { offset = pos; }
  inline const std::size_t Offset() const { return offset; }
  inline std::vector<uint8_t>& Data() { return data; }

  template <typename T>
  inline void Push(T val) {
    const auto size = sizeof(T);
    while (offset + size > data.size())
      data.insert(data.end(), ENLARGE_CAP, 0x00);
    std::memcpy(data.data() + offset, &val, size);
    offset += size;
  }

  void PushInt8(int8_t val) {
    if (offset + 1 > data.size()) data.insert(data.end(), ENLARGE_CAP, 0x00);
    data[offset++] = val;
  }
  void PushUInt8(uint8_t val) {
    if (offset + 1 > data.size()) data.insert(data.end(), ENLARGE_CAP, 0x00);
    data[offset++] = val;
  }

  inline void PushInt16(int16_t val) { Push(val); }
  inline void PushUInt16(uint16_t val) { Push(val); }

  inline void PushInt32(int32_t val) { Push(val); }
  inline void PushUInt32(uint32_t val) { Push(val); }

  inline void PushInt64(int64_t val) { Push(val); }
  inline void PushUInt64(uint64_t val) { Push(val); }

  inline void PushFloat(float val) { Push(val); }
  inline void PushDouble(double val) { Push(val); }

  void PushStr8(std::string str);
  void PushStr16(std::u16string str);
  void PushStr32(std::u32string str);
  void PushWstr(std::wstring str);
};
}  // namespace binary
}  // namespace nc

#endif  // NC_BINARY_WRITER_HPP_
