#define LOG_TAG "CoredumpTest"

#include <utils/Log.h>
#include <string.h>
#include <sys/resource.h>

using namespace android;

int test4()
{
    int ret = strlen(NULL);

    ALOGD("enter %s: %d", __func__,  ret);

    return ret;
}

int test3()
{
    int ret = test4() + 3;

    ALOGD("enter %s: %d", __func__, ret);

    return ret;
}

int test2()
{
    int ret = test3() + 2;

    ALOGD("enter %s: %d", __func__, ret);

    return ret;
}

int test1()
{
    int ret = test2() + 1;

    ALOGD("enter %s: %d", __func__, ret);

    return ret;
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

    int n = test1();
    ALOGD("Ready to enter test");

    return 0;
}
