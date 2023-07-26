#pragma once
#include "IO.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<typename T>
using ordered_set = tree<T,
                         null_type,
                         less<T>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;

template<typename T>
using ordered_multiset = tree<T,
                              null_type,
                              less_equal<>,
                              rb_tree_tag,
                              tree_order_statistics_node_update>;