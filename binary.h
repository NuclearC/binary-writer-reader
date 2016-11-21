// ----------------------------------------------------- //
//                                                       //
//              Binary Writer/Reader                     //
//               Copyright (C) 2016                      //
//                  by NucleArc                          //
//                                                       //
// ----------------------------------------------------- //

#pragma once

#ifndef BINARY_H_
#define BINARY_H_
#include <vector>
#include <cstring>
#include <cstdint>

template<typename _T>
static void writeToVector(std::vector<char>& _Buffer, unsigned long long& _Offset, const _T& _Val, bool _Le = true)
{
	unsigned long long size = sizeof(_T);
	unsigned const char * array = reinterpret_cast<unsigned const char *>(&_Val);

	for (unsigned long i = 0; i < size; i++)
	{
		_Buffer[_Offset] = (array[i]);
		_Offset++;
	}
}

template<typename _T>
static void writeToVector(std::vector<unsigned char>& _Buffer, unsigned long long& _Offset, const _T& _Val, bool _Le = true)
{
	unsigned long long size = sizeof(_T);
	unsigned const char * array = reinterpret_cast<unsigned const char *>(&_Val);

	for (unsigned long i = 0; i < size; i++)
	{
		_Buffer[_Offset] = (array[i]);
		_Offset++;
	}
}

template<typename _T>
static void writeToBuffer(char* _Buffer, unsigned long long& _Offset, const _T& _Val, bool _Le = true)
{
	unsigned long long size = sizeof(_T);
	unsigned const char * array = reinterpret_cast<unsigned const char *>(&_Val);

	for (unsigned long i = 0; i < size; i++)
	{
		*(_Buffer + _Offset + i) = (char)array[i];
	}

	_Offset += size;
}

template<typename _T>
static _T readFromBuffer(const char* _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true)
{
	_T _Result = 0;
	unsigned long long size = sizeof(_T);
	if (size + _Offset > _Size)
		return _Result;

	memcpy(&_Result, _Buffer + _Offset, size);
	_Offset += size;
	return _Result;
}

static int readInt32(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<int>(_Buffer, _Size, _Offset, _Le);
}

static short int readInt16(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<short>(_Buffer, _Size, _Offset, _Le);
}

static char readInt8(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<char>(_Buffer, _Size, _Offset, _Le);
}

static unsigned int readUint32(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<unsigned int>(_Buffer, _Size, _Offset, _Le);
}

static unsigned short int readUint16(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<unsigned short>(_Buffer, _Size, _Offset, _Le);
}

static unsigned char readUint8(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<unsigned char>(_Buffer, _Size, _Offset, _Le);
}

static float readFloat(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<float>(_Buffer, _Size, _Offset, _Le);
}

static double readDouble(const char * _Buffer, const unsigned long long& _Size, unsigned long long& _Offset, bool _Le = true) {
	return readFromBuffer<double>(_Buffer, _Size, _Offset, _Le);
}

static void writeInt32(char* _Buffer, unsigned long long& _Offset, const int& _Val, bool _Le = true) {
	return writeToBuffer<int>(_Buffer, _Offset, _Val, _Le);
}

static void writeInt16(char* _Buffer, unsigned long long& _Offset, const short& _Val, bool _Le = true) {
	return writeToBuffer<short>(_Buffer, _Offset, _Val, _Le);
}

static void writeInt8(char* _Buffer, unsigned long long& _Offset, const char& _Val, bool _Le = true) {
	return writeToBuffer<char>(_Buffer, _Offset, _Val, _Le);
}

static void writeUint32(char* _Buffer, unsigned long long& _Offset, const unsigned int& _Val, bool _Le = true) {
	return writeToBuffer<unsigned int>(_Buffer, _Offset, _Val, _Le);
}

static void writeUint16(char* _Buffer, unsigned long long& _Offset, const unsigned short& _Val, bool _Le = true) {
	return writeToBuffer<unsigned short>(_Buffer, _Offset, _Val, _Le);
}

static void writeUint8(char* _Buffer, unsigned long long& _Offset, const unsigned char& _Val, bool _Le = true) {
	return writeToBuffer<unsigned char>(_Buffer, _Offset, _Val, _Le);
}

static void writeFloat(char* _Buffer, unsigned long long& _Offset, const float& _Val, bool _Le = true) {
	return writeToBuffer<float>(_Buffer, _Offset, _Val, _Le);
}

static void writeDouble(char* _Buffer, unsigned long long& _Offset, const double& _Val, bool _Le = true) {
	return writeToBuffer<double>(_Buffer, _Offset, _Val, _Le);
}
#endif // BINARY_H_