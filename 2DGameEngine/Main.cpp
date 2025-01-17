#include "Game.h"

int main()
{
    Game game; 

    while (game.IsRunning())
    {
        game.CaptureInput();
        game.Update();
        game.LateUpdate();
        game.Draw();
        game.CalculateDeltaTime();
    }

    return 0;
}