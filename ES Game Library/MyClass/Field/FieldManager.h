#pragma once

#include"../../ESGLib.h"

class FieldManager {
public:
    FieldManager::FieldManager();
    FieldManager::~FieldManager();

    bool    Initialize();
    void    Draw();
    Vector3 Position();

private:
    MODEL  _model;
};