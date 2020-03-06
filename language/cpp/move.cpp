template <typename T>
typename remove_reference<T>::type &&move(T &&t) {
    return static_case<typename remove_reference<T>::type &&>(t);
}
