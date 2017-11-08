#pragma once

struct RandomGenerator;
struct RandomOperations
{
    void (*destroy)(struct RandomGenerator *);
    double (*next_double)(struct RandomGenerator *);
    int (*next_int)(struct RandomGenerator *, int a, int b);
};
struct RandomGenerator
{
    const struct RandomOperations *ops;
};

struct RandomFactory;
struct RandomFactoryOperations
{
    void (*destroy)(struct RandomFactory *);
    struct RandomGenerator *(*new_instance)(struct RandomFactory *, const char *args);
};
struct RandomFactory
{
    const struct RandomFactoryOperations *ops;
};
