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

static int32_t readInt32(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	int32_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static int16_t readInt16(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	int16_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static int8_t readInt8(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	int8_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static uint32_t readUInt32(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	uint32_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static uint16_t readUInt16(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	uint16_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static uint8_t readUInt8(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	uint8_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static double_t readDouble(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	double_t result; int size = sizeof (result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static float_t readFloat(std::vector<uint8_t>& msg, int *off)
{
	if ((*off) > msg.size()) return 0;
	float_t result; int size = sizeof(result);
	memcpy(&result, msg.data() + (*off), size); (*off) += size; 
	return result;
}

static std::string readString(std::vector<uint8_t>& msg, int *off, int size)
{
	return std::string(msg.begin() + (*off), msg.begin() + (*off) + size); (*off) += size; 
}

static void writeInt32(std::vector<uint8_t>* msg, int32_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeInt16(std::vector<uint8_t>* msg, int16_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeInt8(std::vector<uint8_t>* msg, int8_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeUInt32(std::vector<uint8_t>* msg, uint32_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeUInt16(std::vector<uint8_t>* msg, uint16_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeUInt8(std::vector<uint8_t>* msg, uint8_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeFloat(std::vector<uint8_t>* msg, float_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeDouble(std::vector<uint8_t>* msg, double_t value)
{
	uint8_t const * array = reinterpret_cast<uint8_t const *>(&value);

	for (std::size_t i = 0; i != sizeof(value); ++i)
	{
		(*msg).push_back(array[i]);
	}
}

static void writeString(std::vector<uint8_t>* msg, std::string value)
{
	for (int i = 0; i < value.size(); i++)
	{
		(*msg).push_back(value[i]);
	}
}

#endif // BINARY_H_