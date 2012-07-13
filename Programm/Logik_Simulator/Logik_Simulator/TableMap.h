#pragma once

using namespace System;
using namespace System::Collections;

public ref class TableMap
{
public:
	TableMap(void);
protected:
	ArrayList^ keys;
	ArrayList^ values;
public:
	Boolean contains(String ^ key);
	ArrayList ^ getKeys();
	ArrayList ^ getValue(String ^ key);
	void addKeyValuePair(String ^ key, ArrayList ^ value);
	void remove(String ^ key);
};
