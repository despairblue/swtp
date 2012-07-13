#include "StdAfx.h"
#include "TableMap.h"

TableMap::TableMap(void)
{
    this->keys = gcnew ArrayList();
    this->values = gcnew ArrayList();
    this->length = 0;
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
        values[keys->IndexOf(key)] = value;
    }
    else
    {
        keys->Add(key);
        values->Add(value);
    }
}

void TableMap::remove(String ^ key)
{
    Int32 index = keys->IndexOf(key);

    if (index == -1)
    {
        // do nothing
    }
    else
    {
        keys->RemoveAt(index);
        values->RemoveAt(index);
    }
}

void TableMap::removeAll()
{
    keys->Clear();
    values->Clear();
}

void TableMap::addKey(String ^ key)
{
    ArrayList ^ tempValue = gcnew ArrayList();

    for (int i = 0; i < length; i++)
    {
        tempValue->Add(false);
    }

    addKeyValuePair(key, tempValue);
}

Int32 TableMap::getLength()
{
    return length;
}

// void setLength(Int32 length)
// {
//     this->length = length;

//     for each (String ^ key in keys)
//     {
//         ArrayList^ tempValue = getValue(key);

//         for (int i = 0; i < length; i++)
//         {
//             if (tempValue[i])
//             {

//             }
//         }
//     }
// }

void TableMap::addRow()
{
    length++;

    for each (String ^ key in keys)
    {
        ArrayList ^ value = getValue(key);

        value->Add(false);
    }
}

void TableMap::removeRow()
{
    if (length > 0)
    {
        for each (String ^ key in keys)
        {
            ArrayList ^ value = getValue(key);

			value->RemoveAt(value->Count - 1);
        }
    }
}
