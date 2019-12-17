template <std::size_t N> struct num { static const constexpr auto value = N; };

/**
 * \brief A compile time for loo
 *
 * For loops in C++ are runtime constructs, and cannot be deduced statically at
 * compile time. Using a templatized version allows the expression to be
 * expanded at compile time.
 */
template <class F, std::size_t... Is>
void compile_for(F func, std::index_sequence<Is...>) {
    (func(num<Is>{}), ...);
}
