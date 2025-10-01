template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;

    auto result = first;
    while(++first != last) {
        if (!(*result == *first)) {
            ++result;
            *result = *first;
        }
    }
    return ++result;
}