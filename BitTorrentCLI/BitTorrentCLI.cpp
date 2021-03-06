// BitTorrentCLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace args;
using namespace std;

int main()
{
    ArgumentParser p("git-like parser");
    Group commands(p, "commands");
    Command add(commands, "add", "add file contents to the index");
    Command commit(commands, "commit", "record changes to the repository");
    Group arguments(p, "arguments", Group::Validators::DontCare, Options::Global);
    ValueFlag<string> gitdir(arguments, "path", "", { "git-dir" });
    HelpFlag h(arguments, "help", "help", { 'h', "help" });
    PositionalList<string> pathsList(arguments, "paths", "files to commit");

    try
    {
        p.ParseCLI(__argc, __argv);
        if (add)
        {
            std::cout << "Add";
        }
        else
        {
            std::cout << "Commit";
        }

        for (auto &&path : pathsList)
        {
            std::cout << ' ' << path;
        }

        std::cout << std::endl;
    }
    catch (args::Help)
    {
        std::cout << p;
    }
    catch (args::Error& e)
    {
        std::cerr << e.what() << std::endl << p;
        return 1;
    }
    return 0;
}

