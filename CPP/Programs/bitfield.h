#include <cstdlib>

class bitfield {
	private:
		bool* data;
		unsigned long length;
	public:
		bitfield(const unsigned long nlength);
		~bitfield();
		bool get(const unsigned long index);
		void set(const unsigned long index) const;
};

bitfield::bitfield(const unsigned long nlength)
{
	data = (bool*)malloc(nlength);
	length = nlength;
	for(unsigned long counter = 0; counter < nlength; ++counter)
		data[counter] = false;
};
bitfield::~bitfield()
{
	free(data);
};
bool bitfield::get(const unsigned long index)
{
	return(data[index-1]);
};
void bitfield::set(const unsigned long index) const
{
	data[index-1] = true;
};
