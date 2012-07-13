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
	Int32 length;
public:
	Boolean contains(String ^ key);
	ArrayList ^ getKeys();
	ArrayList ^ getValue(String ^ key);
	void addKeyValuePair(String ^ key, ArrayList ^ value);
	void addKey(String ^ key);
	void remove(String ^ key);
	void removeAll();
	Int32 getLength();
	void addRow();
	void removeRow();
};
