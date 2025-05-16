#include <iostream>
#include <crtdbg.h>
#include "Scene.h"

#define FakeDeltaTime 0.016f

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CScene*   scene   = new CScene;
	CPlayer*  player  = new CPlayer;
	CMonster* monster = new CMonster;

	scene->AddObject(player);
	scene->AddObject(monster);

	// This simulates 5 frames, pushing and executing one command per frame.
	for (int frame = 1; frame <= 5; frame++)
	{
		std::cout << ">> [Frame " << frame << "] <<\n";

		FCommand cmd;
		cmd.action = [player, monster, frame](float dt)
		{
			if (frame % 2 == 0)
				player->PlayerAction(dt);
			else
				monster->MonsterAction(dt);
		};
		scene->PushCommand(cmd);

		scene->Update(FakeDeltaTime);

		std::cout << "\n";
	}
	delete scene;

	return 0;
}