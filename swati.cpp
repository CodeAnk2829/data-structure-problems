#include <iostream>
#include <numeric>
#include <algorithm>

using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

bool can_complete(ll T, ll c1, ll d1, ll c2, ll d2) {
    if (T - T / c1 < d1) {
        return false;
    }
    if (T - T / c2 < d2) {
        return false;
    }

    ll common_mult = lcm(c1, c2);

    ll slots_for_d1_only = T / c2 - T / common_mult;
    ll slots_for_d2_only = T / c1 - T / common_mult;
    ll shared_slots = T - (T / c1 + T / c2 - T / common_mult);

    ll d1_needs_shared = (d1 > slots_for_d1_only) ? (d1 - slots_for_d1_only) : 0;
    ll d2_needs_shared = (d2 > slots_for_d2_only) ? (d2 - slots_for_d2_only) : 0;

    return d1_needs_shared + d2_needs_shared <= shared_slots;
}

long minDeliveryTime(int charge1, int delivery1, int charge2, int delivery2) {
    ll c1 = charge1, d1 = delivery1, c2 = charge2, d2 = delivery2;

    ll low = 1, high = 40000000000000LL;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (can_complete(mid, c1, d1, c2, d2)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // Sample Case 0
    int charge1_0 = 2;
    int delivery1_0 = 1;
    int charge2_0 = 2;
    int delivery2_0 = 3;
    long result_0 = minDeliveryTime(charge1_0, delivery1_0, charge2_0, delivery2_0);
    std::cout << "Sample Case 0 Input: charge1=2, delivery1=1, charge2=3, delivery2=2" << std::endl;
    std::cout << "Sample Case 0 Output: " << result_0 << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // Sample Case 1
    int charge1_1 = 3;
    int delivery1_1 = 2;
    int charge2_1 = 4;
    int delivery2_1 = 1;
    long result_1 = minDeliveryTime(charge1_1, delivery1_1, charge2_1, delivery2_1);
    std::cout << "Sample Case 1 Input: charge1=3, delivery1=3, charge2=4, delivery2=1" << std::endl;
    std::cout << "Sample Case 1 Output: " << result_1 << std::endl;

    return 0;
}