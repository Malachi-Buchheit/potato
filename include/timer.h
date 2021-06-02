#pragma once

#include <ctime>

class Timer {
    private:
    clock_t start;

    public:
    Timer() {
        start = clock();
    }

    void reset() {
        start = clock();
    }

    /**
     * Time elapsed in seconds.
     */
    float elapsed() {
        clock_t t = clock();
        return (double)(t-start) / CLOCKS_PER_SEC;
    }

    /**
     * Time elapsed in milliseconds.
     */
    float ms_elapsed() {
        clock_t t = clock();
        return 1000 * (double)(t-start) / CLOCKS_PER_SEC;
    }
};
