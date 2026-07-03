#pragma once // prevents multiple includes

#include "Animal.h"

class Chicken : public Animal {
    public:
        
        Chicken();
        void update(float dt) override;
};