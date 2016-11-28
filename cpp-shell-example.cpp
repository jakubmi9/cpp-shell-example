// cpp-shell-example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../cpp-shell/cpp-shell.h"

int main()
{
	const std::string greet = "testing program for cpp-shell v0.1\nLicensed under GNU GPLv3";
	const std::string prompt = "test";
	bool loaded = 0;
	sh::shell *main = new sh::shell(greet, prompt);
	while(true)
	{
		main->prompt();
		if(main->command[0] == "exit")
		{
			if(loaded)
			{
				std::cout << "module is loaded. are you sure? Y/N" << std::endl;
				main->subprompt();
				if(main->command[1] == "Y" || main->command[1] == "y")
				{
					delete main;
					std::system("pause");
					return 0;
				}
			}
			else
			{
				delete main;
				std::system("pause");
				return 0;
			}
		}
		if(main->command[0] == "list")
		{
			while(true)
			{
				try
				{
					if(main->command.at(1) == "users")
					{
						if(main->command.at(2) == "nearby")
						{
							if(main->command.size() != 3)
							{
								std::cout << "invalid syntax!" << std::endl;
								break;
							}
							std::cout << "Nearby users:" << std::endl;
							break;
						}
						else
						{
							std::cout << "invalid syntax!" << std::endl;
							break;
						}
					}
					else
					{
						std::cout << "invalid syntax!" << std::endl;
						break;
					}
				}
				catch(const std::out_of_range&)
				{
					main->subprompt();
				}
			}
		}
		if(main->command[0] == "load")
		{
			main->submodule("module");
			loaded = 1;
		}
		if(main->command[0] == "unload")
		{
			main->submodule();
			loaded = 0;
		}
		main->command.clear();
	}
}

