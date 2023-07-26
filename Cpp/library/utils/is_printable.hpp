#include "../IO.hpp"

template<typename _Tp, typename dummy = void>
struct is_printable : std::false_type {};

template<typename _Tp>
struct is_printable<_Tp,
                    typename std::enable_if_t<std::is_same_v<
                        std::remove_reference_t<
                            decltype(std::cout << std::declval<_Tp>())>,
                        std::ostream>>> :
    std::true_type {
};

template<typename _Tp>
inline constexpr bool is_printable_v = is_printable<_Tp>::value;
