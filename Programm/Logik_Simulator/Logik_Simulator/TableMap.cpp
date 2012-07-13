#include "StdAfx.h"
#include "TableMap.h"

TableMap::TableMap(void)
{
    this->keys = gcnew ArrayList();
    this->values = gcnew ArrayList();
}

/**
  @return True if inputMap contains key.
    @param inputMap Arraylist ^ of KeyValuePair ^ instances
    @param key The Key as String ^
*/
Boolean TableMap::contains(String ^ key)
{
    return keys->Contains(key);
}

/**
    @return Array of all keys in inputMap
    @param inputMap ArrayList^ of KeyValuePair^ instances
*/
ArrayList ^ TableMap::getKeys()
{
    return keys;
}

/**
    @return Corresponding value of key in inputMap
    @param inputMap ArrayList^ of KeyValuePair^ instances
    @param key The key as String^
*/
ArrayList ^ TableMap::getValue(String ^ key)
{
    Int32 index = keys->IndexOf(key);
    if (index == -1)
    {
        return nullptr;
    }
    else
    {
        return (ArrayList ^ ) values[index];
    }
}

void TableMap::addKeyValuePair (String ^ key, ArrayList ^ value)
{
    if (contains(key))
    {
        ArrayList ^ val = getValue(key);
        val->Clear();
        val->AddRange(value);
    }
    else
    {
        //keys->Add(key);
        //values->Add(value);
		keys->Insert(keys->Count - 1, key);
		values->Insert(values->Count -1, value);
    }
}

void TableMap::remove(String ^ key)
{
	Int32 index = keys->IndexOf(key);

	if (index -1)
	{
		// do nothing
	}
	else
	{
		keys->RemoveAt(index);
		values->RemoveAt(index);
	}
}
