#include "stdafx.h"
#include "Item.h"


Item::Item(void)
{
}
int Item::Price::get()
{
	return price;
}
void Item::Price::set(int p)
{
	price=p;
}
String^ Item::Name::get()
{
	return name;
}
void Item::Name::set(String^ n)
{
	name=n;
}
void Item::Stats::set(Statistics^ n)
{
	stats=n;
}
Statistics^ Item::Stats::get()
{
	return stats;
}