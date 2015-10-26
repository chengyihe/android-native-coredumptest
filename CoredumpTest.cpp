#define LOG_TAG "CoredumpTest"

#include <utils/Log.h>
#include <string.h>
#include <sys/resource.h>

using namespace android;

void test4()
{
    int len;

    ALOGD("Ready to crash");
    ALOGD("strlen(NULL) = %d",  strlen(NULL));
}

void test3()
{
    test4();
}

void test2()
{
    test3();
}

void test1()
{
    test2();
}

int main()
{
    struct rlimit core_limit;
    core_limit.rlim_cur = RLIM_INFINITY;
    core_limit.rlim_max = RLIM_INFINITY;

    if (setrlimit(RLIMIT_CORE, &core_limit) < 0) {
        ALOGD("Failed to setrlimit: %s", strerror(errno));
        return 1;
    }

    ALOGD("Ready to enter test");
    test1();

    return 0;
}
