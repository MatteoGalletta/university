/*
 * set.cpp
 */

#include "set.h"

SetDuplicates::SetDuplicates() : size(0)
{
}

SetDuplicates::SetDuplicates(SetDuplicates& s)
{
	size = s.size;
	data = new int[size];
	for (int i = 0; i < size;i++) {
		data[i] = s.data[i];
	}
}

SetDuplicates::~SetDuplicates()
{
	if (size > 0)
		delete [] data;
}


void SetDuplicates::add(int elem)
{
	int * new_data = new int[size + 1];
	for (int i = 0; i < size;i++) {
		new_data[i] = data[i];
	}
	new_data[size] = elem;
	
	if (size > 0)
		delete [] data;
	data = new_data;
	size++;
}

bool SetDuplicates::remove(int elem)
{
	int i;
	for (i = 0; i < size;i++) {
		if (data[i] == elem)
			break;
	}
	
	if (i == size)
		return false;
		
	size--;
	if (size > 0) {
		for (int j = i; j < size;j++) {
			data[j] = data[j + 1];
		}
	
		int * new_data = new int[size];
		for (int i = 0; i < size;i++) {
			new_data[i] = data[i];
		}
	
		delete [] data;
		data = new_data;
	}
	else
		delete [] data;
	return true;
}

bool SetDuplicates::find(int elem)
{
	for (int i = 0; i < size;i++) {
		if (data[i] == elem)
			return true;
	}
	return false;
}

SetDuplicates SetDuplicates::operator+(SetDuplicates & rhs)
{
	SetDuplicates result(rhs);
	for (int i = 0; i < size;i++) {
		result.add(data[i]);
	}
	return result;
}

SetDuplicates SetDuplicates::operator-(SetDuplicates & rhs)
{
	SetDuplicates result(*this);
	for (int i = 0; i < rhs.size;i++) {
		result.remove(rhs.data[i]);
	}
	return result;
}

ostream& operator<<(ostream& output_stream, SetDuplicates & s)
{
	output_stream << "-------------------------" << endl;
	for (int i = 0;i < s.size;i++) {
		output_stream << i << ":" << s.data[i] << endl;
	}
	return output_stream;
}

void Set::add(int elem)
{
	if (find(elem))
		return;
		
	SetDuplicates::add(elem); // chiamata metodo classe padre
}

Set Set::operator+(Set & rhs)
{
	Set result(rhs);
	for (int i = 0; i < size;i++) {
		result.add(data[i]);
	}
	return result;
}


