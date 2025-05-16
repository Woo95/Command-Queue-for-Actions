#pragma once
#include <vector>
#include "Entity.h"
#include "CommandQueue.h"

class CScene
{
public:
	CScene() = default;
	virtual ~CScene()
	{
		for (CObject* obj : mObjects)
			delete obj;
	}

private:
	CCommandQueue mCommandQueue;

	std::vector<CObject*> mObjects;

public:
	void Update(float deltaTime)
	{
		// Process all pending commands
		while (!mCommandQueue.IsEmpty())
		{
			FCommand cmd = mCommandQueue.Dequeue();
			if (cmd.action)
				cmd.action(deltaTime);
		}

		// Update objects
		for (CObject* obj : mObjects)
			obj->Update(deltaTime);
	}

	void AddObject(CObject* obj)
	{
		mObjects.push_back(obj);
	}

	void PushCommand(const FCommand& command)
	{
		mCommandQueue.Enqueue(command);
	}
};