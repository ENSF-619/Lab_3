// DynString.cpp
// ENSF 619 Spring 2020 lab 3 exercise D
//
// completed by:
// lab section:
#include <assert.h>
#include <string.h>
#include "DynString.h"
#pragma warning(disable:4996)

DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
    // Point 1
}

DynString::~DynString()
{
    delete [] storageM;
    // Point 2 
}

int DynString::length() const
{
    return lengthM;
}

char DynString::get_element(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

void DynString::set_element(int pos, char value)
{
    assert(pos >= 0 && pos < length());
    storageM[pos] = value;
}

const char * DynString::c_str() const
{
    return storageM;
}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    
}
void DynString::append(const DynString& tail) {
    
   char* updated = new char [this->lengthM + tail.lengthM+1];
   strcpy(updated, storageM);
   strcat(updated, tail.storageM);
   this->lengthM += tail.lengthM;
   delete[] this->storageM;
   storageM = updated;
    



}