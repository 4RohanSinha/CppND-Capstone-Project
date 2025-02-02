#ifndef SURFACE_MANAGER_H
#define SURFACE_MANAGER_H

#include <vector>
#include <stdexcept>
#include "Surface.h"

class SurfaceManager {
public:
	void AddSource(std::string text, Font font);
	void AddSurface(Surface surface);
	Surface operator[](int i) const;
	int size() { return surfaces_.size(); }
private:
	std::vector<Surface> surfaces_;
};

#endif
