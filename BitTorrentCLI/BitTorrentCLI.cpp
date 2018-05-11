// BitTorrentCLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace clara;
using namespace std;

int main()
{
    bool privateTorrent = false;
    std::string command;
    auto cli
        = Opt(privateTorrent)
        ["-p"]["--private"]
        ("Is torrent private?")
        | Arg(command, "command")
        ("which command to run");

    auto result = cli.parse(Args(__argc, __argv));
    if (!result) {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
        exit(1);
    }

    cout << command << endl;
    cout << privateTorrent << endl;

    return 0;
}

