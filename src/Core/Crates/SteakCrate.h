#pragma once
#include "../Crates/Crate.h"


class SteakCrate : public  Crate {

public:

	SteakCrate();

	void Draw() override;
	void Update() override;


	~SteakCrate() override;
};
