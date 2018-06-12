#ifndef PUBLIC_TRANSPORT_COUNTED_HPP
#define PUBLIC_TRANSPORT_COUNTED_HPP

#include <cstddef>

template <typename T>
class Counted {
public:
    Counted();
    Counted(const Counted& counted);
    Counted(Counted &&counted) noexcept;
    ~Counted();

    static std::size_t getInstancesCount();
private:
    static std::size_t instances;
};

template<typename T>
std::size_t Counted<T>::instances = 0;

template<typename T>
Counted<T>::Counted() {
    Counted<T>::instances++;
}

template<typename T>
Counted<T>::Counted(const Counted &counted) {
    Counted<T>::instances++;
}

template<typename T>
Counted<T>::Counted(Counted &&counted) noexcept {
    Counted<T>::instances++;
}

template<typename T>
Counted<T>::~Counted() {
    Counted<T>::instances--;
}

template<typename T>
std::size_t Counted<T>::getInstancesCount() {
    return Counted<T>::instances;
}


#endif //PUBLIC_TRANSPORT_COUNTED_HPP
