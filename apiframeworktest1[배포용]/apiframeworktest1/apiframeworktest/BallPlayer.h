#pragma once
#include "BaseMoveCircle.h"

class Image;

class BallPlayer :
    public BaseMoveCircle
{
public:
    BallPlayer();
    BallPlayer(KEY upKey, KEY downKey);
    virtual ~BallPlayer();

private:
    CLONE(BallPlayer);

public:
    //void Init()          override;
    void Update()        override;

    KEY     m_kUpKey;
    KEY     m_kDownKey;
};
