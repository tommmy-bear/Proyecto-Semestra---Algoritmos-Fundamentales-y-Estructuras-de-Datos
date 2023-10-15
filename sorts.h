#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
    void swap(typename std::list<T>::iterator, typename std::list<T>::iterator);
    void merge(typename std::list<T>::iterator, typename std::list<T>::iterator);
    typename std::list<T>::iterator mergeSort(typename std::list<T>::iterator, int);

public:
    void ordenaBurbuja(std::list<T>&);
    void ordenaSeleccion(std::list<T>&);
    void ordenaMerge(std::list<T>&);
    typename std::list<T>::iterator busqSecuencial(const std::list<T>&, int valor);
    typename std::list<T>::iterator busqBinaria(const std::list<T>&, int valor);

    // Funciones adicionales para trabajar con una lista doblemente enlazada
    void insertar(std::list<T>&, const T&);
    void printList(const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(typename std::list<T>::iterator it1, typename std::list<T>::iterator it2) {
    std::iter_swap(it1, it2);
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::list<T> &source) {
    for (auto i = source.begin(); i != source.end(); ++i) {
        for (auto j = source.begin(); j != std::prev(source.end()); ++j) {
            auto next = std::next(j);
            if (*j > *next) {
                swap(j, next);
            }
        }
    }
}

template <class T>
void Sorts<T>::ordenaSeleccion(std::list<T> &source) {
    for (auto i = source.begin(); i != std::prev(source.end()); ++i) {
        auto min = i;
        for (auto j = std::next(i); j != source.end(); ++j) {
            if (*j < *min) {
                min = j;
            }
        }
        if (min != i) {
            swap(i, min);
        }
    }
}

template <class T>
void Sorts<T>::merge(typename std::list<T>::iterator left, typename std::list<T>::iterator right) {
    std::list<T> result;
    while (left != right && left != std::prev(right)) {
        if (*left < *std::next(left)) {
            result.push_back(*left);
            ++left;
        } else {
            result.push_back(*std::next(left));
            left = std::next(left, 2);
        }
    }
    if (left != right) {
        result.push_back(*left);
    }
    left = result.begin();
    while (left != result.end()) {
        *std::next(right, std::distance(left, result.end())) = *left;
        ++left;
    }
}

template <class T>
typename std::list<T>::iterator Sorts<T>::mergeSort(typename std::list<T>::iterator left, int size) {
    if (size <= 1) return left;
    int middle = size / 2;
    typename std::list<T>::iterator right = std::next(left, middle);
    left = mergeSort(left, middle);
    right = mergeSort(right, size - middle);
    merge(left, right);
    return left;
}

template <class T>
void Sorts<T>::ordenaMerge(std::list<T> &source) {
    if (source.size() > 1) {
        source.begin() = mergeSort(source.begin(), source.size());
    }
}

template <class T>
typename std::list<T>::iterator Sorts<T>::busqSecuencial(const std::list<T> &source, int valor) {
    for (auto it = source.begin(); it != source.end(); ++it) {
        if (*it == valor) {
            return it;
        }
    }
    return source.end();
}

template <class T>
typename std::list<T>::iterator Sorts<T>::busqBinaria(const std::list<T> &source, int valor) {
    int low = 0;
    int high = source.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        auto it = std::next(source.begin(), mid);
        if (*it == valor) {
            return it;
        }
        if (*it < valor) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return source.end();
}

template <class T>
void Sorts<T>::insertar(std::list<T>& lista, const T& elemento) {
    lista.push_back(elemento);
}

template <class T>
void Sorts<T>::printList(const std::list<T>& lista) {
    for (const T& elemento : lista) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

#endif /* SORTS_H_ */
