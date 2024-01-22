//
// Created by enrico on 1/9/24.
//

#ifndef COMMONS_VECTOR_CUSTOM_H
#define COMMONS_VECTOR_CUSTOM_H
#include <stdexcept>

namespace stdlibfac
{

	class Vector
	{
		double* elem;
		int sz;
	 public:

		explicit Vector (int s);

		Vector (std::initializer_list<double>); // inizializzatore di lista

		Vector (const Vector& a);            // costruttore di copia
		Vector& operator= (const Vector& a); // assegnazione della copia

		Vector (Vector&& a) noexcept ;                 // costruttore di spostamento
		Vector& operator= (Vector&& a) noexcept ;//assegnazione di spostamento

		double& operator[] (int i);
		const double& operator[] (int i) const;

		int size () const
		{
			return sz;
		}
		void push_back (double);
		void print ();

		~Vector ()
		{
			delete[] elem;
		}
	};

// DEFINIZIONI

	Vector::Vector (int s)
		: elem{ new double[s] },
		  sz{ s }
	{
		for (int i = 0; i < s; ++ i)
			elem[i] = 0;
	}

	Vector::Vector (const Vector& a) //costruttore di copia
		: elem{ new double[a.sz] },
		  sz{ a.sz }
	{
		for (int i = 0; i < sz; ++ i)
			elem[i] = a.elem[i];
	}

	Vector::Vector (std::initializer_list<double> lst)
		: elem{ new double[lst.size ()] },
		  sz{ static_cast<int>(lst.size ()) }
	{
		std::copy (lst.begin (), lst.end (), elem);
	}

	double& Vector::operator[] (int i)
	{
		if (! (i >= 0 && i < sz))
		{
			throw std::out_of_range{ "stdlibfac::Vector::operator[]" };
		}
		return elem[i];
	}

	void Vector::push_back (double new_d)
	{
		// alloco nuovo vettore
		auto* _elem = new double[sz + 1];
		// copio vecchi dati
		for (int i = 0; i < sz; ++ i)
			_elem[i] = elem[i];
		_elem[sz] = new_d;

		// libero vecchie risorse
		delete[] elem;

		// aggiorno risorse
		elem = _elem;
		sz ++;
	}

	void Vector::print ()
	{
		std::cout << "[ ";
		for (int i = 0; i < sz; ++ i)
		{
			std::cout << elem[i] << ' ';
		}
		std::cout << "]" << std::endl;
	}

	Vector& Vector::operator= (const Vector& a)
	{
		auto* p = new double[a.sz];
		for (int i = 0; i != a.sz; ++ i)
			p[i] = a.elem[i];
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}

	Vector::Vector (Vector&& a) noexcept
		:elem{a.elem},  // preleva gli elementi da a
		sz{a.sz}
	{
		a.elem = nullptr;
		a.sz = 0;
	}

	Vector& Vector::operator=(Vector&& a) noexcept
	{
		elem = a.elem;
		sz = a.sz;
		a.elem = nullptr;
		a.sz = 0;
	}

	Vector operator+(const Vector& a, const Vector& b)
	{
		if (a.size() != b.size())
		{
			throw std::length_error{"length mismatch"};
		}
		Vector res(a.size());

		for (int i = 0; i != a.size(); ++i)
		{
			res[i] = a[i] + b[i];
		}

		return res;
	}

	const double& Vector::operator[](int i) const
	{
		if (! (i >= 0 && i < sz))
		{
			throw std::out_of_range{ "stdlibfac::Vector::operator[]" };
		}
		return elem[i];
	}
}

#endif //COMMONS_VECTOR_CUSTOM_H
