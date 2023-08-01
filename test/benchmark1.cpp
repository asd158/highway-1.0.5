#include <benchmark/benchmark.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "hwy/aligned_allocator.h"
#include "hwy/base.h"

// clang-format off
#undef HWY_TARGET_INCLUDE
#define HWY_TARGET_INCLUDE "test/benchmark1.cpp"

#include "hwy/foreach_target.h"  // IWYU pragma: keep
#include "hwy/highway.h"
#include "hwy/contrib/dot/dot-inl.h"

HWY_BEFORE_NAMESPACE();
namespace hwy {
    namespace HWY_NAMESPACE {
        template<typename T>
        HWY_NOINLINE T SimpleDot(const T *pa,
                                 const T *pb,
                                 size_t num) {
            double      sum = 0.0;
            for (size_t i   = 0;
                 i < num;
                 ++i) {
                sum += pa[i] * pb[i];
            }
            return static_cast<T>(sum);
        }

        HWY_NOINLINE float SimpleDot(const bfloat16_t *pa,
                                     const bfloat16_t *pb,
                                     size_t num) {
            float       sum = 0.0f;
            for (size_t i   = 0;
                 i < num;
                 ++i) {
                sum += F32FromBF16(pa[i]) * F32FromBF16(pb[i]);
            }
            return sum;
        }
    }
}
HWY_AFTER_NAMESPACE();

#if HWY_ONCE
int main() {
    return 0;
}
#endif
