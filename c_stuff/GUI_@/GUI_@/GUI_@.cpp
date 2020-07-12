#define OLC_PGE_APPLICATION

#include "JGThreeD.h"

int main()
{
	TCEExample app;
	if (app.Construct(512, 350, 1, 1, false, true)) app.Start();
	return 0;
}