#pragma once
#include <queue>
#include <functional>

struct FCommand
{
	using Action = std::function<void(float)>;

	Action action;
};

class CCommandQueue
{
public:
	CCommandQueue() = default;
	~CCommandQueue() = default;

private:
	std::queue<FCommand> mQueue;

public:
	void Enqueue(const FCommand& command)
	{
		mQueue.push(command);
	}

	FCommand Dequeue()
	{
		if (IsEmpty())
			return FCommand{};

		FCommand cmd = mQueue.front();
		mQueue.pop();

		return cmd;
	}

	bool IsEmpty() const
	{
		return mQueue.empty();
	}
};