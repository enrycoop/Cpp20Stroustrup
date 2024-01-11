//
// Created by dev on 1/11/24.
//

#ifndef COMMONS_CONTAINER_CUSTOM_H
#define COMMONS_CONTAINER_CUSTOM_H

#include <iostream>
#include <list>
#include "vector_custom.h"

namespace stdlibfac {


    class Container {
    public:
        virtual double& operator[](int) =0;          // funzione virtuale pura
        virtual int size() const =0;                 // funzione membro const
        virtual ~Container() {}                      // distruttore
    };



    class Vector_container : public Container {
    public:
        Vector_container(int s) : v(s) { }
        ~Vector_container() {}

        double& operator[](int i) override { return v[i]; }
        int size() const override { return v.size(); }

    private:
        Vector v;
    };

    class List_container : public Container {
    public:
        List_container() = default;
        List_container(std::initializer_list<double> il) : ld{il} { }
        ~List_container() override = default;

        double& operator[](int i) override;
        int size() const override { return ld.size(); }
    private:
        std::list<double> ld;
    };

    double& List_container::operator[](int i)
    {
        for (auto& x : ld) {
            if (i==0)
                return x;
            --i;
        }
        throw std::out_of_range{"List_container"};
    }

    void use(Container& c) {
        const int sz = c.size();
        for (int i=0; i<sz; ++i)
            std::cout << c[i] << " ";
    }

    void h() {
        List_container lc = {1,2,3,4,5,6,7,8};
        use(lc);
    }


}

#endif //COMMONS_CONTAINER_CUSTOM_H
