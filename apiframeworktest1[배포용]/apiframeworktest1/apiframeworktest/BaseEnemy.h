#pragma once
#include "Object.h"

class FaceObj;

class BaseEnemy :
    public Object
{
public:
    BaseEnemy();
    virtual ~BaseEnemy();

private:
    CLONE(BaseEnemy);

public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther) override;

public:
    virtual void ExecutePattern();

public:
    void        SetPattern(int pattern) { m_iPattern = pattern; }
    
private:
    int         m_iPattern;
    
private:
    FaceObj*    m_FaceObject;

    vector<Object*> m_vPatternObjs;
};

