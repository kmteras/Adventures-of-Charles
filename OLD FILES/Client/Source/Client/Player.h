#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "../Shared/Entity.h"

class Player : public Entity {
    std::string name;
public:
    Player();
    void Draw();
    void Update();
};

#endif