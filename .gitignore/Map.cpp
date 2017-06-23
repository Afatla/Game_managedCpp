#include "stdafx.h"
#include "Map.h"


Map::Map(Location^ location)
{
	this->begin=location;
}
Map::Map(){}
Location^ Map::Begin::get()
{
	return this->begin;
}

void Map::Begin::set(Location^ value)
{
	this->begin = value;
}
