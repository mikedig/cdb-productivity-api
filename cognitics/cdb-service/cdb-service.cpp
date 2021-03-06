
#include <cdb_util/cdb_service.h>

#include <ccl/LogStream.h>
#include <ccl/ObjLog.h>
#include <ccl/ArgumentParser.h>

#include <cstdlib>
#include <fstream>
#include <chrono>

int main(int argc, char** argv)
{
    ccl::Log::instance()->attach(ccl::LogObserverSP(new ccl::LogStream(ccl::LDEBUG)));

    auto args = cognitics::ArgumentParser();
    args.AddOption("logfile", 1, "<filename>", "filename for log output");
    args.AddOption("bind", 1, "<bind string>", "bind string (port or ip:port)");
    args.AddOption("cdb", 1, "<cdbpath>", "path to CDB");
    if(args.Parse(argc, argv) == EXIT_FAILURE)
        return EXIT_FAILURE;

    std::ofstream logfile;
    if(args.Option("logfile"))
    {
        auto logfn = args.Parameters("logfile").at(0);
        logfile.open(logfn.c_str(), std::ios::out);
        ccl::Log::instance()->attach(ccl::LogObserverSP(new ccl::LogStream(ccl::LDEBUG, logfile)));
    }

    auto params = cognitics::cdb::cdb_service_parameters();
    if(args.Option("cdb"))
        params.cdb = args.Parameters("cdb").at(0);
    if(args.Option("bind"))
        params.bind = args.Parameters("bind").at(0);

    ccl::ObjLog log;
    log << args.Report() << log.endl;

    auto ts_start = std::chrono::steady_clock::now();
    bool result = cognitics::cdb::cdb_service(params);
    auto ts_stop = std::chrono::steady_clock::now();

    log << log.endl;
    log << "cdb-service runtime: " << std::chrono::duration<double>(ts_stop - ts_start).count() << "s" << log.endl;
    
    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}


