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

#endif // BINARY_H_