export module Renderer.Vec3;
import <math.h>;
import <iostream>;
namespace renderer {
	export struct vec3 {
	public:
		vec3();
		vec3(double x, double y, double z);
		double x()const;
		double y()const;
		double z()const;
		vec3 operator-() const;
		double operator[] (int i) const;
		double& operator[](int i);
		vec3& operator+=(const vec3& v);

		vec3& operator*=(const double t);

		vec3& operator/=(const double t);

		double length() const;

		double length_squared() const;
		/*
		* I just wanted that e to be private
		* so I overide those operater as friend member function
		* if you don't you can make e to be public 
		* then every override will be normal functions
		* all friend functions right here are just for calculation
		* and all just using const refs
		* when I was a student, my teacher told me not to use friend keyword
		* but in this situation using friend functions is alright
		*/
		friend inline std::ostream& operator<<(std::ostream& out, const vec3& v);
		friend inline vec3 operator+(const vec3& u, const vec3& v);
		friend inline vec3 operator-(const vec3& u, const vec3& v);
		friend inline vec3 operator*(const vec3& u, const vec3& v);
		friend inline vec3 operator*(const vec3& v, double t);
		friend inline double dot(const vec3& u, const vec3& v);
		friend inline vec3 cross(const vec3& u, const vec3& v);
	private:
		double e[3];
	};
	export using point3 = vec3;
	export using color = vec3;
};
/*
* Interface vec3
* you can got your own implementation if you want
*/


/*
* Default Implementations for vec3
* just a consult
* not the best (may not even a good one)
* and not sure if this will be high performance or not
* as this is a vec type,
* you could use some template magic or macro skill to implement those
* like template args for how many dimensions is used
* or use macro to specified deferent vec type by some thing like ifdef/ifndef
* and also you could have the vector type from std library as your storage of data
* there may be thousands of implementation of vector
* just using the one you like
*/

namespace renderer {

	vec3::vec3() : e{ 0,0,0 } {}

	vec3::vec3(double x, double y, double z) : e{ x,y,z } {}


	double vec3::x() const
	{
		return e[0];
	}

	double vec3::y() const
	{
		return e[1];
	}

	double vec3::z() const
	{
		return e[2];
	}

	vec3 vec3::operator-() const
	{
		/*
		* this will works the same
		* but this looks so java
		* and use more call stack
		* return vec3(-this.x(), -this.y(), -this.z());
		*/
		return vec3(-e[0], -e[1], -e[2]);
	}


	vec3& vec3::operator+=(const vec3& v)
	{
		this->e[0] += v.e[0];
		this->e[1] += v.e[1];
		this->e[2] += v.e[2];
		return *this;
	}

	vec3& vec3::operator*=(const double t)
	{
		this->e[0] *= t;
		this->e[1] *= t;
		this->e[2] *= t;
		return *this;
	}

	vec3& vec3::operator/=(const double t)
	{
		this->e[0] /= t;
		this->e[1] /= t;
		this->e[2] /= t;
		return *this;
	}

	export double vec3::length() const
	{
		return sqrt(this->length_squared());
	}

	double vec3::length_squared() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	double vec3::operator[](int i) const
	{
		return e[i];
	}

	double& vec3::operator[](int i)
	{
		return e[i];
	}

	/*
	* will print vec3(x, y, z)
	*/
	export inline std::ostream& operator<<(std::ostream& out, const vec3& v)
	{
		return out << "vec3(" << v.e[0] << ", " << v.e[1] << ", " << v.e[2] << ")";
	}

	export inline vec3 operator+(const vec3& u, const vec3& v)
	{
		return vec3{ u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2] };
	}

	export inline vec3 operator-(const vec3& u, const vec3& v)
	{
		return vec3{ u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2] };
	}

	export inline vec3 operator*(const vec3& u, const vec3& v)
	{
		return vec3{ u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2] };
	}

	export inline vec3 operator*(const vec3& v, double t)
	{
		return vec3{ t * v.e[0], t * v.e[1], t * v.e[2] };
	}

	export inline vec3 operator*(double t, const vec3& v)
	{
		return v * t;
	}

	export inline vec3 operator/(vec3 v, double t) {
		return (1 / t) * v;
	}

	export inline double dot(const vec3& u, const vec3& v) {
		return u.e[0] * v.e[0]
			+ u.e[1] * v.e[1]
			+ u.e[2] * v.e[2];
	}

	export inline vec3 cross(const vec3& u, const vec3& v) {
		return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
			u.e[2] * v.e[0] - u.e[0] * v.e[2],
			u.e[0] * v.e[1] - u.e[1] * v.e[0]);
	}

	export inline vec3 unit_vector(vec3 v) {
		return v / v.length();
	}
};

