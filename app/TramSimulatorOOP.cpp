#include "TramSimulatorOOP.h"

using namespace std;

int main(){
	TrafficManager* mainManager = TrafficManager::GetInstance(8);
	mainManager->ReadCSVData();
	mainManager->Setup();
	mainManager->RunSimulation();
	mainManager->WriteCSVData();
	return 0;
}
