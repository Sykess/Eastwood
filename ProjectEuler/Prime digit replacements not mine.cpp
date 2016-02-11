#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIMIT 1000000
#define MAX_FAILS 2

bool sieve[LIMIT] = {0};
int primes[LIMIT];
int pc = 0;

void fill_sieve() {
    for (int i = 2; i * i < LIMIT; ++i) {
        if (sieve[i]) continue;
        for (int j = 2 * i; j < LIMIT; j += i) sieve[j] = true;
    }
}

void fill_primes() {
    fill_sieve();
    int *cur = primes;
    for (int i = 2; i < LIMIT; ++i) {
        if (!sieve[i]) { ++pc; *cur++ = i; }
    }
}

int md(int v, int i) {
    static int shift[] = {1, 10, 100, 1000, 10000, 100000};
    return (v / shift[i]) % 10;
}

int aand(int v, int m) {
    int res = 0;
    int mul = 1;
    for (; m; m /= 2, mul *= 10) {
        if (m % 2) res += ((v / mul) % 10) * mul;
    }
    return res;
}

bool check_with_mask(int p, int l, int mask, int start, int idx) {
    if (!mask) return false;
    if (idx == l) {
        int fails = start;
        int cur = p;
        int d = aand(1111111, mask);
        for (int i = start + 1; fails <= MAX_FAILS && i <= 9; ++i) {
            cur += d;
            if (sieve[cur]) ++fails;
        }
        if (fails <= MAX_FAILS) {
            printf("%d (", p);
            cur = p;
            const char *sep = "";
            for (int i = start + 1; i <= 9; ++i) {
                cur += d;
                if (!sieve[cur]) {
                    printf("%s%d", sep, cur);
                    sep = ", ";
                }
            }
            puts(")");
            return true;
        }
        return false;
    }
    
    int mult = 1 << idx;
    if (mask & mult) {
        if (check_with_mask(p, l, mask ^ mult, start, idx + 1)) return true;
    }
    return check_with_mask(p, l, mask, start, idx + 1);
}

bool check_with_start(int p, int l, int start) {
    int mask = 0; int mult = 1;
    for (int i = 0; i < l; ++i, mult *= 2) {
        if (md(p, i) == start) mask += mult;
    }
    return check_with_mask(p, l, mask, start, 0);
}

bool check(int p, int l) {
    if (check_with_start(p, l, 0)) return true;
    if (check_with_start(p, l, 1)) return true;
    if (check_with_start(p, l, 2)) return true;
    return false;
}

int main() {
    fill_primes();
    int limit = 10;
    int length = 1;
    for (int i = 0; i < pc; ++i) {
        int p = primes[i];
        for (; limit <= p; limit *= 10, ++length);
        if (check(p, length)) break;
    }
}
