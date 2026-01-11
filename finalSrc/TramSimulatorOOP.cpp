#include "TramSimulatorOOP.h"

using namespace std;

int main()
{
	TrafficManager* mainManager = TrafficManager::GetInstance();
	mainManager->ReadCSVData();
	mainManager->Setup();
	mainManager->RunSimulation();
	mainManager->WriteCSVData();
	return 0;
}
