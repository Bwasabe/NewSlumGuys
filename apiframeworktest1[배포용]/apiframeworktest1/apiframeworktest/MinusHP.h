#pragma once
#include "Object.h"
class Image;
class MinusHP :
    public Object
{
private:
     int  m_hp;
public:
    MinusHP();
    ~MinusHP();

    CLONE(MinusHP);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    void SetHP(int _value) { m_hp = _value; }
    int GeHP() { return m_hp; }
};

