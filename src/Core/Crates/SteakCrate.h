#include "raylib.h"

class SteakCrate {

public:

	SteakCrate();

	float posX;
	float posY;
	float posZ;
    
    Model crateModel;
    Vector3 position;
	BoundingBox baseBox;
	BoundingBox worldBox;

	void Draw();
	void Update();
	void UpdateBoundingBox();

	~SteakCrate();
};
