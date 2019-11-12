#ifndef FIGURES_H
#define FIGURES_H
#include <iostream>
#include <tuple>
#include <cmath>


template <class T>
struct Pentagon {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a;T R;
    Pentagon(T x1, T y1, T R) : a(x1, y1), R(R)
    {}
};

template <class T>
struct Hexagon {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a; T R;
    Hexagon(T x1, T y1, T R) : a(x1, y1), R(R)
    {}
};

template <class T>
struct Octagon {
    using type = T;
    using vertex_t = std::pair<T,T>;
    vertex_t a;T R;
    Octagon(T x1, T y1, T R) : a(x1, y1), R(R)
    {}
};

template <class T>
bool check(T R) {
    if(R > 0) {
        return true;
    } else {
        std::cout << "Error" << std::endl;
        return false;
    }
}

template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Hexagon<T> >::value, F<T> >::type information(F<T> h) {
    std::cout << "Hexagon :" << std::endl;
    std::cout << "Center point (" << h.a.first << "," << h.a.second << ")" << std::endl;
    T sq, x, y, angle;
    sq = 3 * sin(M_PI / 3) * h.R * h.R;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 6; i++) {
        angle =  M_PI * i / 3;
        x = h.R * cos(angle) + h.a.first;
        y = h.R * sin(angle) + h.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    return h;
}

template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Octagon<T> >::value, F<T> >::type information2(F<T> o) {
    std::cout << "Octagon :" << std::endl;
    std::cout << "Center point (" << o.a.first << "," << o.a.second << ")" << std::endl;
    T sq,x,y,angle;
    sq = 4 * sin(M_PI / 4) * o.R * o.R;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 8; i++) {
        angle =  M_PI * i / 4;
        x = o.R * cos(angle) + o.a.first;
        y = o.R * sin(angle) + o.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    return o;
}

template <template <class> class F, class T>
typename std::enable_if< std::is_same< F<T>, Pentagon<T> >::value, F<T> >::type information3(F<T> pe) {
    std::cout << "Pentagon :" << std::endl;
    std::cout << "Center point (" << pe.a.first << "," << pe.a.second << ")" << std::endl;
    T sq, x, y, angle;
    sq = 5 * sin(2*M_PI / 5) * pe.R * pe.R;
    std::cout << "Area : " << sq << std::endl;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 5; i++) {
        angle =  2*M_PI * i / 5;
        x = pe.R * cos(angle) + pe.a.first;
        y = pe.R * sin(angle) + pe.a.second;
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
    return pe;
}

template <class T>
void information(std::tuple<std::pair<T,T>> Hexagon,T R) {
    std::cout << "Hexagon :" << std::endl;
    T sq, hx, hy;
    std::cout << "Center point (" << std::get<0>(Hexagon).first << "," << std::get<0>(Hexagon).second << ")" << std::endl;
    sq = 3 * sin(M_PI / 3) * R * R;
    std::cout << "Area : " << sq << std::endl;
    T angle;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 6; i++) {
        angle =  M_PI * i / 3;
        hx = R * cos(angle) + std::get<0>(Hexagon).first;
        hy = R * sin(angle) + std::get<0>(Hexagon).second;
        std::cout << "(" << hx << "," << hy << ")" << std::endl;
    }
}

template <class T>
void information2(std::tuple<std::pair<T,T>> Octagon,T R) {
    std::cout << "Octagon :" << std::endl;
    T sq, ox, oy;
    std::cout << "Center point (" << std::get<0>(Octagon).first << "," << std::get<0>(Octagon).second << ")" << std::endl;
    sq = 4 * sin(M_PI / 4) * R * R;
    std::cout << "Area : " << sq << std::endl;
    T angle;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 8; i++) {
        angle =  M_PI * i / 4;
        ox = R * cos(angle) + std::get<0>(Octagon).first;
        oy = R * sin(angle) + std::get<0>(Octagon).second;
        std::cout << "(" << ox << "," << oy << ")" << std::endl;
    }
}

template <class T>
void information3(std::tuple<std::pair<T,T>> Pentagon,T R) {
    std::cout << "Pentagon :" << std::endl;
    T sq, pex, pey;
    std::cout << "Center point (" << std::get<0>(Pentagon).first << "," << std::get<0>(Pentagon).second << ")" << std::endl;
    sq = 5 * sin(2*M_PI / 5) * R * R;
    std::cout << "Area : " << sq << std::endl;
    T angle;
    std::cout << "Coordinates :" << std::endl;
    for(int i = 0; i < 5; i++) {
        angle = 2*M_PI * i / 5;
        pex = R * cos(angle) + std::get<0>(Pentagon).first;
        pey = R * sin(angle) + std::get<0>(Pentagon).second;
        std::cout << "(" << pex << "," << pey << ")" << std::endl;
    }
}

#endif
