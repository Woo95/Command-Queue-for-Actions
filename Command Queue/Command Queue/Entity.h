#pragma once
#include <iostream>

class CObject
{
public:
	CObject() = default;
	virtual ~CObject() = default;

public:
	virtual void Update(float deltaTime) {}
};

class CPlayer : public CObject
{
public:
	CPlayer() = default;
	virtual ~CPlayer() = default;

public:
	void PlayerAction(float deltaTime)
	{
		std::cout << "Player Action!\n";
	}
};

class CMonster : public CObject
{
public:
	CMonster() = default;
	virtual ~CMonster() = default;

public:
	void MonsterAction(float deltaTime)
	{
		std::cout << "Monster Action!\n";
	}
};