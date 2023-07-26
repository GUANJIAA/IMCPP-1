#include "LoginService.h"
#include "mysqldb.h"
#include "redisdb.h"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);

    connection_pool::GetInstance()->init();

    // RedisOpt::GetInstance()->LoginRun();

    RpcProvider provider;
    provider.NotifyService(new LoginService());

    provider.Run();

    return 0;
}