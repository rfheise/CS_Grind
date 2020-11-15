#ifndef _NAS_H_
#define _NAS_H_
#include <memory>
class Nas {
public:
	Nas();
	Nas(const char *name);
	~Nas();
	std::unique_ptr<char[]>& getName() {
		return name;
	}
private:
	std::unique_ptr<char[]> name;
};

#endif
