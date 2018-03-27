/* 
    Binary Reader/Writer
    Copyright (C) 2016-2017 by NuclearC
*/

#pragma once

#ifndef NC_BINARY_H_
#define NC_BINARY_H_

#ifndef  WIN32
#include <string.h>
typedef float float_t;
typedef double double_t;
#endif // ! WIN32

template <typename T>
static void write_buffer(char* buf, size_t len, T value, size_t& offset) {
    auto size = sizeof(T);
    if (offset + size > len) {
        throw "out of range";
    }
    memcpy(buf + offset, &value, size);
    offset += size;
}

template <typename T>
static void write_buffer(char* buf, size_t len, T value, const size_t& offset = 0) {
    auto size = sizeof(T);
    if (offset + size > len) {
        throw "out of range";
    }
    memcpy(buf + offset, &value, size);
}

template <typename T>
static T read_buffer(const char* buf, size_t len, size_t& offset) {
    auto size = sizeof(T);
    if (offset + size > len) {
        throw "out of range";
    }
    T res = {};
    memcpy(&res, buf + offset, size);
    offset += size;
    return res;
}


template <typename T>
static T read_buffer(const char* buf, size_t len, const size_t& offset = 0) {
    auto size = sizeof(T);
    if (offset + size > len) {
        throw "out of range";
    }
    T res = {};
    memcpy(&res, buf + offset, size);
    return res;
}

static void write_int8(char* buf, size_t len, int8_t value, const size_t& offset) {
    return write_buffer<int8_t>(buf, len, value, offset);
}
static void write_int8(char* buf, size_t len, int8_t value, size_t& offset) {
    return write_buffer<int8_t>(buf, len, value, offset);
}
static void write_uint8(char* buf, size_t len, uint8_t value, const size_t& offset) {
    return write_buffer<uint8_t>(buf, len, value, offset);
}
static void write_uint8(char* buf, size_t len, uint8_t value, size_t& offset) {
    return write_buffer<uint8_t>(buf, len, value, offset);
}

static void write_int16(char* buf, size_t len, int16_t value, const size_t& offset) {
    return write_buffer<int16_t>(buf, len, value, offset);
}
static void write_int16(char* buf, size_t len, int16_t value, size_t& offset) {
    return write_buffer<int16_t>(buf, len, value, offset);
}
static void write_uint16(char* buf, size_t len, uint16_t value, const size_t& offset) {
    return write_buffer<uint16_t>(buf, len, value, offset);
}
static void write_uint16(char* buf, size_t len, uint16_t value, size_t& offset) {
    return write_buffer<uint16_t>(buf, len, value, offset);
}

static void write_int32(char* buf, size_t len, int32_t value, const size_t& offset) {
    return write_buffer<int32_t>(buf, len, value, offset);
}
static void write_int32(char* buf, size_t len, int32_t value, size_t& offset) {
    return write_buffer<int32_t>(buf, len, value, offset);
}
static void write_uint32(char* buf, size_t len, uint32_t value, const size_t& offset) {
    return write_buffer<uint32_t>(buf, len, value, offset);
}
static void write_uint32(char* buf, size_t len, uint32_t value, size_t& offset) {
    return write_buffer<uint32_t>(buf, len, value, offset);
}

static void write_int64(char* buf, size_t len, int64_t value, const size_t& offset) {
    return write_buffer<int64_t>(buf, len, value, offset);
}
static void write_int64(char* buf, size_t len, int64_t value, size_t& offset) {
    return write_buffer<int64_t>(buf, len, value, offset);
}
static void write_uint64(char* buf, size_t len, uint64_t value, const size_t& offset) {
    return write_buffer<uint64_t>(buf, len, value, offset);
}
static void write_uint64(char* buf, size_t len, uint64_t value, size_t& offset) {
    return write_buffer<uint64_t>(buf, len, value, offset);
}

static void write_float(char* buf, size_t len, float_t value, const size_t& offset) {
    return write_buffer<float_t>(buf, len, value, offset);
}
static void write_double(char* buf, size_t len, double_t value, const size_t& offset) {
    return write_buffer<double_t>(buf, len, value, offset);
}
static void write_float(char* buf, size_t len, float_t value, size_t& offset) {
    return write_buffer<float_t>(buf, len, value, offset);
}
static void write_double(char* buf, size_t len, double_t value, size_t& offset) {
    return write_buffer<double_t>(buf, len, value, offset);
}

static int8_t read_int8(const char* buf, size_t len, size_t& offset) {
    return read_buffer<int8_t>(buf, len, offset);
}
static int8_t read_int8(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<int8_t>(buf, len, offset);
}
static uint8_t read_uint8(const char* buf, size_t len, size_t& offset) {
    return read_buffer<uint8_t>(buf, len, offset);
}
static uint8_t read_uint8(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<uint8_t>(buf, len, offset);
}

static int16_t read_int16(const char* buf, size_t len, size_t& offset) {
    return read_buffer<int16_t>(buf, len, offset);
}
static int16_t read_int16(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<int16_t>(buf, len, offset);
}
static uint16_t read_uint16(const char* buf, size_t len, size_t& offset) {
    return read_buffer<uint16_t>(buf, len, offset);
}
static uint16_t read_uint16(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<uint16_t>(buf, len, offset);
}

static int32_t read_int32(const char* buf, size_t len, size_t& offset) {
    return read_buffer<int32_t>(buf, len, offset);
}
static int32_t read_int32(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<int32_t>(buf, len, offset);
}
static uint32_t read_uint32(const char* buf, size_t len, size_t& offset) {
    return read_buffer<uint32_t>(buf, len, offset);
}
static uint32_t read_uint32(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<uint32_t>(buf, len, offset);
}

static int64_t read_int64(const char* buf, size_t len, size_t& offset) {
    return read_buffer<int64_t>(buf, len, offset);
}
static int64_t read_int64(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<int64_t>(buf, len, offset);
}
static uint64_t read_uint64(const char* buf, size_t len, size_t& offset) {
    return read_buffer<uint64_t>(buf, len, offset);
}
static uint64_t read_uint64(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<uint64_t>(buf, len, offset);
}

static float_t read_float(const char* buf, size_t len, size_t& offset) {
    return read_buffer<float_t>(buf, len, offset);
}
static float_t read_float(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<float_t>(buf, len, offset);
}
static double_t read_double(const char* buf, size_t len, size_t& offset) {
    return read_buffer<double_t>(buf, len, offset);
}
static double_t read_double(const char* buf, size_t len, const size_t& offset) {
    return read_buffer<double_t>(buf, len, offset);
}

#endif // NC_BINARY_H_