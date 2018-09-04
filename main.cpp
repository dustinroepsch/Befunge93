#include <iostream>
#include <fstream>
#include "src/FungeInterpreter.h"

#include <boost/program_options.hpp>

int main(int ac, const char* av[]) {
    namespace po = boost::program_options;
    po::options_description desc("How to use Befunge93");
    desc.add_options()
            ("help", "Produce this help message")
            ("filepath", po::value<std::string>(), "Path to the befunge program to execute");


    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    if (!vm.count("filepath")) {
        std::cout << "use --filepath to tell Befunge93 what program to run." << std::endl;
        return -1;
    }

    FungeInterpreter interpreter;
    std::ifstream file(vm["filepath"].as<std::string>());
    interpreter.LoadProgram(file);
    file.close();

    while (interpreter.IsExecuting()) {
        interpreter.Tick();
    }
    return 0;
}